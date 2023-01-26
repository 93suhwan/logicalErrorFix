#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long double PI = 3.14159265358979323846;
const long double EPS = 0.000000001;
const long long MD_7 = 1000000007;
const long long MD_9 = 1000000009;
const long long MD = 228228227;
const long long INF = 1e18;
bool solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<vector<char> > a(n, vector<char>(m));
  vector<vector<bool> > used(n, vector<bool>(m, false));
  for (long long i = 0; i < n; ++i)
    for (long long j = 0; j < m; ++j) cin >> a[i][j];
  for (long long i = n - 1; i >= 0; i--)
    for (long long j = 0; j < m; ++j)
      if (a[i][j] == '*') {
        long long delt = 1;
        while (i >= delt && j >= delt && j + delt < m) {
          if (a[i - delt][j - delt] == '*' && a[i - delt][j + delt] == '*')
            delt++;
          else
            break;
        }
        delt--;
        bool flag = false;
        if (delt >= k) flag = true;
        if (flag) {
          used[i][j] = true;
          delt = 1;
          while (i >= delt && j >= delt && j + delt < m) {
            if (a[i - delt][j - delt] == '*' && a[i - delt][j + delt] == '*') {
              used[i - delt][j - delt] = true;
              used[i - delt][j + delt] = true;
              delt++;
            } else
              break;
          }
        }
        if (!used[i][j]) return false;
      }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) cout << (solve() ? "YES\n" : "NO\n");
  return 0;
}
