//
// Created by 87572 on 20/7/8.
//

#include "../include/DivideObj.h"


DivideObj::DivideObj() {

}

char *DivideObj::getName() {

    return nullptr;
}

DivideObj::~DivideObj() {

}

//静态化变量会提前初始化,类似于java的静态构造
int DivideObj::num = 20;