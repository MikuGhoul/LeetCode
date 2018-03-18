// Runtime: 173ms
void recursive(vector<int>::iterator lhs, vector<int>::iterator rhs, int& _ans) {
	if (lhs == rhs)	return;
	auto p = std::max_element(lhs, rhs);
	_ans += *p;
	int index = 1;
	for (auto i = lhs; i != p; ++i) {
		_ans -= *i;
		++index;
	}

	recursive(lhs + index, rhs, _ans);
}

class Solution {
public:
	int romanToInt(string s) {
		vector<int> parseTable;
		for (auto i = s.begin(); i != s.end(); ++i) {
			
			switch (*i) {
				case 'I':
					parseTable.push_back(1);
					break;
				case 'V':
					parseTable.push_back(5);
					break;
				case 'X':
					parseTable.push_back(10);
					break;
				case 'L':
					parseTable.push_back(50);
					break;
				case 'C':
					parseTable.push_back(100);
					break;
				case 'D':
					parseTable.push_back(500);
					break;
				case 'M':
					parseTable.push_back(1000);
					break;
			}
		}

		int ans = 0;
		recursive(parseTable.begin(), parseTable.end(), ans);
		return ans;
	}
};


// Runtime: 28 ms
static string s=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return "";
}();

class Solution {
public:
    int romanCharToInt(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
        return 0;
    }
    int romanToInt(string s) {
        int result = 0;
        if (s.empty()) return 0;
        if (s.size() == 1) {
            return romanCharToInt(s[0]);
        }
        int temp = romanCharToInt(s[0]);
        for (size_t i = 1; i < s.size(); ++i) {
            int v = romanCharToInt(s[i]);
            if (v > temp) {
                result -= temp;
                temp = v;
            }
            else {
                result += temp;
                temp = v;
            }
        }
        result += temp;
        return result;
    }
};