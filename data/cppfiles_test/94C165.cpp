#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  string s;
  cin >> s;
  int n = ((int)((s).size()));
  reverse(s.begin(), s.end());
  vector<vector<vector<long long>>> f(
      n, vector<vector<long long>>(2, vector<long long>(2)));
  for (int i = (0); i < (10); ++i) {
    for (int j = (0); j < (10); ++j) {
      int su = i + j;
      if (su % 10 == (s[0] - '0')) {
        ++f[0][0][su / 10];
      }
    }
  }
  for (int cyf = (0); cyf < (n - 1); ++cyf) {
    for (int c1 = (0); c1 < (2); ++c1) {
      for (int c2 = (0); c2 < (2); ++c2) {
        if (f[cyf][c1][c2] == 0) {
          continue;
        }
        int szuk = s[cyf + 1] - '0';
        for (int i = (0); i < (10); ++i) {
          for (int j = (0); j < (10); ++j) {
            int su = i + j + c1;
            if (su % 10 != szuk) {
              continue;
            }
            f[cyf + 1][c2][su / 10] += f[cyf][c1][c2];
          }
        }
      }
    }
  }
  cout << f[n - 1][0][0] - 2 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
