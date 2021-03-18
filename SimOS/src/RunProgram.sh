#!/bin/sh
g++ -std=c++0x SimOS.cpp Driver.cpp MemoryManagement/Disk.cpp PCB.cpp
./a.out
rm ./a.out
