import glob

# SCons wiki for reference: https://github.com/SCons/scons/wiki


SOURCE_DIR = "./src"
STATIC_LINK_LIBS = ["raylib", "lua"]
INCLUDE_DIRS = ["./src/", "./include/"]
CUSTOM_DEFINES = []
EXTRA_FLAGS = ['-Werror']


def get_all_source_files():
    files = glob.glob("**/*.cpp", recursive=True)
    return files


env = Environment()
is_debug = ARGUMENTS.get('debug', 0)

if int(is_debug):
    CUSTOM_DEFINES.append("DEBUG")

env.Append(CPPFLAGS=EXTRA_FLAGS)
env.Append(CPPDEFINES=CUSTOM_DEFINES)
env.Append(CPPPATH=INCLUDE_DIRS)
env.Append(SCONS_CXX_STANDARD="c++11")
env.Program(target="build/main", source=get_all_source_files(),
            LIBS=STATIC_LINK_LIBS)
