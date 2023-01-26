#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (k == 0) {
      if (n % 2)
        cout << "NO\n";
      else
        cout << "YES\n";
      continue;
    }
    int wid = m / 2;
    int hei = wid * n;
    if (hei < k) {
      cout << "NO\n";
      continue;
    }
    hei -= k;
    int rest_wid = hei / n;
    int rest_hei = hei % n;
    if (rest_hei % 2) {
      cout << "NO\n";
      continue;
    }
    if (rest_wid) {
      if (n % 2) {
        cout << "NO\n";
        continue;
      }
    }
    cout << "YES\n";
  }
  return 0;
}
