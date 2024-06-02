#include <iostream>
#include <vector>

using namespace std;

int lastOcccurence(vector<int> v, int target)
{
    int s = 0;
    int e = v.size() - 1;

    int mid = s + (e - s) / 2;

    int ans = -1;

    while (s <= e)
    {
        if (v[mid] == target)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (v[mid] > target)
        {
            e = mid - 1;
        }

        else if (v[mid] < target)
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    vector<int> v{1, 2, 3, 3, 3, 4, 5, 5, 6};
    int target = 3;
    int ans = lastOcccurence(v, target);
    cout << "Last Occurence of " << target << " is " << ans;
    return 0;
}