@REM
@REM echo off

if not defined __VCVARSALL_TARGET_ARCH call set_vcvarsall.bat

@REM
if not exist build (
    mkdir build
)

pushd build
cmake -G"NMake Makefiles" .. && cmake --build .
pushd test
ctest
popd
popd
