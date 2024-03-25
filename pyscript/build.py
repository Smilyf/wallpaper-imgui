import os
import sys

cppPath=[]
srcPath=[]
compilePath=[]
includePath=[]
libPath=[]
libName=[]
buildPath=[]
def find_cpp_files(path,extension):
    cpp_files = []
    for root, _, files in os.walk(path):
        for file in files:
            if file.endswith(extension):
                cpp_files.append(os.path.join(root, file))

    return cpp_files

cppPath.append('C:\\Users\\yam_l\\wallpaper-imgui\\wallpaper-imgui\\src\\linux')
compilePath.append('D:\\sf\\x86_64-w64-mingw32\\bin\\')


includePath.append('C:\\Users\\yam_l\\wallpaper-imgui\\wallpaper-imgui\\include')
includePath.append('D:\\sf\\VulkanSDK\\1.3.275.0\\Include')
includePath.append('D:\\sf\\VulkanSDK\\1.3.275.0\\Include\\SDL2')


buildPath.append("C:\\Users\\yam_l\\wallpaper-imgui\\wallpaper-imgui\\build\\")
libPath.append('D:\\sf\\VulkanSDK\\1.3.275.0\\Lib')

libName.append('SDL2')
libName.append('SDL2main')
libName.append('vulkan-1')
# libName.append('glfw3')
for path in cppPath:
    srcPath.extend(find_cpp_files(path,'.cpp'))
    
def tostr(arges,des):
    if len(arges) > 0:
        return des+des.join(map(str, arges))
    else:
        return ''
        
cpp_file=''
cpp_file+=compilePath[0]
cpp_file+='g++ '
cpp_file+=tostr(srcPath,' ')
cpp_file+=tostr(includePath,' -I') #include
cpp_file+=tostr(libPath,' -L') #Lib
cpp_file+=tostr(libName,' -l') #LibName
cpp_file += ' -o '
cpp_file+=buildPath[0]+'out'
# cpp_file += ' -static -std=c++20 -fmodules-ts'
cpp_file += ' -static -std=c++20 '
print(cpp_file)
os.system(cpp_file)
os.system(buildPath[0]+'out')
