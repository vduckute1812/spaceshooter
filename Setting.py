import os

BASE_DIR = os.path.dirname(os.path.abspath(__file__)) # Dir path of this file (setting.py)


NAME_LIST = {
    "Fonts"    : 0,
    "Images"   : 1,
    "Sounds"   : 2,
    "UIButton" : 3,
}

IS_PLAN = {
    "Blue" : 0,
    "Red"  : 1,
}

SUFFIX_FILE = {
	"Fonts"    : ".fnt",
	"Images"   : ".png",
	"Sounds"   : ".mp3",
	"UIButton" : ".png",
        "Blue"     : ".png",
        "Red"      : ".png",
}



SOURCES_PATH = "..\Resources"
