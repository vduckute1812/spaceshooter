from Setting import NAME_LIST, SUFFIX_FILE, IS_PLAN, SOURCES_PATH
import os

ITEM_COUNT = {
    "Fonts"   :   0,
    "Images"  :   0,
    "Sounds"  :   0,
    "UIButton":   0,
}

def list_item(source_path):
    for type_data in os.listdir(source_path):
        if type_data in NAME_LIST:
            type_data_path = os.path.join(source_path, type_data)
            for type_data_item in os.listdir(type_data_path):
                if type_data_item.endswith(SUFFIX_FILE[type_data]):
                    path_item = os.path.join(type_data_path, type_data_item)
                    yield path_item
                elif type_data_item in IS_PLAN:
                    plan_path = os.path.join(type_data_path, type_data_item)
                    for plan_item in os.listdir(plan_path):
                        if plan_item.endswith(SUFFIX_FILE[type_data_item]):
                            path_plan_item = os.path.join(plan_path, plan_item)
                            yield path_plan_item

for idx, path_img in enumerate(list_item(SOURCES_PATH)):
    print(path_img)
    NAME = os.path.split(os.path.dirname(path_img))[1]
    print(NAME)
    if NAME in IS_PLAN:
        ITEM_COUNT["Images"]+=1
    else:
        ITEM_COUNT[NAME] += 1

print(ITEM_COUNT)


ID_COUNT = {
    "Fonts"   :   0,
    "Images"  :   0,
    "Sounds"  :   0,
    "UIButton":   0,
}


file = open("Data.txt", "w")
file.seek(0)

for type_data in ITEM_COUNT:
    file.write("#"+type_data+" "+ str(ITEM_COUNT[type_data])+"\n")
    for idx, path_img in enumerate(list_item(SOURCES_PATH)):
        type_name = os.path.split(os.path.dirname(path_img))[1]
        if type_name == type_data:
            ID_COUNT[type_name] += 1
            file.write("- ID: "+str(ID_COUNT[type_name])+"\n")
            file.write("- PATH:")
            file.write(path_img+"\n")
        elif type_name in IS_PLAN and type_data == "Images":
            ID_COUNT[type_data] += 1
            file.write("- ID: "+str(ID_COUNT[type_data])+"\n")
            file.write("- PATH:")
            file.write(path_img+"\n")            
file.close()
