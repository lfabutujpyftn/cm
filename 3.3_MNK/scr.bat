cd ..
cd ..
rmdir /s /q build
mkdir build
cd build
cmake ./../cm/3.3_MNK -G "Visual Studio 12 2013 Win64"
pause