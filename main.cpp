#include <iostream>
#include <vector>

using namespace std;

class Utils {
public:
    void print_vector(const vector<int> & nums){
        cout << "[";
        for (auto num = nums.cbegin(); num != nums.cend(); ++num){
            if (num != nums.cbegin()){
                cout << ", ";
            }
            cout << *num;
        }
        cout << "]" << endl;
    };

};

class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> res(2);

        q_sort(nums, 0, nums.size()-1);

        int idx_search;
        int last = nums.size()-1;
        for (int i = 0; i < last - 1; i++){
            res[0] = i;
            idx_search = bin_search(nums, i + 1, last, target - nums[i]);
            if (idx_search != -1){
                res[1] = idx_search;
                break;
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
    int bin_search(const vector<int> &nums, int first, int last, int target){

        int mid_idx;

        while (true){
            mid_idx = (first + last) / 2;

            if (nums[mid_idx] > target) last = mid_idx-1;
            else if (nums[mid_idx] < target) first = mid_idx+1;
            else return mid_idx;

            if (first > last){
                return -1;
            }
        }
    }
};

int main() {
    Utils utils;

    TwoSum two_sum;
//    vector<int> nums = {2, 33, 7, 11, 15, 10, 2, 44, 34, 13};
//    vector<int> nums = {2, 7, 15, 5, 19,33};
    vector<int> nums = {3, 2, 4};
    vector<int> res = two_sum.twoSum(nums, 6);
    utils.print_vector(res);
    return 0;
}
