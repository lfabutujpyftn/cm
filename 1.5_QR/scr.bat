cd ..
cd ..
rmdir /s /q build
mkdir build
cd build
cmake ./../cm/1.5_QR -G "Visual Studio 12 2013 Win64"
pause