#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> v, int target)
{
    int s = 0;
    int e = v.size() - 1;

    int mid = (s + e) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (v[mid] == target)
        {
            ans = mid;
            e = mid - 1;
        }

        else if (target > v[mid])
        {
            s = mid + 1;
        }

        else if (target < v[mid])
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
    }
    return ans;
}

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
    vector<int> v{1, 2, 3, 4, 4, 5, 5, 6, 7};
    int target = 5;
    int first = firstOccurence(v, target);
    int second = lastOcccurence(v, target);

    cout << "Sum is :" << second - first + 1 << endl;
    return 0;
}