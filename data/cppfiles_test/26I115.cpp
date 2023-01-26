#include <bits/stdc++.h>
using namespace std;
string s1, s2;
bool dfs(string s1, string s2, int a, int b, int c) {
  if (c == 0) {
    if (b == s2.size()) {
      return true;
    } else if (a == s1.size()) {
      return dfs(s1, s2, a - 2, b, 1);
    } else if (s1[a] == s2[b]) {
      return dfs(s1, s2, a + 1, b + 1, 0) || dfs(s1, s2, a - 1, b + 1, 1);
    } else {
      return dfs(s1, s2, a - 1, b, 1);
    }
  } else {
    if (b == s2.size()) {
      return true;
    } else if (a == -1) {
      return false;
    } else if (s1[a] != s2[b]) {
      return false;
    } else {
      return dfs(s1, s2, a - 1, b + 1, 1);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> s1 >> s2;
    int t = 1;
    for (int i = 0; i < s1.size() && t; i++) {
      if (dfs(s1, s2, i, 0, 0)) {
        cout << "YES" << endl;
        t = 0;
      }
    }
    if (t) {
      cout << "NO" << endl;
    }
  }
}
