cmake . -B cmake-build-debug -DPORT=Linux -DCMAKE_BUILD_TYPE=Debug
cmake --build cmake-build-debug/
./cmake-build-debug/vendor/Google_Tests_run
