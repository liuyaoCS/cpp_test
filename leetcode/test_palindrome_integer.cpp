
#include <iostream> 
#include <stack>
using std::cout;
using std::endl;
class Solution {
public:
    bool isPalindrome(int x) {
        return x == reverse(x);
    }
    int reverse(int x) {
        std::stack<int> st;
        bool negtive = false;
             
        if (x == 0) {
            return 0;
        }else if(x <= 0) {
            negtive = true;
            x*=-1;
        }
        
        int ret=0;  
        while(x>0){
            int d = x%10;
            st.push(d);
            x=x/10;
        }
        int i=1;
        while(!st.empty()){
            int s=st.top();
            s=s*i;
            ret+=s;

            st.pop();
            i*=10;
        }
        return negtive?-ret:ret;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    bool ret=s.isPalindrome(121);
    cout << "ret= " << ret << endl;
    return 0;
}
