

# take in spritesheet.json and map.json
# autocode instances (note reuse of static tiles, specialisation of unique tiles)
# create tilemap array

# TODO: only objects seem to have custom properties, how to indicate floor/wall on tile layer? Naming?

# onInteraction function which is named in custom property of map.json, and passed to constructor of special tile
# separate object layer including pickups, mobs, etc

import json

# Load map data
with open("res/test.json") as f:
    j = json.load(f)
    mapdata = j["layers"]

# Load tileset data
with open("res/xipe.json") as f:
    j = json.load(f)
    image_file = j["image"]  # for calling w4 png2src
    tileset_w = j["columns"]
    image_h = j["imageheight"]
    image_w = j["imagewidth"]
    
    tileset = {}  # dict of tileID -> name
    for tilepair in j["tiles"]:
        tileset[tilepair["id"]] = tilepair["type"]
    
    print(j)

# get tiles as list of int IDs TODO pack into uint8 with bit for wall?
tiledata = mapdata[0]["data"]

# tile array width
map_w = mapdata[0]["width"]

objdata = mapdata[1]["objects"]
# print(objdata)
