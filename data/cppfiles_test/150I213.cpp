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
        if (a[p] <= 3 * x) {
          int l = a[p] % 3;
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
          int s = a[p] - 3 * x;
          int dw = j + i / 2;
          int od = i % 2;
          if (s % 2 == 0) {
            if (2 * dw < s) {
              chek = 0;
              break;
            }
          } else {
            if (od == 0) {
              if (i >= 2)
                dw--;
              else {
                chek = 0;
                break;
              }
            }
            s--;
            if (2 * dw < s) {
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
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.rbegin(), a.rend());
  int k = a[0] / 3;
  if (a[0] % 3 != 0) k++;
  if (che(k, a))
    cout << k << "\n";
  else
    cout << k + 1 << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
