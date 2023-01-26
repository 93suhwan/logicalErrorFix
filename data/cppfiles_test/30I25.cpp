#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int n;
string s;
int palin(int h) {
  int u = 0;
  int v = n - 1;
  int kt = 1;
  while (u <= v) {
    if (s[u] != s[v]) {
      if (s[u] == h) {
        ++u;
        ++cnt;
      }
      if (s[v] == h) {
        --v;
        ++cnt;
      }
      if (s[u] == s[v]) {
        ++u;
        --v;
        continue;
      }
      kt = 0;
      break;
    } else {
      ++u;
      --v;
    }
  }
  return kt;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int o = 1; o <= t; ++o) {
    cin >> n;
    int ds = 2000000000;
    cin >> s;
    for (int i = 0; i <= 26; ++i) {
      cnt = 0;
      if (palin(i + 'a')) {
        ds = min(ds, cnt);
      }
    }
    if (ds == 2000000000)
      cout << -1 << "\n";
    else
      cout << ds << "\n";
  }
}
