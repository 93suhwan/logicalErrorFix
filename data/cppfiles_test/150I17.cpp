#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long double Pi = 3.141592653;
const long long mod = 998244353;
long long INF = 1000000000000000000;
struct mycmp {
  bool operator()(pair<int, int> a, pair<int, int> b) const {
    return (a.first < b.first) || (a.first == b.first && a.second > b.second);
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans5 = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] % 3)
        ++cnt;
      else
        ans5 = max(ans5, a[i] / 3);
    }
    if (!cnt)
      cout << ans5 << "\n";
    else {
      long long x1 = 0, x2 = 0;
      long long ans = 0, ans1 = 0, ans2 = 0;
      for (int i = 0; i < n; i++) {
        ans = max(ans, a[i] / 3);
        long long y = a[i] % 3;
        if (y == 2)
          x1 = max(x1, y);
        else if (y == 1)
          x1 = max(x1, y);
      }
      ans += x1;
      x1 = 0;
      long long ans4 = 0;
      for (int i = 0; i < n; i++) {
        ans4 = max(ans4, a[i] / 3);
        if (a[i] == 1) ans4 = INF;
        long long y = a[i] % 3;
        if (y == 2)
          x1 = 1;
        else if (y == 1)
          x1 = 2;
      }
      if (x1 == 2) {
        for (int i = 0; i < n; i++) {
          if (a[i] % 3 == 1) {
            long long h = a[i] - 4;
            ans1 = max(ans1, h / 3);
          } else
            ans1 = max(ans1, a[i] / 3);
        }
        ans1 += 2;
        ans4 = INF;
      } else
        ans4 += 1, ans1 = INF;
      x1 = 0, x2 = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] % 3 == 1) ++x1;
        if (a[i] % 3 == 2) ++x2;
        if (a[i] % 3 == 0)
          ans2 = max(ans2, a[i] / 3 - 1);
        else
          ans2 = max(ans2, a[i] / 3);
      }
      ans2 += 2;
      cout << min(ans1, min(ans2, min(ans, ans4))) << "\n";
    }
  }
}
