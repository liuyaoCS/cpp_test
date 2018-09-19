#ifndef HELLO_H
#define HELLO_H

#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<vector>
#include<csignal>
#include<unistd.h>
#include<pthread.h>
using namespace std;

#define DEBUG  //定义为预处理器变量
#define MIN(a,b) (a<b?a:b)
#define MKSTR(x) #x             //# 运算符会把 replacement-text 令牌转换为用引号引起来的字符串
#define CONCAT(x,y)  x##y  //## 运算符用于连接两个令牌

int count;
extern void write_extern(void);
extern "C" {
    void test_c();
}

namespace demo{

    void test_base();
    void test_pointer();
    void test_struct();
    void test_object();
    void test_file();
    void test_exception();
    void test_dynamic_memory();
    template<typename T>  void test_template(T &t);
    void test_thread();
    void test_signal();
    void sigHandler(int sig);

    template<class T> class Stack{
        private:
            vector<T> items;
        public:
            void push(T &t){
                items.push_back(t);
            }
            void pop(){
                items.pop_back();
            }
            T& top(){
                return items.back();
            }
            bool isEmpty(){
                return items.empty();
            }
    };

    struct Person{
        int id;
        string name;
    };

    class OPerson{ //抽象类不能被用于实例化对象，它只能作为接口使用,子类必须实现每个虚函数。
        public :
            int id;
            string name;
            virtual void say(string content){
                cout << "base says:" << content << endl;
            }
            //纯虚函数 类中至少有一个函数被声明为纯虚函数，则这个类就是抽象类;
            virtual string getName()=0;
            
            //静态成员变量在类中仅仅是声明，没有定义，所以要在类的外面定义，实际上是给静态成员变量分配内存。
            static int count;
            static int getCount(){
                return count;
            }
    };
    int OPerson::count=1;

    class Student : public OPerson{ //usually public inherit 
        public :
            //在类内部定义的函数默认为inline（10行以内，不要有递归，循环，switch）
            Student(){
                cout << "construct student" << endl;
            }
            void say(string content){
                cout << this->name << " says: " << content << endl;
            }
            string getName(){
                return "[s]"+name;
            }
            Student operator+(Student& s){
                Student ss;
                ss.id=this->id+s.id;
                ss.name=this->name+":"+s.name;
                return ss;
            }
    };
    class Teacher : public OPerson{
        public :
            Teacher(int i,string n){
                this->id=i;
                this->name=n;
            }
            void say(string content){
                cout << this->name << " says: " << content << endl;
            }
            string getName(){
                return "[t]"+name;
            }
            ~Teacher(){
                cout << "teacher obj will be delete" << endl;
            }
    };
}

#endif