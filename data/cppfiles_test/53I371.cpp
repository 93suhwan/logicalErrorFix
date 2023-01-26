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
      if (p != 0) {
        if (nums[j] < nums[j - 1]) p++;
      } else
        p = 1;
    }
    if (p <= k)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
