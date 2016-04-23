cd ..
cd ..
rmdir /s /q build
mkdir build
cd build
cmake ./../cm/1.1_LU -G "Visual Studio 12 2013 Win64"
pause