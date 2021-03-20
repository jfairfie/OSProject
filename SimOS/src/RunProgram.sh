#!/bin/sh
g++ -std=c++0x SimOS.cpp Driver.cpp MemoryManagement/Disk.cpp MemoryManagement/PCB.cpp SupportPrograms.cpp
./a.out
rm ./a.out
