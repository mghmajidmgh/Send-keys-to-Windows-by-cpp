# Send-keys-to-Windows-by-cpp

With whis code in c++ you can send any keys to windows OS. For example you want to click a key every 10 seconds to stop locking the screen(I totally write this code for this purpose).

If you want to have an exe file that don't need other dependencies, use this command for compilation: g++.exe --std c++17 -fdiagnostics-color=always -static-libgcc -static-libstdc++ -L. -lwinpthread -llibwinpthread  main.cpp -g -o main.exe -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive

