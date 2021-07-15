//
// Created by 87572 on 20/7/8.
//

#ifndef CPPNOTEONE_DIVIDEOBJ_H
#define CPPNOTEONE_DIVIDEOBJ_H

using namespace std;


class DivideObj {
private:
    char *name;
    int age;
    static int  num;
public:
    DivideObj();

    char *getName();

    ~DivideObj();
};


#endif //CPPNOTEONE_DIVIDEOBJ_H
