
#include <iostream> 
#include <vector>
using std::cout;
using std::endl;
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> vc;
        int start=0;
        int end=nums.size()-1;
        int tmp=nums.at(start)+nums.at(end);
        while( tmp != target){
            if(tmp > target){
                end--;
            }else{
                start++;
            }
            tmp=nums.at(start)+nums.at(end);
        }
        vc.push_back(start);
        vc.push_back(end);
        return vc;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    std::vector<int> inputs={2,5,6,9};

    int t=7;
    std::vector<int> ret = s.twoSum(inputs,t);
    for(int i:ret){
        cout<< "item " << i << endl;
    }

    return 0;
}
