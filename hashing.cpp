#include <iostream>
#include <vector>

using namespace std;

vector<int> countFrequency(int n, int x, vector<int> &nums)
{
    // Write your code here.
    vector<int> v(x);

    for (int i = 0; i < n; i++)
    {
        v[nums[i]]++;
        cout << v[i] << endl;
    }

    return v;
}

int main()
{
    int n = 4;
    int x = 3;

    vector<int> nums = {0, 1, 3, 1};

    countFrequency(n, x, nums);
    return 0;
}