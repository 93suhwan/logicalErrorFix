#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;
const long double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX;
const long long SIZE = 100000;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (n % 2 == 1) {
    long long some = m / 2;
    if (k < some) {
      cout << "NO" << endl;
      return;
    }
    k -= some;
    if (k % 2 == 0) {
      cout << "YES" << endl;
      char ans[n][m];
      for (long long i = 0; i < (long long)n; i++) {
        for (long long j = 0; j < (long long)m; j++) {
          ans[i][j] = '1';
        }
      }
      long long cur = 0;
      for (long long i = 0; i < m; i += 2) {
        ans[0][i] = cur + 'a';
        ans[0][i + 1] = cur + 'a';
        cur = (cur + 1) % 26;
      }
      for (long long i = 1; i < n; i += 2) {
        for (long long j = 0; j < m; j += 2) {
          if (k == 0) break;
          if (ans[i - 1][j] == cur + 'a') {
            cur = (cur + 1) % 26;
          }
          if (j > 0 && ans[i][j - 1] == cur + 'a') {
            cur = (cur + 1) % 26;
          }
          if (i > 0 && j > 0) {
            while (ans[i - 1][j] == cur + 'a' && ans[i][j - 1] == cur + 'a') {
              cur = (cur + 1) % 26;
            }
          }
          ans[i][j] = cur + 'a';
          ans[i][j + 1] = cur + 'a';
          cur = (cur + 1) % 26;
          ans[i + 1][j] = cur + 'a';
          ans[i + 1][j + 1] = cur + 'a';
          cur = (cur + 1) % 26;
          k -= 2;
        }
        if (k == 0) break;
      }
      for (long long i = 1; i < n; i += 2) {
        for (long long j = 0; j < (long long)m; j++) {
          if (ans[i][j] == '1') {
            if (ans[i - 1][j] == cur + 'a') {
              cur = (cur + 1) % 26;
            }
            if (j > 0 && ans[i][j - 1] == cur + 'a') {
              cur = (cur + 1) % 26;
            }
            if (i > 0 && j > 0) {
              while (ans[i - 1][j] == cur + 'a' && ans[i][j - 1] == cur + 'a') {
                cur = (cur + 1) % 26;
              }
            }
            ans[i][j] = cur + 'a';
            ans[i + 1][j] = cur + 'a';
            cur = (cur + 1) % 26;
          }
        }
      }
      for (long long i = 0; i < (long long)n; i++) {
        for (long long j = 0; j < (long long)m; j++) cout << ans[i][j];
        cout << endl;
      }
    } else
      cout << "NO" << endl;
    return;
  }
  if (m % 2 == 1) {
    if (k > (n * m - n) / 2) {
      cout << "NO" << endl;
      return;
    }
  }
  if (k % 2 == 0) {
    cout << "YES" << endl;
    char ans[n][m];
    long long cur = 0;
    for (long long i = 0; i < (long long)n; i++) {
      for (long long j = 0; j < (long long)m; j++) {
        ans[i][j] = '1';
      }
    }
    for (long long i = 0; i < n; i += 2) {
      for (long long j = 0; j < m - 1; j += 2) {
        if (k == 0) break;
        if (i > 0 && ans[i - 1][j] == cur + 'a') {
          cur = (cur + 1) % 26;
        }
        if (j > 0 && ans[i][j - 1] == cur + 'a') {
          cur = (cur + 1) % 26;
        }
        if (i > 0 && j > 0) {
          while (ans[i - 1][j] == cur + 'a' && ans[i][j - 1] == cur + 'a') {
            cur = (cur + 1) % 26;
          }
        }
        ans[i][j] = cur + 'a';
        ans[i][j + 1] = cur + 'a';
        cur = (cur + 1) % 26;
        ans[i + 1][j] = cur + 'a';
        ans[i + 1][j + 1] = cur + 'a';
        cur = (cur + 1) % 26;
        k -= 2;
      }
      if (k == 0) break;
    }
    for (long long i = 0; i < n; i += 2) {
      for (long long j = 0; j < (long long)m; j++) {
        if (ans[i][j] == '1') {
          if (i > 0 && ans[i - 1][j] == cur + 'a') {
            cur = (cur + 1) % 26;
          }
          if (j > 0 && ans[i][j - 1] == cur + 'a') {
            cur = (cur + 1) % 26;
          }
          if (i > 0 && j > 0) {
            while (ans[i - 1][j] == cur + 'a' && ans[i][j - 1] == cur + 'a') {
              cur = (cur + 1) % 26;
            }
          }
          ans[i][j] = cur + 'a';
          ans[i + 1][j] = cur + 'a';
          cur = (cur + 1) % 26;
        }
      }
    }
    for (long long i = 0; i < (long long)n; i++) {
      for (long long j = 0; j < (long long)m; j++) cout << ans[i][j];
      cout << endl;
    }
  } else
    cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
