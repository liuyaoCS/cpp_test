
#include <iostream> 
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
private:
    const int T = 0;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;i++){
            int target=T-nums[i];
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]>target)k--;
                else if(nums[j]+nums[k]<target)j++;
                else{
                    vector<int> arr={nums[i],nums[j],nums[k]};
                    res.insert(arr);
                    j++;
                    k--;
                }
            }
        }
        vector<vector<int>> ret;
        for(vector<int> v:res){
            ret.push_back(v);
        }
        return ret;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    vector<int> inputs={-1, 0, 1, 2, -1, -4};
   
    vector<vector<int>> rets = s.threeSum(inputs);
    for(vector<int> ret:rets){
        cout << "{" ;
        for(int i:ret){
            cout<<  i << ",";
        }
        cout << "}" << endl;
    }
    return 0;
}
