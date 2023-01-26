#include <bits/stdc++.h>
using namespace std;
void cnt_pref(vector<int> &a) {
  for (int i = 1; i < a.size(); ++i) a[i] = a[i - 1] + a[i];
}
void solve(void) {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<string> tp = {"abc", "acb", "bac", "bca", "cab", "cba"};
  vector<int> nota0(n + 1, 0), nota1(n + 1, 0), nota2(n + 1, 0);
  vector<int> notb0(n + 1, 0), notb1(n + 1, 0), notb2(n + 1, 0);
  vector<int> notc0(n + 1, 0), notc1(n + 1, 0), notc2(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    if (s[i] != 'a') {
      if (i % 3 == 0) ++nota0[i + 1];
      if (i % 3 == 1) ++nota1[i + 1];
      if (i % 3 == 2) ++nota2[i + 1];
    }
    if (s[i] != 'b') {
      if (i % 3 == 0) ++notb0[i + 1];
      if (i % 3 == 1) ++notb1[i + 1];
      if (i % 3 == 2) ++notb2[i + 1];
    }
    if (s[i] != 'c') {
      if (i % 3 == 0) ++notc0[i + 1];
      if (i % 3 == 1) ++notc1[i + 1];
      if (i % 3 == 2) ++notc2[i + 1];
    }
  }
  cnt_pref(nota0);
  cnt_pref(nota1);
  cnt_pref(nota2);
  cnt_pref(notb0);
  cnt_pref(notb1);
  cnt_pref(notb2);
  cnt_pref(notc0);
  cnt_pref(notc1);
  cnt_pref(notc2);
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    if (r - l == 0) cout << "0\n";
    if (r - l == 1)
      cout << (s[l] == s[r]) << '\n';
    else {
      int ans = n;
      for (string str : tp) {
        int ansnw = 0;
        if (str[0] == 'a') {
          if (l % 3 == 0) ansnw += nota0[r + 1] - nota0[l];
          if (l % 3 == 1) ansnw += nota1[r + 1] - nota1[l];
          if (l % 3 == 2) ansnw += nota2[r + 1] - nota2[l];
        }
        if (str[0] == 'b') {
          if (l % 3 == 0) ansnw += notb0[r + 1] - notb0[l];
          if (l % 3 == 1) ansnw += notb1[r + 1] - notb1[l];
          if (l % 3 == 2) ansnw += notb2[r + 1] - notb2[l];
        }
        if (str[0] == 'c') {
          if (l % 3 == 0) ansnw += notc0[r + 1] - notc0[l];
          if (l % 3 == 1) ansnw += notc1[r + 1] - notc1[l];
          if (l % 3 == 2) ansnw += notc2[r + 1] - notc2[l];
        }
        if (str[1] == 'a') {
          if ((l + 1) % 3 == 0) ansnw += nota0[r + 1] - nota0[l];
          if ((l + 1) % 3 == 1) ansnw += nota1[r + 1] - nota1[l];
          if ((l + 1) % 3 == 2) ansnw += nota2[r + 1] - nota2[l];
        }
        if (str[1] == 'b') {
          if ((l + 1) % 3 == 0) ansnw += notb0[r + 1] - notb0[l];
          if ((l + 1) % 3 == 1) ansnw += notb1[r + 1] - notb1[l];
          if ((l + 1) % 3 == 2) ansnw += notb2[r + 1] - notb2[l];
        }
        if (str[1] == 'c') {
          if ((l + 1) % 3 == 0) ansnw += notc0[r + 1] - notc0[l];
          if ((l + 1) % 3 == 1) ansnw += notc1[r + 1] - notc1[l];
          if ((l + 1) % 3 == 2) ansnw += notc2[r + 1] - notc2[l];
        }
        if (str[2] == 'a') {
          if ((l + 2) % 3 == 0) ansnw += nota0[r + 1] - nota0[l];
          if ((l + 2) % 3 == 1) ansnw += nota1[r + 1] - nota1[l];
          if ((l + 2) % 3 == 2) ansnw += nota2[r + 1] - nota2[l];
        }
        if (str[2] == 'b') {
          if ((l + 2) % 3 == 0) ansnw += notb0[r + 1] - notb0[l];
          if ((l + 2) % 3 == 1) ansnw += notb1[r + 1] - notb1[l];
          if ((l + 2) % 3 == 2) ansnw += notb2[r + 1] - notb2[l];
        }
        if (str[2] == 'c') {
          if ((l + 2) % 3 == 0) ansnw += notc0[r + 1] - notc0[l];
          if ((l + 2) % 3 == 1) ansnw += notc1[r + 1] - notc1[l];
          if ((l + 2) % 3 == 2) ansnw += notc2[r + 1] - notc2[l];
        }
        ans = min(ans, ansnw);
      }
      cout << ans << '\n';
    }
  }
}
int main(void) {
  cout << fixed << setprecision(20);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  srand(time(NULL));
  while (t--) solve();
  return 0;
}
