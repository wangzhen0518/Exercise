#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long count(vector<int> const& a, int c) {
  long long cnt = 0;
  for (int i = 0; i < a.size(); i++)  // 遍历每一个B
  {
    int st;
    int l = i + 1, r = a.size() - 1;  // 寻找A第一次出现的位置，使得A-B=C
    while (l < r)  // 因为是第一次出现，尽量往左，模板1
    {
      int mid = l + r >> 1;
      if (a[mid] - a[i] >= c)
        r = mid;  // 判断：在目标值的右边，满足，往左来
      else
        l = mid + 1;
    }
    if (a[l] - a[i] == c) {
      st = l;                        // 能找到C就继续
      l = st - 1, r = a.size() - 1;  // 查找A最后出现的位置
      while (l < r)  // 因为是最后一次出现，尽量往右，模板2
      {
        int mid = l + r + 1 >> 1;
        if (a[mid] <= a[st])
          l = mid;  // 判断：在目标值的左边，满足，往右去
        else
          r = mid - 1;
      }
      cnt +=
          l - st + 1;  // 最后出现的位置减首次出现的位置就是区间长度，即A的个数}
    }
  }
  return cnt;
}

int main() {
  int n, c;
  cin >> n >> c;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());  // 先排序
  cout << count(a, c);
  return 0;
}
