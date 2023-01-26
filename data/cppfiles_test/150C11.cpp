#include <bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector,unroll-loops")
#pragma GCC target("avx2,fma")
using namespace std;
const long long inf = 2e9, N = 1e6 + 10, mod = 1e9 + 7, pr = 998244353;
int a[N];
int cnt1, cnt2, cnt3;
int ans1, ans2, ans3;
int ans_t;
bool g;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ans_t = inf;
    cnt1 = 0, cnt2 = 0, cnt3 = 0;
    ans1 = 0, ans2 = 0, ans3 = 0;
    g = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1) g = 1;
      if (a[i] % 3 == 0)
        cnt3 = max(cnt3, a[i]);
      else if (a[i] % 3 == 2)
        cnt2 = max(cnt2, a[i]);
      else
        cnt1 = max(cnt1, a[i]);
    }
    if (g == 0) {
      if (cnt2 > 0) {
        ans2 = 1;
        ans3 = cnt2 / 3;
      }
      if (cnt1 > 0) {
        ans2 = 2;
        ans3 = max(ans3, (cnt1 - 4) / 3);
      }
      if (cnt3 > 0) {
        if (ans1 == 0 || ans2 == 0)
          ans3 = max(ans3, (cnt3 / 3));
        else
          ans3 = max(ans3, (cnt3 - 3) / 3);
      }
      ans_t = ans1 + ans2 + ans3;
    }
    ans1 = 0, ans2 = 0, ans3 = 0;
    if (cnt2 > 0) {
      ans2 = 1;
      ans3 = cnt2 / 3;
    }
    if (cnt1 > 0) {
      ans1 = 1;
      ans3 = max(ans3, (cnt1 - 1) / 3);
    }
    if (cnt3 > 0) {
      if (ans1 == 0 || ans2 == 0)
        ans3 = max(ans3, (cnt3 / 3));
      else
        ans3 = max(ans3, (cnt3 - 3) / 3);
    }
    ans_t = min(ans_t, ans1 + ans2 + ans3);
    ans1 = 0, ans2 = 0, ans3 = 0;
    if (cnt2 > 0) {
      ans1 = 2;
      ans3 = cnt2 / 3;
    }
    if (cnt1 > 0) {
      if (ans1 == 0) ans1 = 1;
      ans3 = max(ans3, (cnt1 - 1) / 3);
    }
    if (cnt3 > 0) {
      ans3 = max(ans3, (cnt3 / 3));
    }
    ans_t = min(ans_t, ans1 + ans2 + ans3);
    cout << ans_t << "\n";
  }
  return 0;
}
