#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int count;
extern void write_extern(void);

void test_base();
void test_pointer();
void test_struct();
void test_object();

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

int main(){
    
    test_base();
    test_pointer();
    test_struct();
    test_object();

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
    };
    Color color=Blue;
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

void test_object(){

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