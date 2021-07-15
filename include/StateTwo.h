//
// Created by 87572 on 20/7/5.
//

#ifndef CPPNOTEONE_STATETWO_H
#define CPPNOTEONE_STATETWO_H


#include <iostream>

using namespace std;


struct TwoRoom {

    char *getAddress() {
        return address;
    }

    int getNum() {
        return num;
    }

    char address[100];
    int num;

};

namespace ClassSpace {

    class TwoPerson {

    public:
        TwoPerson();

    private:
        char name[100];

        int age = 88;


    public:
        char *getName();

        int getAge();

        void setAge(int age);
    };
}

class StructUse {

public:

    int age;
    char *name = nullptr;

    StructUse() {
        cout << "init: no params" << endl;
        name = static_cast<char *>(calloc(10, sizeof(char)));

    }

    StructUse(const StructUse &p) {

        cout << "copy: struct ref" << endl;
    }

    StructUse(const StructUse *const p) {

        cout << "copy: struct point" << endl;
    }

    ~StructUse() {

        cout << "destroy" << endl;
        /*if (name != nullptr) {
            free(nullptr);
            name = nullptr;
        }*/
    }

};

class TestRoom {

public:
    TestRoom(int address) {

    }


};


class Apple {
public:
    int color;

    Apple(int color) {

        cout << "init:---apple" << color << endl;
    }

    ~Apple(){
        cout<<"destroy:---apple---"<<endl;
    }
};

class Orange {
public:
    int color;

    Orange(int color) {

        cout << "init:---orange" << color << endl;
    }

    ~Orange(){
        cout<<"destroy:---orange---"<<endl;
    }

};


class FruitList {

public:
    Apple apple;
    Orange orange;

    FruitList(int color) : apple(color),orange(color) {
        cout << "init:---Fruit-----" << endl;
    }

    ~FruitList(){
        cout<<"destroy:---friut---"<<endl;
    }

};


class FruitPtrs{

public:
    Apple *apple= nullptr;
    Orange *orange= nullptr;

    FruitPtrs(){
        cout<<"FruitPtrs:--init----"<<endl;
    };

    ~FruitPtrs(){
        cout<<"FruitPtrs:--destroy---"<<endl;
    }

};


#endif //CPPNOTEONE_STATETWO_H
