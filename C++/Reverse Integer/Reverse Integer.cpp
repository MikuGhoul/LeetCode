// Runtime: 25ms
class Solution {
public:
	int reverse(int x) {
		long long ans = 0;
		do {
			ans = ans * 10 + (x % 10);
		} while (x /= 10);

		if (ans > INT32_MAX || ans < INT32_MIN)
			return 0;
		return ans;
	}
};


/* 
    排第一的Solutions强行优化23333，学到了
*/

// Runtime: 6ms
static int x = []() { 
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL);  
    return 0; 
}();

class Solution {
public:
    int reverse(int x) {
        long answer = 0;
        while (x != 0) {
            answer = answer * 10 + x % 10;
            if (answer > INT_MAX || answer < INT_MIN) return 0;
            x /= 10;
        }
        return (int)answer;
    }
};
