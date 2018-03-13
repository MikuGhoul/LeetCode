// Runtime: 7 ms
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int flag = 0;
		for (auto i : nums)
			if (i == val)
				++flag;
		for (auto i = nums.begin(); i != nums.end(); ++i) {
			if (*i != val)
				continue;
			for (auto j = i + 1; j != nums.end(); ++j) {
				if (*j != val) {
					int temp = *j;
					*j = *i;
					*i = temp;
					break;
				}
			}
		}
		nums.erase(nums.end() - flag, nums.end());
		
		return nums.size();
	}
};

// 这题做的感觉我自己是个**，尤其是看到了下面的答案

// Runtime:6 ms 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
         auto v = std::remove(nums.begin(), nums.end(), val);
         int sz = distance(nums.begin(), v);
        return sz;
    }
};