// Runtime: 28 ms
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		
		int count = 0;
		if (!nums.size())
			return 0;
		for (auto i = nums.begin() + 1; i != nums.end(); ++i) {
			if (*i == *(i - 1))
				count++;
			else
				*(i - count) = *i;
		}
		nums.erase(nums.end() - count, nums.end());
		return nums.size();
	}
};