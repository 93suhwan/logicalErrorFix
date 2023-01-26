#include <bits/stdc++.h>
using namespace std;
bool che(long long k, vector<long long> &a, int n) {
  for (long long i = 0; i <= 3; i++) {
    for (long long j = 0; j <= 3; j++) {
      long long x = k - i - j;
      if (x < 0) continue;
      bool chek = 1;
      for (int p = 0; p < n; p++) {
        if (a[p] <= 3 * x) {
          long long l = a[p] % 3;
          if (l == 0) continue;
          if (l == 1 and i == 0) {
            chek = 0;
            break;
          }
          if (l == 2 and j == 0) {
            chek = 0;
            break;
          }
        } else {
          long long s = a[p] - 3 * x;
          if (s <= 0) continue;
          long long dw = j + i / 2;
          long long od = i % 2;
          if (s % 2 == 0) {
            if ((s - 2 * dw - od) > 0) {
              chek = 0;
              break;
            }
          } else {
            if (od == 0) {
              if (i != 0)
                dw--;
              else {
                chek = 0;
                break;
              }
            }
            if ((s - 2 * dw - od) > 0) {
              chek = 0;
              break;
            }
          }
        }
      }
      if (chek) {
        return 1;
      }
    }
  }
  return 0;
}
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.rbegin(), a.rend());
  long long l = 1, r = a[0] + 1;
  while (l != r) {
    long long m = (l + r) / 2;
    if (che(m, a, n))
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
