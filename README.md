# 1. Build
```
mkdir build
cd build
cmake ..
make install
```
# 2. Usage
Use with find:  
```
cp fixapp <path>/robots-configuration
cd <path>/robots-configuration
find ./robots-configuration/  -name *wrapper*.xml | ./fixapp
```
