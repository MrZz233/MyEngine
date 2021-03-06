workspace "MyEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "MyEngine/vendor/GLFW/include"
include "MyEngine/vendor/GLFW"

project "MyEngine"
    location "MyEngine"
    kind "SharedLib"
    language "C++"

    targetdir("bin/"..outputdir.."/%{prj.name}")
    objdir("bin-int/"..outputdir.."/%{prj.name}")

    pchheader "Engpch.h"
    pchsource "MyEngine/src/Engpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ENG_PLATFORM_WINDOWS",
            "ENG_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/"..outputdir.."/SandBox")
        }

    filter "configurations:Debug"
        defines "ENG_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "ENG_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "ENG_DIST"
        buildoptions "/MD"
        optimize "On"

project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"
    targetdir("bin/"..outputdir.."/%{prj.name}")
    objdir("bin-int/"..outputdir.."/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "MyEngine/vendor/spdlog/include",
        "MyEngine/src"
    }

    links
    {
        "MyEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ENG_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "ENG_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "ENG_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "ENG_DIST"
        buildoptions "/MD"
        optimize "On"