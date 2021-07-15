//
// Created by 87572 on 20/7/5.
//

#ifndef CPPNOTEONE_STATEONE_H
#define CPPNOTEONE_STATEONE_H

#include <iostream>


struct Person{
    int age;
};

void useNameSapce();
void useConst();
void  useReference();

namespace nameC{

    // int d=100;  不可以和其他nameC下的冲突;但是不同名的nameSpace下的变量可以同名.
    void innerNameSpaceFun();
    void innerNameSpaceFun2();
}

class APerson{

    int age;

};

#endif //CPPNOTEONE_STATEONE_H
