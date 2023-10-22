#include <iostream>
using namespace std;

bool ispalin(int i, int n, string &s)
{
    while (i <= n)
    {
        if (s[i] != s[n - i]) return false;

        i++;
        n--;
    }
    return true;
};

bool recpalin(int i, int n, string &s)
{
    if (i >= n / 2) return true;

    if (s[i] != s[n]) return false;

    return recpalin(i + 1, n - 1, s);
}

bool f(int i, string &str){ 

    if(i >= (str.size() >> 1)) return true;

    if(str[i] != str[str.size() - i - 1]) return false;

    return f(i+1, str);
}

int main()
{
    string s = "appa";

    cout << ispalin(0, s.size() - 1, s) << endl;
    cout << recpalin(0, s.size() - 1, s) << endl;
    cout << f(0, s) << endl;
    return 0;
}