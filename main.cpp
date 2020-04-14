#include <iostream>
#include <vector>

using namespace std;

class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> res(2);

        for (int i = 0; i < nums.size(); ++i){
            for (int j=0; j < nums.size(); ++j){
                if (nums[i] + nums[j] == target and i!=j){
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }
        return res;
    }
};

int main() {
    TwoSum two_sum;
    vector<int> nums = {2, 33, 7, 11, 15, 10, 2, 44, 34, 13};
    vector<int> res = two_sum.twoSum(nums, 9);
    return 0;
}
