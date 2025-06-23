workspace "Zengine"
	architecture "x64"

	configurations
	{ 
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Zengine/vendor/GLFW/include"

include "Zengine/vendor/glfw"

project "Zengine"
	location "Zengine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "znpch.h"
	pchsource "Zengine/src/znpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
	}

	links
	{
		"GLFW",
		"opengl32.lib",
	}

	filter "system:windows"
		buildoptions "/utf-8"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ZN_PLATFORM_WINDOWS",
			"ZN_BUILD_DLL",  
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}

	filter "configurations:Debug"
		defines "ZN_DEBUG" 
		symbols "On"
	filter "configurations:Release"
		defines "ZN_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "ZN_DIST"
		optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Zengine/vendor/spdlog/include",
		"Zengine/src"
	}

	links
	{
		"Zengine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions "/utf-8"

		defines
		{
			"ZN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ZN_DEBUG" 
		symbols "On"
	filter "configurations:Release"
		defines "ZN_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "ZN_DIST"
		optimize "On"
