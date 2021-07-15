cmake_minimum_required(VERSION 3.13)
project(CppNoteOne)

set(CMAKE_CXX_STANDARD 11)

add_executable(CppNoteOne main.cpp stateOne/StateOne.cpp include/StateOne.h include/StateTwo.h stateOne/StateTwo.cpp stateOne/externC.c include/externVar.h stateOne/externVar.cpp stateOne/StateThree.cpp include/StateThree.h stateOne/DivideObj.cpp include/DivideObj.h stateOne/StateFive.cpp include/StateFive.h stateOne/StateSix.cpp include/StateSix.h stateOne/StateSeven.cpp include/StateSeven.h stateOne/StateEight.cpp include/StateEight.h stateOne/STLOne.cpp include/STLOne.h stateOne/STLTwo.cpp include/STLTwo.h stateOne/STLThree.cpp include/STLThree.h)