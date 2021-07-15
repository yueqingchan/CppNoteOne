//
// Created by 87572 on 20/7/12.
//

#include "../include/STLThree.h"
#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

class ThreePerson {
public:
    int age;

    ThreePerson() {

    }

    ThreePerson(int age) {
        this->age = age;
    }

    bool operator==(const ThreePerson &person) const {
        return person.age == this->age;
    }

    ~ThreePerson() {
        cout << "destroy------------" << endl;
    }

};

bool comparePerson(const ThreePerson &p1, const ThreePerson &p2)  {

    return p2.age > p1.age;
}

class Compare {

public:
    bool operator()(const ThreePerson &p1, const ThreePerson &p2) {

        return p2.age > p1.age;

    }

};


void printList(const list <ThreePerson> &list1) {

    for (auto iterator1 = list1.begin(); iterator1 != list1.end(); ++iterator1) {
        cout << (iterator1->age) << endl;
    }

}

void useThreeState() {

    //获取三种迭代器的方法
    vector <ThreePerson> vector1 = vector<ThreePerson>();

    vector1.push_back(ThreePerson(5));
    vector<ThreePerson>::reverse_iterator iterator = vector1.rbegin();
    vector<ThreePerson>::iterator iterator2 = vector1.begin();
    vector<ThreePerson>::const_iterator iterator3 = vector1.begin();
    vector<ThreePerson>::iterator iterator4 = vector1.end();
    cout << iterator->age << endl;


    ThreePerson threePerson1 = ThreePerson(1);
    ThreePerson threePerson2 = ThreePerson(2);
    ThreePerson threePerson3 = ThreePerson(3);
    ThreePerson threePerson4 = ThreePerson(5);
    ThreePerson threePerson5 = ThreePerson(4);

    list <ThreePerson> list1;
    list1.push_back(threePerson1);
    list1.push_back(threePerson2);
    list1.push_back(threePerson3);
    list1.push_back(threePerson4);
    list1.push_front(threePerson5);
    printList(list1);
    cout << "-------------------------------------" << endl;
    list1.sort(Compare());
    printList(list1);


    /*cout << "-----------------remove--------------------" << endl;
    list1.remove(ThreePerson(1));
    printList(list1);

    cout << "-------------------eraser------------------" << endl;

    list1.erase(list1.begin()++);
    printList(list1);*/




}
/**
 * K1:---------------------list的相关API------------------------------
 *
 * list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
       list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身。
       list(n,elem);//构造函数将n个elem拷贝给本身。
       list(const list &lst);//拷贝构造函数。
       3.6.4.2 list数据元素插入和删除操作
       push_back(elem);//在容器尾部加入一个元素
       pop_back();//删除容器中最后一个元素
       push_front(elem);//在容器开头插入一个元素
       pop_front();//从容器开头移除第一个元素
       insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
       insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
       insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
       clear();//移除容器的所有数据
       erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
       erase(pos);//删除pos位置的数据，返回下一个数据的位置。
       remove(elem);//删除容器中所有与elem值匹配的元素。


       3.6.4.3 list大小操作
       size();//返回容器中元素的个数
       empty();//判断容器是否为空
       resize(num);//重新指定容器的长度为num，
       若容器变长，则以默认值填充新位置。
       如果容器变短，则末尾超出容器长度的元素被删除。
       resize(num, elem);//重新指定容器的长度为num，
       若容器变长，则以elem值填充新位置。
       如果容器变短，则末尾超出容器长度的元素被删除。

       3.6.4.4 list赋值操作
       assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
       assign(n, elem);//将n个elem拷贝赋值给本身。
       list& operator=(const list &lst);//重载等号操作符
       swap(lst);//将lst与本身的元素互换。
       3.6.4.5 list数据的存取
       front();//返回第一个元素。
       back();//返回最后一个元素。
       3.6.4.6 list反转排序
       reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
       sort(); //list排序
 *
 *
 */


/**
 * K2:----------------list的细节----------------------------
 * 1.sort排序,需要传入二元比较函数.或者仿函数.
 *   注意点:JAVA中的compare返回的是int,这里返回的是bool.
 *
 * 2.remove 自定义结构体,需要重写operator== 的二元函数.
 *
 */

/**
 * K3:-------------------set的使用--------------------------
 *
 * 1.自定义类型的class,需要传入仿函数的比较器.bool operator()(const T1&,consrT2&),public修饰.
 *    或者重写类内部的< 重载符.
 *
 * 2.移除自定义的类,需要重写operator==的二元函数.
 *
 *
 *
 *      set构造函数
        set<T> st;//set默认构造函数：
        mulitset<T> mst; //multiset默认构造函数:
        set(const set &st);//拷贝构造函数
        3.7.2.2 set赋值操作
        set& operator=(const set &st);//重载等号操作符
        swap(st);//交换两个集合容器
        3.7.2.3 set大小操作
        size();//返回容器中元素的数目
        empty();//判断容器是否为空

        3.7.2.4 set插入和删除操作
        insert(elem);//在容器中插入元素。
        clear();//清除所有元素
        erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
        erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
        erase(elem);//删除容器中值为elem的元素。
 *
 *
 */


/**
 *
 * K4:----------------迭代器补充--------------------
 *      vector<int>::iterator pStart = v.begin(); //vector 容器提供了 begin()方法 返回指向第一个元素的迭代器
	    vector<int>::iterator pEnd = v.end(); //vector 容器提供了 end()方法 返回指向最后一个元素下一个位置的迭代器
 *      并不是最后一个,而是最后一个的下一个.......
 *
 *
 */


/**
 *
 * K5:-------------  ==  <  仿函数,谓词的总结:------------
 *  **都要注意加const修饰**
 *  bool operator==(const T &t)const  是用于remove的时候调用.
 *  bool operator<(const T &t)const  是用于比较排序的时候调用.
 *  仿函数  也是用于比较排序的时候调用.  bool operator()(const T&t1,const T &t2)const ;
 *
 *  这个无法加const
 *  或者写一个全局函数. bool compare(const T&t1,const T &t2)
 *
 *  1、函数对象通常不定义构造函数和析构函数，所以在构造和析构时不会发生任何问题，避免了函数调用的运行时问题。
 *  2、函数对象超出普通函数的概念，函数对象可以有自己的状态
 *  3、函数对象可内联编译，性能好。用函数指针几乎不可能
 *  4、模版函数对象使函数对象具有通用性，这也是它的优势之一
 *
 *
 */
class SetPerson {

public:
    int age;

    SetPerson() {
        cout << "init " << endl;
    }

    SetPerson(int age) {
        this->age = age;
//        cout << "init " << "age " << age << endl;
    }

    ~SetPerson() {
//        cout << "destroy" << endl;
    }

};

class SetRoom {

public:
    int age;

    SetRoom() {
        cout << "init " << endl;
    }

    SetRoom(int age) {
        this->age = age;
        cout << "init " << "age " << age << endl;
    }

    ~SetRoom() {
        cout << "destroy" << endl;
    }

    bool operator<(const SetRoom &room) const {

        return true;
    }

};

class SetCompare {
public:
    bool operator()(const SetPerson &p1, const SetPerson &p2) const {
        return p1.age > p2.age;
    }

};

void printSet(const set <SetPerson, SetCompare> &set1) {

    cout << "---------------------------------------------" << endl;

    auto it2 = set1.begin();

    cout << it2->age << endl;


    for (auto it = set1.begin(); it != set1.end(); ++it) {
        cout << "SetPerson:------age-------" << it->age << endl;
    }

}

void printSetPerson(const multiset <SetPerson, SetCompare> &set1) {

    cout << "---------------------------------------------" << endl;

    auto it2 = set1.begin();

    auto it3 = set1.end();


    cout << it2->age << "|||||||||||" << (++it3)->age << endl;


    for (auto it = set1.begin(); it != set1.end(); ++it) {
        cout << "SetPerson:------age-------" << it->age << endl;
    }

}

void printSetRoom(const set <SetRoom> &set1) {

    cout << "---------------------------------------------" << endl;

    auto it2 = set1.begin();

    cout << it2->age << endl;


    for (auto it = set1.begin(); it != set1.end(); ++it) {
        cout << "SetRoom:------age-------" << it->age << endl;
    }

}

void useThreeState1() {


    SetPerson setPerson1 = 1;
    SetPerson setPerson3 = 3;
    SetPerson setPerson2 = 2;

    /* set <SetPerson, SetCompare> set1;
     pair<set<SetPerson, SetCompare>::iterator, bool> result1 = set1.insert(setPerson1);

     set1.insert(setPerson3);
     printSet(set1);*/


    multiset <SetPerson, SetCompare> set3;

//    set<SetPerson>::iterator res3 =

    set3.insert(setPerson1);
    set3.insert(setPerson3);
//    set3.insert(setPerson2);

    printSetPerson(set3);


    auto it1 = set3.begin();
    auto it2 = set3.end();


    printf("%p\n", it1);
    printf("%p\n", ++it1);

    printf("%p\n", ++it2);


    /* set <SetRoom> set2;

     SetRoom setRoom1 = 2;
     SetRoom setRoom2 = 1;

     set2.insert(setRoom1);
     set2.insert(setRoom2);*/


    pair<string, int> pair1 = make_pair("123", 1);
    pair<string, int> pair2 = pair<string, int>("123", 1);


}

class MapPerson {
public:
    int age;

    bool operator<(const MapPerson &p) const {
        return this->age < p.age;
    }
};


void printMap(map <MapPerson, string> map1) {


    for (auto it = map1.begin(); it != map1.end(); ++it) {

        cout << "map's  age:  " << it->second << endl;

    }
}

void useThreeState2() {

    map <MapPerson, string> map1;
    auto var1 = map1.insert(make_pair(MapPerson(), "July"));
    auto var2 = map1.insert(make_pair(MapPerson(), "Lucy"));
    map1.insert(make_pair(MapPerson(), "LiLei"));
    printMap(map1);

    cout<<var1.second<<endl;
    cout<<var2.second<<endl;

}
