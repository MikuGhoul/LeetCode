// Runtime: 458 ms
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		set<char> container;
		size_t ans = 0;

		for (string::iterator i = s.begin(); i != s.end(); ++i) {
			if (s.end() - i < container.size())
				break;
			container.insert(*i);
			for (string::iterator j = i + 1; j != s.end(); ++j) {
				if (container.find(*j) != container.end()) {
					ans = (container.size() > ans) ? container.size() : ans;
					container.clear();
					break;
				}
				container.insert(*j);
			}
		}
		INT_MIN;
		ans = (container.size() > ans) ? container.size() : ans;
		return ans;
	}
};

// 比较坑的数据
// ""		空串
// "a"		字符串长度为1


// Runtime: 6 ms
class Solution
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int flags[256];
        for (int i = 0; i < 256; i++)
            flags[i] = -1;
        
        int longest = 0;
        int i = 0;
        int collision = -1;
        while (s[i] != 0)
        {
            if (flags[s[i]] != -1)
                collision = (collision > flags[s[i]] ? collision : flags[s[i]]);
            flags[s[i]] = i;
            longest = (i - collision > longest ? i - collision : longest);
            i++;
        }
        
        return longest;
    }
};