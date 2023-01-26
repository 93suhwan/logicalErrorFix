#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int MOD = 1e9 + 7;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;
const double eps = 1e-9;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n == 1 && s[0] == '?') {
    cout << 'B' << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      for (int j = i + 1; j < n; j++) {
        if (s[j] == 'R') {
          s[i] = 'B';
          break;
        } else if (s[j] == 'B') {
          s[i] = 'R';
          break;
        } else if (s[j] == '?')
          continue;
      }
      for (int j = i - 1; j >= 0; j--) {
        if (s[j] == 'R') {
          s[i] = 'B';
          break;
        } else if (s[j] == 'B') {
          s[i] = 'R';
          break;
        } else if (s[j] == '?')
          continue;
      }
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') ok = false;
  }
  if (!ok) {
    s[0] = 'B';
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        for (int j = i + 1; j < n; j++) {
          if (s[j] == 'R') {
            s[i] = 'B';
            break;
          } else if (s[j] == 'B') {
            s[i] = 'R';
            break;
          } else if (s[j] == '?')
            continue;
        }
        for (int j = i - 1; j >= 0; j--) {
          if (s[j] == 'R') {
            s[i] = 'B';
            break;
          } else if (s[j] == 'B') {
            s[i] = 'R';
            break;
          } else if (s[j] == '?')
            continue;
        }
      }
    }
  }
  cout << s << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  clock_t start, end;
  start = clock();
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cerr << "Exec Time:" << time_taken << "secs.\n";
}
