#include <bits/stdc++.h>
using namespace std;
void init(vector<vector<char>>& res, long long n, long long m, long long k) {
  for (long long i = 0; i < n; i += 2)
    for (long long j = 0; j < m; j += 2) {
      if (k > 0) {
        long long x = ((i / 2) + (j / 2)) % 2;
        if (x == 0) {
          res[i][j] = 'a';
          res[i][j + 1] = 'a';
          res[i + 1][j] = 'b';
          res[i + 1][j + 1] = 'b';
        } else {
          res[i][j] = 'p';
          res[i][j + 1] = 'p';
          res[i + 1][j] = 'u';
          res[i + 1][j + 1] = 'u';
        }
        k -= 2;
      } else {
        long long x = ((i / 2) + (j / 2)) % 2;
        if (x == 0) {
          res[i][j] = 'c';
          res[i][j + 1] = 'd';
          res[i + 1][j] = 'c';
          res[i + 1][j + 1] = 'd';
        } else {
          res[i][j] = 'e';
          res[i][j + 1] = 'f';
          res[i + 1][j] = 'e';
          res[i + 1][j + 1] = 'f';
        }
      }
    }
}
void find(vector<vector<char>>& res) {
  vector<vector<char>> ans(res[0].size(), vector<char>(res.size(), '-'));
  for (long long i = 0; i < res.size(); i++)
    for (long long j = 0; j < res[0].size(); j++) ans[j][i] = res[i][j];
  res = ans;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k, f = 0;
    cin >> n >> m >> k;
    if (m % 2 == 1) {
      f = 1;
      swap(n, m);
      k = n * m / 2 - k;
    }
    vector<vector<char>> res(n, vector<char>(m, '-'));
    if (n % 2 == 0) {
      if (k % 2 == 0)
        cout << "Yes\n";
      else {
        cout << "No\n";
        goto suff;
      }
    } else {
      k -= m / 2;
      if (k < 0) {
        cout << "No\n";
        goto suff;
      } else {
        if (k % 2 == 0) {
          cout << "Yes\n";
          for (long long i = 0; i < m; i += 2)
            if (i % 4 == 0) {
              res[n - 1][i] = 'z';
              res[n - 1][i + 1] = 'z';
            } else {
              res[n - 1][i] = 'o';
              res[n - 1][i + 1] = 'o';
            }
          --n;
        } else {
          cout << "No\n";
          goto suff;
        }
      }
    }
    init(res, n, m, k);
    if (f) find(res);
    for (auto x : res) {
      for (auto j : x) cout << j;
      cout << '\n';
    }
  suff:;
  }
  return 0;
}
