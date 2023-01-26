#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using si = set<int>;
using msi = map<string, int>;
using minpq = priority_queue<int, vector<int>, greater<int>>;
void solve() {
  int n, q = 0, z = 0, cnt = 0, j = 0;
  string s = "#", x, ans = "";
  cin >> n >> x;
  ans = x;
  s += x;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '?') {
      z++;
    } else {
      if (s[i] == 'B') {
        if (z % 2 == 0) {
          while (j < z) {
            if (j % 2 == 0)
              ans[cnt + j++] = 'B';
            else
              ans[cnt + j++] = 'R';
          }
        } else {
          while (j < z) {
            if (j % 2 == 0)
              ans[cnt + j++] = 'R';
            else
              ans[cnt + j++] = 'B';
          }
        }
        ans[cnt + j++] = 'B';
      } else if (s[i] == 'R') {
        if (z % 2 == 0) {
          while (j < z) {
            if (j % 2 == 0)
              ans[cnt + j++] = 'R';
            else
              ans[cnt + j++] = 'B';
          }
        } else {
          while (j < z) {
            if (j % 2 == 0)
              ans[cnt + j++] = 'B';
            else
              ans[cnt + j++] = 'R';
          }
        }
        ans[cnt + j++] = 'R';
      }
      cnt += j;
      z = j = 0;
    }
  }
  if (z) {
    if (ans[cnt - 1] == 'R') {
      while (j < z) {
        if (j % 2 == 0)
          ans[cnt + j++] = 'B';
        else
          ans[cnt + j++] = 'R';
      }
    } else if (ans[cnt - 1] == 'B') {
      while (j < z) {
        if (j % 2 == 0)
          ans[cnt + j++] = 'R';
        else
          ans[cnt + j++] = 'B';
      }
    } else {
      while (j < z) {
        if (j % 2 == 0)
          ans[cnt + j++] = 'R';
        else
          ans[cnt + j++] = 'B';
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
