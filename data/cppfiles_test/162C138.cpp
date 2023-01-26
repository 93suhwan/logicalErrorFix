#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test_case;
  cin >> test_case;
  for (int test = 1; test <= test_case; test++) {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    int ans;
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
      ans = min(ans, v[i]);
    }
    int lo = ans + 1, hi = 1e9;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      vector<int> a = v;
      vector<int> tmp(n + 1);
      bool flag = 1;
      for (int i = n; i > 2 && flag; i--) {
        a[i] += tmp[i];
        if (a[i] < mid) flag = 0;
        a[i] -= tmp[i];
        int k = a[i] - max(0, mid - tmp[i]);
        k /= 3;
        tmp[i - 1] += k;
        tmp[i - 2] += k + k;
      }
      if ((a[1] + tmp[1] < mid) or (a[2] + tmp[2] < mid)) flag = 0;
      if (flag) {
        ans = mid, lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    cout << ans << '\n';
  }
}
