#include <iostream> 
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p=0;
        int c=1;
        while(c<nums.size()){
            if(nums.at(p)<nums.at(c)){
                p++;
                c=p+1;
                continue;
            }
            
            while(c<nums.size() && nums.at(c)==nums.at(p)){
                c++;
            }
            if(c<nums.size()){
                nums[p+1]=nums.at(c);
                p=c-1;
            }
        }
        int ret=nums.size();
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                return i; 
            }
        }
        return ret;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    vector<int> vc={1,2,2,3};
    int ret=s.removeDuplicates(vc);
    for(int i=0;i<ret;i++){
        cout << vc[i] << " " ; 
    }
    cout << endl;
    return 0;
}
