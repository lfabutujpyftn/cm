cd ..
cd ..
rmdir /s /q build
mkdir build
cd build
cmake ./../cm/3.2_Spline -G "Visual Studio 12 2013 Win64"
pause