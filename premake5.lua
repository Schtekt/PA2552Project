solution "PA2252Project"
    platforms {"x86", "x64"}
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

    filter "system:Windows"
        systemversion "latest"
        
    project "GoogleTest"
        kind "StaticLib"
        files { "googletest/googletest/src/gtest-all.cc" }
        includedirs { "googletest/googletest/include", "googletest/googletest" }

    project "Project"
        kind "staticLib"
        files {"lib/**.c", "lib/**.h", "lib/**.cpp", "lib/**.hpp"}
        vpaths {
            ["Headers/"] = { "lib/**.h", "lib/**.hpp" },
            ["Sources/"] = {"lib/**.c", "lib/**.cpp"}
        }

    project "ProjectTestRuntime"
        kind "ConsoleApp"
        files {"runtimeTest/**.c", "runtimeTest/**.h", "runtimeTest/**.cpp", "runtimeTest/**.hpp"}
        vpaths {
            ["Headers/"] = { "runtimeTest/**.h", "runtimeTest/**.hpp" },
            ["Sources/"] = {"runtimeTest/**.c", "runtimeTest/**.cpp"}
        }
        links {"Project", "GoogleTest"}
        includedirs{"lib", "googletest/googletest/include"}

    project "ProjectRuntime"
        kind "ConsoleApp"
        files {"runtime/**.c", "runtime/**.h", "runtime/**.cpp", "runtime/**.hpp"}
        vpaths {
            ["Headers/"] = { "runtime/**.h", "runtime/**.hpp" },
            ["Sources/"] = {"runtime/**.c", "runtime/**.cpp"}
        }
        links {"Project"}
        includedirs{"lib"}