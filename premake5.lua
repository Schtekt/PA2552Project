-- courtesy of "https://github.com/premake/premake-core/issues/935#issuecomment-343491487"
function os.winSdkVersion()
    local reg_arch = iif( os.is64bit(), "\\Wow6432Node\\", "\\" )
    local sdk_version = os.getWindowsRegistry( "HKLM:SOFTWARE" .. reg_arch .."Microsoft\\Microsoft SDKs\\Windows\\v10.0\\ProductVersion" )
    if sdk_version ~= nil then return sdk_version end
end


solution "PA2252Project"
    platforms {"x86", "x64"}
    configurations {"Debug","Release"}
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"

    filter {"system:windows", "action:vs*"}
        systemversion(os.winSdkVersion() .. ".0")

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
        vpaths {
            ["Headers/"] = { "lib/**.h", "lib/**.hpp" },
            ["Sources/"] = {"lib/**.c", "lib/**.cpp"}
        }
        staticruntime "On"

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