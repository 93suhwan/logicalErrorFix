#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979323846;
const long long M = 1e18 + 7;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const int mod = 998244353;
void solve() {
  int n;
  cin >> n;
  int v[n][5];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      vector<int> temp(3, 0);
      for (int k = 0; k < n; k++) {
        if (v[k][i] + v[k][j] == 2) {
          temp[2]++;
        } else if (v[k][i] == 1) {
          temp[0]++;
        } else if (v[k][j])
          temp[1]++;
        else
          break;
        if (k == n - 1) {
          if (temp[0] <= n / 2 && temp[1] <= n / 2) {
            cout << "YES" << endl;
            return;
          }
        }
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
