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
    long long n, m, k;
    cin >> n >> m >> k;
    char c[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cin >> c[i][j];
    }
    char ans[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (c[i][j] == '.')
          ans[i][j] = '.';
        else {
          int cnt1 = 0, idx1 = i - 1, idx2 = j - 1;
          while (idx1 >= 0 && idx2 >= 0 && c[idx1][idx2] == '*')
            ++cnt1, --idx1, --idx2;
          int cnt2 = 0;
          idx1 = i - 1, idx2 = j + 1;
          while (idx1 >= 0 && idx2 < m && c[idx1][idx2] == '*')
            ++cnt2, --idx1, ++idx2;
          cnt1 = min(cnt1, cnt2);
          if (cnt1 < k) continue;
          ans[i][j] = c[i][j];
          idx1 = i - 1;
          idx2 = j - 1;
          cnt2 = cnt1;
          while (cnt2--) {
            ans[idx1][idx2] = '*';
            --idx1;
            --idx2;
          }
          cnt2 = cnt1;
          idx1 = i - 1;
          idx2 = j + 1;
          while (cnt2--) {
            ans[idx1][idx2] = '*';
            --idx1;
            ++idx2;
          }
        }
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (c[i][j] != ans[i][j]) {
          ok = false;
        }
      }
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
