cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
if make -j4
then
cd ..
fi
