if (-Not (Test-Path build)) {
    cmake -S . -B build
}
cmake --build build