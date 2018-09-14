#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int count;
extern void write_extern(void);

void test_base();
void test_pointer();
void test_struct();

struct Person{
    int id;
    string name;
};

int main(){
    
    test_base();
    test_pointer();
    test_struct();

    // keep terminal not exit
    //cin>> a; 
    return 0;
}

void test_base(){
    //typedef 
    typedef int int_name;
    int_name a = 0;

    //extern :修饰符通常用于当有两个或多个文件共享相同的全局变量或函数的时候
    count=5;
    write_extern();

    //u l :U 表示无符号整数（unsigned），L 表示长整数（long）。后缀可以是大写，也可以是小写，U 和 L 的顺序任意
    unsigned long c=23ul;

    //const
    #define LENGTH 10 
    const int WIDTH = 10;

    //auto
    auto f=3.14; //double 
    auto s("hello"); //const char* 
    auto z = new auto(9); // int*

    //cstring string
    char c_str[12]="hello,c str";
    string str="hello, c++ str";
    cout<< c_str << endl << str << endl;

    //enum
    enum Color{
        Red,
        Green,
        Blue
    } color;
    Color c=Blue;
    color=Red;
}

void test_pointer(){
    int a;
    cout << "address of a:" << &a << " value of a:" << a << endl;

    int& b=a;
    cout << "address of b:" << &b << " value of b:" << b << endl;
}

void test_struct(){
    Person p1;
    p1.id=0;
    p1.name="ly";
    
    Person* pp=&p1;
    cout << "person name:" << pp->name << endl;
}