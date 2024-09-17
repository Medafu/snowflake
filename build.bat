pushd build
cl gdi32.lib msvcrt.lib raylib.lib user32.lib shell32.lib winmm.lib ../main.cpp /EHsc -Zi -Ic:\c_libs\raylib\include /link /libpath:c:\c_libs\raylib\lib /NODEFAULTLIB:libcmt 
popd
