// 236 ms submission
/*

Already lost...

*/


// 3 ms submission

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); ++i) {
            auto search = index.find(target - nums[i]);
            if (search != index.end())
                return vector<int> {search->second, i};
            index[nums[i]] = i;
        }
    }
};