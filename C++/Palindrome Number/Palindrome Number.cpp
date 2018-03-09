// Runtime: 223 ms
class Solution
{
  public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (!x)
            return true;
        long long div = 1, mod = 1;
        while (x / div)
        {
            div *= 10;
        }
        div /= 10;

        while (div != mod)
        {
            if (x / div % 10 != x / mod % 10)
                return false;
            if (div / 10 == mod)
                return true;
            div /= 10;
            mod *= 10;
        }
        return true;
    }
};

// 负数肯定不是回文数了
// 判断回文数的几种解决方案
// 1. 转换成字符串再判断
bool isPalindrome(string &str)
{
    int begin = 0, end = str.length() - 1;
    while (begin < end)
    {
        if (str[begin] == str[end])
        {
            begin++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

// 2. 把数字翻转后与原数比较
int reverse(int num)
{
    assert(num >= 0);
    int rev = 0;
    while (num != 0)
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}
// 3. 数字逐位比较
// 就是我用的那种

