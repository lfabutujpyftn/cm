cd ..
cd ..
rmdir /s /q build
mkdir build
cd build
cmake ./../cm/4.1_DU -G "Visual Studio 12 2013 Win64"
pause