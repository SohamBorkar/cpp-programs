#include <iostream>
#include <vector>

using namespace std;

vector<int> countFrequency(int n, int x, vector<int> &nums)
{
    vector<int> v(x);

    // precomputation
    for (int i = 0; i < n; i++)
    {
        v[nums[i]]+=1;
        cout << v[i] << endl;
    }
    return v;
}

int main()
{
    int n = 4;
    int x = 3;

    vector<int> nums = {0, 1, 3, 1};

    // countFrequency(n, x, nums);

    string s = "heyllo";
    int freq[26] = {0};

    for(int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }
    int temp = sizeof(freq)/sizeof(freq[0]); 

    // cout << ('l' - 'a') << endl;
    // cout << freq[11] << endl;

    int uu = 0;
    while (uu < 26)
    {
        cout << freq[uu++] << endl;
        // uu++
        // instead of uu++ use freq[uu++], it works same.
    }

    

    return 0;
}