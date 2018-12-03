#include <iostream> 
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int t=0;
        while(i<nums.size()){
            while(nums[i]==val){
                i++;
            }
            nums[t]=nums[i];
            t++;
            i++;
        }
        return t;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    vector<int> vc={1,2,2,3};
    int ret=s.removeElement(vc,2);
    for(int i=0;i<ret;i++){
        cout << vc[i] << " " ; 
    }
    cout << endl;
    return 0;
}
