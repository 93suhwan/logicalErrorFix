#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  int mod = 998244353;
  cin >> n >> k;
  string S;
  cin >> S;
  vector<vector<int>> c(n + 1, vector<int>(n + 1, 1));
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
  }
  int f = 0;
  for (auto s : S) {
    if (s == '1') {
      ++f;
    }
  }
  if (f < k) {
    cout << 1 << endl;
    return;
  }
  int r = 1;
  for (int i = 0; i < n; ++i) {
    if (S[i] == '1') {
      int j = i + 1, z = 0;
      while (j < n) {
        z += (S[j] == '1');
        if (z >= k) {
          --z;
          break;
        }
        ++j;
      }
      int x = j - i - 1;
      if (x == z || x == 0) {
        continue;
      }
      r += c[x][z + 1];
      r %= mod;
    } else {
      int j = i + 1, z = 0;
      while (j < n) {
        z += (S[j] == '1');
        if (z > k) {
          --z;
          break;
        }
        ++j;
      }
      int x = j - i - 1;
      if (z == 0) {
        continue;
      }
      r += c[x][z - 1];
      r %= mod;
    }
  }
  cout << r << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  solve();
  return 0;
}
