workspace "PA2252Project"
    configurations {"Debug","Release"}
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"

    cppdialect "C++17"
    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"

    project "GoogleTest"
        kind "StaticLib"
        files { "googletest/googletest/src/gtest-all.cc" }
        includedirs { "googletest/googletest/include", "googletest/googletest" }

    project "Project"
        kind "staticLib"
        files {"lib/**.c", "lib/**.h", "lib/**.cpp", "lib/**.hpp"}
        staticruntime "On"

    project "ProjectTestRuntime"
        kind "ConsoleApp"
        files {"runtimeTest/**.c", "runtimeTest/**.h", "runtimeTest/**.cpp", "runtimeTest/**.hpp"}
        links {"Project", "GoogleTest"}
        includedirs{"lib/pub", "googletest/googletest/include"}

    project "ProjectRuntime"
        kind "ConsoleApp"
        files {"runtime/**.c", "runtime/**.h", "runtime/**.cpp", "runtime/**.hpp"}
        links {"Project"}
        includedirs{"lib/pub"}