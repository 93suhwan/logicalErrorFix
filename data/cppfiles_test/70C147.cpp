#include <bits/stdc++.h>
using namespace std;
template <class Num>
Num mabs(Num x) {
  if (x < 0) return -x;
  return x;
}
int get(int n, int c, int a, int b, vector<vector<int>> &suf) {
  int ret = suf[a][c];
  if (b < n - 1) {
    ret -= suf[b + 1][c];
  }
  return ret;
}
void solve() {
  int n;
  string str;
  cin >> str;
  n = (int)str.length();
  vector<vector<int>> suf(n + 1, vector<int>(26, 0));
  for (int i = n - 1; i >= 0; i--) {
    int s = (int)(str[i] - 'a');
    suf[i][s]++;
    if (i < n - 1)
      for (int j = (0); j < (26); j++) suf[i][j] += suf[i + 1][j];
  }
  string remove = "";
  for (int i = 0; i < n; i++) {
    int s = (int)(str[i] - 'a');
    if (suf[i + 1][s] == 0) {
      remove += str[i];
    }
  }
  int len = 0;
  int ans = -1;
  vector<int> cnt(26, 0);
  for (int i = 0; i < n; i++) {
    len = i + 1;
    int x = (int)(str[i] - 'a');
    cnt[x]++;
    bool ok = true;
    vector<int> cnt2 = cnt;
    int pos = i + 1;
    for (char c : remove) {
      int s = (int)(c - 'a');
      if (cnt2[s] == 0) {
        ok = false;
        break;
      }
      len -= cnt2[s];
      cnt2[s] = 0;
      int a = pos, b = pos + len - 1;
      if (b >= n) {
        ok = false;
        break;
      }
      for (int j = (0); j < (26); j++) {
        int y = get(n, j, a, b, suf);
        if (cnt2[j] != y) {
          ok = false;
          break;
        }
      }
      if (!ok) break;
      pos = b + 1;
    }
    if (pos == n && ok) {
      ans = i;
      break;
    }
  }
  if (ans == -1) {
    cout << -1 << endl;
    return;
  }
  string s = "";
  for (int i = (0); i < (ans + 1); i++) {
    s += str[i];
  }
  int pt = 0;
  int m = (int)s.length();
  bool ok = true;
  int i = 0;
  string ns = s;
  vector<bool> skip(26, false);
  while (true) {
    m = (int)ns.length();
    for (int j = 0; j < m; j++) {
      if (str[i] != ns[j]) {
        ok = false;
        break;
      }
      i++;
    }
    if (!ok) break;
    if (i == n) {
      break;
    };
    if (pt == (int)remove.size()) break;
    int cur = (int)(remove[pt] - 'a');
    skip[cur] = true;
    pt++;
    string tt = "";
    for (int j = (0); j < (m); j++) {
      int sl = (int)(ns[j] - 'a');
      if (!skip[sl]) tt += ns[j];
    }
    ns = tt;
    cur++;
  }
  if (!ok) {
    cout << -1 << endl;
    return;
  }
  cout << s << " " << remove << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
