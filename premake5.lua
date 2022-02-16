workspace "Okra"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Okra/vendor/GLFW/include"
IncludeDir["Glad"] = "Okra/vendor/Glad/include"
IncludeDir["ImGui"] = "Okra/vendor/imgui"
IncludeDir["glm"] = "Okra/vendor/glm"

group "Dependencies"
	include "Okra/vendor/GLFW"
	include "Okra/vendor/Glad"
	include "Okra/vendor/imgui"
group ""

project "Okra"
	location "Okra"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "okrapch.h"
	pchsource "Okra/src/okrapch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{ 
			"OKRA_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "OKRA_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "OKRA_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "OKRA_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Okra/vendor/spdlog/include",
		"Okra/src",
		"Okra/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Okra"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "OKRA_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "OKRA_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "OKRA_DIST"
		runtime "Release"
		optimize "On"
