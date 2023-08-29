# CLP Conan Test

mkdir build

conan install . --profile ../conanprofile.txt --build=missing --output-folder=build

cd build

cmake .. --preset conan-release

make

