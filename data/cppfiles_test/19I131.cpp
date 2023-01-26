#include <bits/stdc++.h>
using namespace std;
set<int> s;
int arr[15], x[200005];
int get_sum(int mask, int n) {
  int ret = 0;
  for (int i = 0; i < n; i++) {
    if (mask & (1 << i)) ret += arr[i];
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    s.clear();
    for (int j = 0; j < 2e5 + 5; j++) {
      x[j] = 0;
    }
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
      x[int(arr[j] + 1e5)] = j + 1;
      s.insert(arr[j]);
    }
    if (s.size() < n) {
      cout << "YES\n";
      continue;
    }
    int b1 = 0;
    for (int mask1 = 0; mask1 < (1 << n); mask1++) {
      for (int mask2 = 0; mask2 < (1 << n); mask2++) {
        if (mask1 & mask2) continue;
        int a = get_sum(mask1, n) - get_sum(mask2, n);
        if (a > 1e5) continue;
        if (!x[int(a + 1e5)]) continue;
        if (!(mask1 & (1 << (x[int(a + 1e5)] - 1))) &&
            !(mask2 & (1 << (x[int(a + 1e5)] - 1))))
          b1 = 1;
      }
    }
    if (b1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
