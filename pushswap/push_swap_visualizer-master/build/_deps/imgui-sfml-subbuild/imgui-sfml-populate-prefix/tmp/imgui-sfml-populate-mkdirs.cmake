# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/sholz/test/42IC_Ring02_Push_swap/push_swap/push_swap_visualizer-master/build/_deps/imgui-sfml-src"
  "/home/sholz/test/42IC_Ring02_Push_swap/push_swap/push_swap_visualizer-master/build/_deps/imgui-sfml-build"
  "/home/sholz/test/42IC_Ring02_Push_swap/push_swap/push_swap_visualizer-master/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix"
  "/home/sholz/test/42IC_Ring02_Push_swap/push_swap/push_swap_visualizer-master/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/tmp"
  "/home/sholz/test/42IC_Ring02_Push_swap/push_swap/push_swap_visualizer-master/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src/imgui-sfml-populate-stamp"
  "/home/sholz/test/42IC_Ring02_Push_swap/push_swap/push_swap_visualizer-master/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src"
  "/home/sholz/test/42IC_Ring02_Push_swap/push_swap/push_swap_visualizer-master/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src/imgui-sfml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/sholz/test/42IC_Ring02_Push_swap/push_swap/push_swap_visualizer-master/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src/imgui-sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/sholz/test/42IC_Ring02_Push_swap/push_swap/push_swap_visualizer-master/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src/imgui-sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
