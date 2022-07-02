
# Autocode tileset and map data from Tiled export files

import json
import os

# Size of each screen in tiles
SCREEN_HEIGHT = 10
SCREEN_WIDTH = 10

# Size of each tile:
TILE_SIZE = 16


def load_tileset(path: str):
    with open(path) as f:
        j = json.load(f)

    image_file = j["image"]  # for calling w4 png2src
    n_columns = j["columns"]
    image_w = j["imagewidth"]
    
    tileset = {}
    for tiledata in j["tiles"]:
        # Get id
        i = tiledata["id"]
        if i > 255:
            raise ValueException("Too many tiles, only <= 255 supported")
    
        # Get tile "type"
        ttype = None
        if "type" in tiledata:
            ttype = tiledata["type"]
        tileset[i] = {"type": ttype}

        # Convert properties from {name: N, value: V} to {N: V}
        for prop in tiledata["properties"]:
            name = prop["name"]
            value = prop["value"]
            tileset[i][name] = value
    return tileset, n_columns, image_file, image_w


def load_map(path: str):
    with open(path) as f:
        j = json.load(f)
        mapdata = j["layers"]
        first_gid = j["tilesets"][0]["firstgid"]
        print(f"{first_gid=}")

    # Extract objects:
    objs = []
    for obj in mapdata[1]["objects"]:
        d = {}
        d['x'] = int(obj['x'] / TILE_SIZE)
        d['y'] = int(obj['y'] / TILE_SIZE) - 1   # Not sure why Tiled is off by one
        d['name'] = obj['name'].strip()
        d['sprite'] = obj['gid'] - first_gid

        # Convert properties from {name: N, value: V} to {N: V}
        for prop in obj["properties"]:
            d[prop["name"]] = prop["value"]
        objs.append(d)


    # NOTE: Tiled maps use global id relative to firstgid
    #       but Tiled tilesets use local id relative to 0
    #       to covert, the doc says to subtract the firstgid 
    tile_ids = mapdata[0]["data"]
    tile_ids = [i - first_gid for i in tile_ids]

    # number of tiles in map across
    map_w = mapdata[0]["width"]
    map_h = mapdata[0]["height"]
    return tile_ids, objs, map_w, map_h


if __name__ == "__main__":
    # Load tileset
    tileset_path = "res/tileset.json"
    tileset, n_columns, image_file, image_w = load_tileset(tileset_path)
    
    map_path = "res/map.json"
    map_tiles, objs, map_w, map_h = load_map(map_path)

    # Write tile type definitions header
    tiledefs_path = "src/sprites.defs.auto.hpp"
    with open(tiledefs_path, "w") as f:
        f.write(f"// Auto-generated from {tileset_path}\n");
        f.write("#pragma once\n\n")
        f.write("#include <stdint.h>\n\n")
        f.write("namespace sprites {\n\n")
        for tileid in tileset:
            t = tileset[tileid]['type']
            if t:
                f.write(f"uint8_t const {t} = {tileid};\n")
        f.write("\n} // namespace sprites\n")
    print(f"wrote {tiledefs_path}")

    # Write spritesheet header
    spritesheet_path = "src/sprites.impl.auto.hpp"
    with open(spritesheet_path, 'w') as f:
        f.write(f"// Autogenerated from {tileset_path}\n")
        f.write(f"#define SPRITES_Columns {n_columns}\n")
    os.system(f"w4 png2src res/{image_file} --c >> {spritesheet_path}")
    os.system(f"sed -i 's/sprites/SPRITES_/g' {spritesheet_path}")
    print(f"wrote {spritesheet_path}")

    # Give objects names (in form: class_x_y)
    for obj in objs:
        # if it has been given a name, use that, else generate a name:
        instance_name = obj['name'].strip()
        instance_name = instance_name.replace(" ", "");
        if len(instance_name) == 0:
            instance_name = f"{obj['class'].lower()}_{obj['x']}_{obj['y']}"
        obj['name'] = instance_name

    # Write map data header
    map_impl_header = "src/map.impl.auto.hpp"
    with open(map_impl_header, "w") as f:
        f.write("\n#pragma once\n\n")
        f.write(f"// Auto-generated from {map_path}\n\n")
        f.write("#include <stdint.h>\n")
        f.write('#include "map.objects.hpp"\n\n')
        f.write("namespace map {\n")
        f.write(f"uint8_t const MAP_WIDTH = {map_w};\n")
        f.write(f"uint8_t const MAP_HEIGHT = {map_h};\n")
        f.write(f"uint8_t const SCREEN_WIDTH = {SCREEN_WIDTH};\n")
        f.write(f"uint8_t const SCREEN_HEIGHT = {SCREEN_HEIGHT};\n")
        f.write("\n")

        # Tile data (background layer)
        f.write("uint8_t const TILES[] = {\n")
        for i, tile_id in enumerate(map_tiles):
            f.write(f"{tile_id:3d}, ")
            if (i+1) % map_w == 0:
                f.write("\n")
        f.write("};\n\n")

        # Write out objects
        f.write(f"uint8_t const NUM_OBJECTS = {len(objs)};\n\n")

        # Object declarations
        for obj in objs:
            f.write(f"extern {obj['class']} {obj['name']};\n")
        f.write("\n")

        # Object array declaration
        f.write("extern Object ** OBJECTS;\n\n")
        f.write("void initObjects();\n\n")
        f.write("} // namespace map\n\n")

        # 
    print(f"wrote {map_impl_header}")

    map_impl_source = "src/map.impl.auto.cpp"
    with open(map_impl_source, "w") as f:
        f.write(f"// Auto-generated from {map_path}\n\n")
        f.write('#include "map.impl.auto.hpp"\n\n')
        f.write('#include "map.dialogue.hpp"\n\n')
        f.write("namespace map {\n\n")
        # Object definitions:
        for obj in objs:
            args = ""
            if len(obj['constructor']) > 0:
                args = ", "+obj['constructor']  # append additional arguments
            f.write(f"{obj['class']} {obj['name']}({obj['sprite']}, \"{obj['name']}\"{args});\n")
        f.write("\n")

        # Object array
        f.write("// Run-time expanded array of objects\n")
        f.write("// Not done at compile time to save ROM\n")
        f.write("// Note: Looks like BSS is copied in full at start up, so large static arrays are wasteful of ROM\n")
        f.write("Object ** OBJECTS = nullptr;\n\n")

        # Init function to give them starting position
        f.write("void initObjects() {\n")
        f.write("    OBJECTS = new Object*[MAP_WIDTH * MAP_HEIGHT];\n\n")
        for obj in objs:
            f.write(f"    OBJECTS[{obj['x']} + MAP_WIDTH*{obj['y']}] = &{obj['name']};\n")
        f.write("}\n\n")
        f.write("} // namespace map\n\n")

    print(f"wrote {map_impl_source}")

