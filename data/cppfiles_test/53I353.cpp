#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
int nums[maxn];
int main() {
  int t, n, k;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> k;
    int p = 0;
    int last = 0;
    for (int j = 0; j < n; j++) {
      cin >> nums[j];
      if (p == 0)
        last = nums[j] + 1;
      else
        last = nums[j - 1];
      if (nums[j] < last) p++;
    }
    if (p <= k)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
