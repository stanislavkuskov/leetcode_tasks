#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

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

    void q_sort(vector<int> &nums, int low, int high){
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

// 1. Two Sum
class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> res(2);

        map <int, int> dict;

        for (int i = 0; i < nums.size(); i++){
            int desired = target - nums[i];

            auto val = dict.find(desired);
            if (val != dict.end()){
                res[0] = dict.at(desired);
                res[1] = i;
                break;
            }
            dict.insert(pair(nums[i], i));
        }
        return res;
    }
};

int main() {
    Utils utils;

    TwoSum two_sum;
//    vector<int> nums = {2, 33, 7, 11, 15, 10, 2, 44, 34, 13};
    vector<int> nums = {2, 5, 15, 7, 19,33};
//    vector<int> nums = {3, 2, 4};
    vector<int> res = two_sum.twoSum(nums, 9);
    utils.print_vector(res);
    return 0;
}
