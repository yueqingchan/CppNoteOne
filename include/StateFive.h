//
// Created by 87572 on 20/7/8.
//

#ifndef CPPNOTEONE_STATEFIVE_H
#define CPPNOTEONE_STATEFIVE_H

using namespace std;

#include <iostream>

class StateFive {


public:
    StateFive();

    StateFive(const StateFive &stateFive);

    ~StateFive();

    StateFive getInstanceCopy();

    StateFive &getInstanceRef();

};


void useStateFiveClass();

void useExtends();

void getStructSize();

void  useStaticFun();

void  useSonFun();

void useMultiExtends();

#endif //CPPNOTEONE_STATEFIVE_H
