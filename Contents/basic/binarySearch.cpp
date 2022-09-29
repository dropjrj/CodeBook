#include <bits/stdc++.h>
using namespace std;

int binary_search(const vector<int> &data, int key)
{
    int low = 0;
    int high = data.size()-1;
    while (low <= high)
	{
        int mid = int((low + high) / 2);
        if (key == data[mid])
            return mid;
        else if (key > data[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> data = {1, 9, 2, 7, 4, 10, 3, 8, 5, 6};
    int key = 7;
    
    sort(data.begin(), data.end());

    int ret = binary_search(data, key);
    if (ret == -1)
        cout << "找不到\n";
    else
        cout << "找到索引值" << ret << "\n";
	//lower_bound(a, a + n, k);     //最左邊 ≥ k 的位置
	//upper_bound(a, a + n, k);     //最左邊 > k 的位置
	//upper_bound(a, a + n, k) - 1; //最右邊 ≤ k 的位置
	//lower_bound(a, a + n, k) - 1; //最右邊 < k 的位置
	//[lower_bound, upper_bound) //等於 k 的範圍
	//equal_range(a, a+n, k);
}
