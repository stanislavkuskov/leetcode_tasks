#include <iostream>
#include <vector>

using namespace std;

class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> res(2);

        q_sort(nums, 0, nums.size()-1);

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

    void q_sort(vector<int> & nums, int low, int high){
        if (low < high){
            int pivot = nums[high];
            int i = low;
            int j = high;

            while (i <= j){
                while (nums[i] < pivot){
                    i++;
                }
                while (nums[j] > pivot){
                    j--;
                }
                if (i <= j){
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                    i++;
                    j--;
                }
            }
            if (low < i){
                q_sort(nums, low, j);
            }
            if (j < high){
                q_sort(nums, i, high);
            }
        }
    }
};

int main() {
    TwoSum two_sum;
    vector<int> nums = {2, 33, 7, 11, 15, 10, 2, 44, 34, 13};
    vector<int> res = two_sum.twoSum(nums, 9);
    return 0;
}
