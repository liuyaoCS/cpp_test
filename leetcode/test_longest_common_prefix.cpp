
#include <iostream> 
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        if(strs.size()==1){
            return strs.at(0);
        }
        string tmp=strs.at(0);
        int index=0;
        int last=0;

        bool err = false;
        for(char c:tmp){
            for(string str:strs){
                if(str.at(index)!=c){
                    err=true;
                    break;
                }
            }
            if(err){
                break;
            }
            last=index;
            index++;
        }
        if(!err){
            return tmp;
        }else{
            return tmp.substr(0,index);
        }
        
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    vector<string> strs={"flower","flow","flight"};
    string ret=s.longestCommonPrefix(strs);
    cout << "ret= " << ret << endl;
    return 0;
}
