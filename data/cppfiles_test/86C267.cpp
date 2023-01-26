#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1;
  cin >> s2;
  int mex = 0;
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      mex += 2;
      continue;
    }
    if (i == n - 1) {
      if (s1[i] == '0') mex++;
      break;
    }
    if (s1[i] == s2[i]) {
      if (s1[i + 1] == s2[i + 1] && s1[i] != s1[i + 1]) {
        mex += 2;
        i++;
        continue;
      }
      if (s1[i + 1] == s2[i + 1] && s1[i] == s1[i + 1]) {
        if (s1[i] == '0') mex += 1;
      }
      if (s1[i + 1] != s2[i + 1] && s1[i] == '0') mex++;
    }
  }
  cout << mex << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
