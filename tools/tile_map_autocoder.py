
# take in spritesheet.json and map.json

# onInteraction function which is named in custom property of map.json, and passed to constructor of special tile
# separate object layer including pickups, mobs, etc

import json


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
        if i > 127:
            raise ValueException("Too many tiles, only <= 127 supported")
    
        # Get tile "type"
        ttype = None
        if "type" in tiledata:
            ttype = tiledata["type"]
        tileset[i] = {"type": ttype}

        # Get properties
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

    obj_data = mapdata[1]["objects"]

    # NOTE: Tiled maps use global id relative to firstgid
    #       but Tiled tilesets use local id relative to 0
    #       to covert, the doc says to subtract the firstgid 
    tile_ids = mapdata[0]["data"]
    tile_ids = [i - first_gid for i in tile_ids]

    # number of tiles in map across
    map_w = mapdata[0]["width"]
    return tile_ids, obj_data, map_w


if __name__ == "__main__":
    # Load tileset
    tileset, n_columns, image_file, image_w = load_tileset("res/tileset.json")
    
    map_tiles, obj_data, map_w = load_map("res/map.json")

    # Write tile type definitions to sprites.auto.hpp, included in sprites.hpp
    for tileid in tileset:
        t = tileset[tileid]['type']
        if t:
            print(f"uint8_t const {t} = {tileid};")
    print("")

    # Write background layer to map.auto.hpp, included in map.cpp
    print("uint8_t tiles[] = {")
    for tile_id in map_tiles:
        # Lookup passability
        passable = tileset[tile_id]["passable"]
        # pack passability and sprite into 8 bits!
        b = tile_id | (int(passable) << 7)
        print(f"{b}, ")
    print("};")

    #TODO write object layer
    #print(objdata)
