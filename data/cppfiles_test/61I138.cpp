#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string s, t[2];
  cin >> n >> s;
  for (int i = 0; i < (int)(2); i++) {
    t[i] = s;
    for (int j = 0; j < (int)(n); j++)
      if (s[j] == '?') t[i][j] = "BR"[(j + i) & 1];
  }
  auto f = [&](string &s) {
    int cnt = 0;
    for (int i = 0; i < (int)(n - 1); i++) cnt += (s[i] == s[i + 1]);
    return cnt;
  };
  cout << (f(t[0]) < f(t[1]) ? t[0] : t[1]) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int tn;
  cin >> tn;
  while (tn--) solve();
}
