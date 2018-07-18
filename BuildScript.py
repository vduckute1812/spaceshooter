import os
from subprocess import Popen


BASE_DIR = os.path.dirname(os.path.abspath(__file__))
LIB_PATH="../GameEngine"

LIST_PATH = {BASE_DIR, LIB_PATH}
                           
SUFFIX_FILE = [".h",".cpp"]
file = open("Makefile.txt", "w")
file_bat = open("batchfile.bat", "w")

def list_item(source_path):
    tmp = ""
    file_item = ""
    list_data = []
    for item in os.listdir(source_path):
        if item.endswith(SUFFIX_FILE[0]) or item.endswith(SUFFIX_FILE[1]):
            print(item)
            file_item = os.path.splitext(item)[0]
            if(file_item != os.path.splitext(tmp)[0] and item.endswith(SUFFIX_FILE[0])):
            	tmp = item
            	continue
            if(tmp.endswith(SUFFIX_FILE[1]) and file_item!= os.path.splitext(tmp)[0]):
            	file.write("\n\t"+"g++ -c "+tmp+"\n")
            	file_bat.write("g++ -c "+source_path+"/"+tmp+"\n")
                
            if(file_item != os.path.splitext(tmp)[0]):
            	file.write(file_item+".o: ")
            	list_data.append(file_item+".o")
            file.write(item+" ")

            if(item.endswith(SUFFIX_FILE[0])):
            	file.write("\n\t"+"g++ -c "+file_item+SUFFIX_FILE[1]+"\n")
            	file_bat.write("g++ -c "+source_path+"/"+file_item+SUFFIX_FILE[1]+"\n")
            tmp = item
    return list_data

list_file = []
flat_list = []

for lib_path in LIST_PATH:
   list_file.append(list_item(lib_path))

for sublist in list_file:
    for item in sublist:
        flat_list.append(item)

file.write("build: ")
for item in flat_list:
	file.write(item+" ")
	file_bat.write(item+" ")
file.write("\n\t" + "g++ ")
file_bat.write("g++ ")
for item in flat_list:
	file.write(item+" ")
	file_bat.write(item+" ")
file.write("-o output\n")
file_bat.write("-o output\n")

file.write("run: ")
file.write("\n\t"+"./output")
file_bat.write("start " + "output.exe")

file.close()
file_bat.close()
# p = Popen("batchfile.bat", cwd=r"C:\Users\duc.nguyenvan5\Documents\Visual Studio 2013\Projects\CPPDemoGameEngine\DemoGame\Demo")
# stdout, stderr = p.communicate()
