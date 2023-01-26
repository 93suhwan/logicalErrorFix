#include <bits/stdc++.h>
using namespace std;
bool che(int k, vector<int> &a) {
  int n = a.size();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int x = k - i - j;
      if (x < 0) continue;
      bool chek = 1;
      for (int p = 0; p < n; p++) {
        bool h = 0;
        for (int l = 0; l <= i; l++) {
          for (int w = 0; w <= j; w++) {
            int t = a[p] - l - 2 * w;
            if ((t - 3 * x) <= 0 and t >= 0 and (t % 3 == 0)) h = 1;
          }
        }
        if (!h) {
          chek = 0;
          break;
        }
      }
      if (chek) return 1;
    }
  }
  return 0;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.rbegin(), a.rend());
  int k = a[0] / 3;
  if (a[0] % 3 != 0) k++;
  int l = 1, r = a[0] + 1;
  while (l != r) {
    int m = (l + r) / 2;
    if (che(m, a))
      r = m;
    else
      l = m + 1;
  }
  cout << l << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
