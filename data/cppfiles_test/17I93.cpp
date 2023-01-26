#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 100005;
const int oo = 1000000000;
bool winna(int inp[][6], int r1, int r2) {
  int ct = 0;
  for (int i = 1; i <= 5; i++) {
    if (inp[r1][i] < inp[r2][i]) ++ct;
  }
  if (ct > 2) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int inp[n + 1][6];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 5; j++) {
        cin >> inp[i][j];
      }
    }
    unordered_map<int, int> um;
    for (int i = 1; i <= 5; i++) {
      int ind = -1, m = INT_MAX;
      for (int j = 1; j <= n; j++) {
        if (inp[j][i] < m) {
          ind = j;
          m = inp[j][i];
        }
      }
      if (!um[ind])
        um[ind] = 1;
      else
        ++um[ind];
    }
    bool b = true;
    bool t = true;
    for (auto x : um) {
      if (x.second > 2) {
        b = false;
        cout << x.first << endl;
        break;
      } else {
        t = true;
        for (int i = 1; i <= n; i++) {
          if (i == x.first) continue;
          if (!winna(inp, x.first, i)) {
            t = false;
            break;
          }
        }
        if (t) {
          cout << x.first << endl;
          break;
        }
      }
    }
    if (b && !t) cout << -1 << endl;
  }
}
