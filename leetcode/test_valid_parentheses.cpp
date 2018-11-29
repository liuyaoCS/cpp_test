#include <iostream> 
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
private:
    unordered_map<char,char> um={
        {']','['},
        {'}','{'},
        {')','('}
    };
public:
    bool isValid(string s) {
        stack<char> sk;
        for(char c:s){
            if(c=='[' || c=='{' || c=='('){
                sk.push(c);
            }else{
                // auto p=um.find(c);
                // char tmp=p->second;
                char tmp=um.at(c);
                if(tmp==sk.top()){
                    sk.pop();
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    string str="{[]}";
    bool ret=s.isValid(str);
    cout << "ret= " << ret << endl;
    return 0;
}
