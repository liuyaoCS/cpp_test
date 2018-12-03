#include <iostream> 
#include <vector>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        bool found=false;
        int i=0;
        int it=0;
        while(i<haystack.size()){
            int j=0;
            it=i;
            while(j<needle.size()){
                if(haystack[it]==needle[j]){
                    it++;
                    j++;
                }else{
                    break;
                }
            }
            if(j==needle.size()){
                return i;
            }
            i++;
        }
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    string haystack = "hello", needle = "ll";
    int ret=s.strStr(haystack,needle);
    cout << ret << endl;
    return 0;
}
