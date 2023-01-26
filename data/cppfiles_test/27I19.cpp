#include <bits/stdc++.h>
using namespace std;
long long TC, N;
string S, T;
void solve() {
  cin >> S >> T;
  long long pre = -1;
  bool no = 0;
  for (long long i = 0; i <= long long(T.size() - 1); ++i) {
    long long cur = pre;
    while (1) {
      long long x = -1;
      for (long long j = cur + 1; j <= long long(S.size() - 1); ++j)
        if (S[j] == T[i]) {
          x = j;
          break;
        };
      if (x == -1) {
        no = 1;
        break;
      }
      cur = x;
      if ((x - pre) % 2 == 1) {
        pre = x;
        break;
      }
    }
    if ((S.size() - pre - 1) % 2 == 1) no = 1;
  }
  if (!no) {
    cout << "YES\n";
    return;
  }
  no = 0;
  pre = -1;
  for (long long i = 0; i <= long long(T.size() - 1); ++i) {
    long long cur = pre;
    while (1) {
      long long x = -1;
      for (long long j = cur + 1; j <= long long(S.size() - 1); ++j)
        if (S[j] == T[i]) {
          x = j;
          break;
        };
      if (x == -1) {
        no = 1;
        break;
      }
      cur = x;
      if (pre != -1 && (x - pre) % 2 == 1) {
        pre = x;
        break;
      }
      if (pre == -1 && (x - pre) % 2 == 0) {
        pre = x;
        break;
      }
    }
    if ((S.size() - pre - 1) % 2 == 1) no = 1;
  }
  if (!no) {
    cout << "YES\n";
    return;
  } else
    cout << "NO\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> TC;
  while (TC--) {
    solve();
  }
}
