cd ..
cd ..
rmdir /s /q build
mkdir build
cd build
cmake ./../cm/2.1_EQ -G "Visual Studio 12 2013 Win64"
pause