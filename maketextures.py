#!/usr/bin/python

"""
Reads through the svg/ directory structure, replicates it as textures/ , and converts all the svgs to pngs for use within the engine.
"""

import os

for folderName, withFolders, withFiles in os.walk("svg"):
    newFolder = "textures/%s" % folderName[4:]
    os.system("mkdir -p %s" % newFolder)

    for filename in withFiles:
        if filename[-3:] == "svg":
            oldPath = "%s/%s" % (folderName,filename)
            newPath = "%s/%s.png" % (newFolder, filename[:-4])
            os.system("convert -background None %s %s" % (oldPath, newPath))
