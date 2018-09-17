#include "hello.h"
using namespace demo;

int main(){
    
    test_base();
    test_pointer();
    test_struct();
    test_object();
    test_file();
    test_exception();
    test_dynamic_memory();

    // keep terminal not exit
    //cin>> a; 
    return 0;
}

void  demo::test_base(){
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
    };
    Color color=Blue;
}

void demo::test_pointer(){
    int a;
    cout << "address of a:" << &a << " value of a:" << a << endl;

    int& b=a;
    cout << "address of b:" << &b << " value of b:" << b << endl;
}

void demo::test_struct(){
    Person p1;
    p1.id=0;
    p1.name="ly";
    
    Person* pp=&p1;
    cout << "person name:" << pp->name << endl;
}

void demo::test_object(){

    //静态成员变量，函数
    cout << "count: " << OPerson::getCount();

    //继承
    Student s;
    s.id = 2;
    s.name = "dm";
    s.say("hi i am new here");

    //操作符重载
    Student p;
    p.id=3;
    p.name="dwife";

    Student couple=s+p;
    couple.say("welcome to our house");

    //多态
    Teacher t(4,"zls");
    OPerson *pOP=&t;
    pOP->say("hi boys");
    cout << "name:" + pOP->getName() << endl;
}

void demo::test_file(){
    fstream fs;
    string content = "hi ,i am ly";
    fs.open("test.txt", ios::app | ios::out); //如果有ios::in在，不会自动创建文件(ios::app也存在的情况下，不存在也会自动创建)
    fs << content << endl;
    // fs >> content ;
    // cout << "read from fs: " << content << endl;
    fs.close();
}

void demo::test_exception(){
    try{
        string err="this is a test exception";
        throw err;
    }catch(string msg){
        cerr << msg << endl;
    }
}

void demo::test_dynamic_memory(){
    int *c= NULL;
    c = new int;
    *c = 1;
    delete c;

    string * str=new string;
    *str="hi str";
    delete str;

    char * pchar=new char[20];
    pchar[2]='a';
    delete[] pchar;
}