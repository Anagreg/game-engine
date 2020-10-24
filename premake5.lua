-- Premake 5.0 alpha 15
workspace "Tamago"
   architecture "x64"

   configurations{
      "Debug",
      "Release",
      "Dist"
   }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Tamago"
   location "Tamago"
   kind "SharedLib"
   language "C++"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   files{
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
   }

   includedirs{
      "%{prj.name}/vendor/spdlog/include"
   }

   filter "system:windows"
      cppdialect "C++17"
      staticruntime "On"
      systemversion "latest"

      defines{
         "TG_PLATFORM_WINDOWS",
         "TG_BUILD_DLL"
      }

      postbuildcommands{
         ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
      }

   filter "configurations:Debug"
      defines "TG_DEBUG"
      symbols "On"

   filter "configurations:Release"
      defines "TG_RELEASE"
      optimize "On"

   filter "configurations:Dist"
      defines "TG_DIST"
      optimize "On"

project "Sandbox"
   location "Sandbox"
   kind "ConsoleApp"
   language "C++"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   files{
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
   }

   includedirs{
      "Tamago/vendor/spdlog/include",
      "Tamago/src"
   }

   links{
      "Tamago"
   }

   filter "system:windows"
      cppdialect "C++17"
      staticruntime "On"
      systemversion "latest"

      defines{
         "TG_PLATFORM_WINDOWS"
      }

   filter "configurations:Debug"
      defines "TG_DEBUG"
      symbols "On"

   filter "configurations:Release"
      defines "TG_RELEASE"
      optimize "On"

   filter "configurations:Dist"
      defines "TG_DIST"
      optimize "On"
