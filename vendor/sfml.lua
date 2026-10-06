local SFML = "SFML/"
local SRC  = SFML .. "src/SFML/"

local function common(name)
    project("sfml-" .. name)
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    warnings "Off"
    includedirs {
        SFML .. "include", SFML .. "src",
        SFML .. "extlibs/headers",
        SFML .. "extlibs/headers/vulkan",
        SFML .. "extlibs/headers/glad/include",
        SFML .. "extlibs/headers/stb_image",
        "freetype/include",
    }
    filter "system:windows"
        defines { "UNICODE", "_UNICODE", "STRICT", "NOMINMAX", "WIN32_LEAN_AND_MEAN" }
    filter { "system:windows", "toolset:gcc" }
        includedirs { SFML .. "extlibs/headers/mingw" }
    filter {}
end

common("system")
    files { SRC .. "System/*.cpp" }
    filter "system:windows"      files { SRC .. "System/Win32/*.cpp" }
    filter "system:not windows"  files { SRC .. "System/Unix/*.cpp" }
    filter {}

common("window")
    files { SRC .. "Window/*.cpp" }
    removefiles { SRC .. "Window/EGLCheck.cpp", SRC .. "Window/EglContext.cpp" }
    filter "system:windows"  files { SRC .. "Window/Win32/*.cpp" }
    filter "system:linux"    files { SRC .. "Window/Unix/*.cpp" }
    filter "system:macosx"   files { SRC .. "Window/macOS/*.cpp", SRC .. "Window/macOS/*.mm", SRC .. "Window/macOS/*.m" }
    filter {}

common("graphics")
    files { SRC .. "Graphics/*.cpp" }
