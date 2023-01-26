#include <bits/stdc++.h>
using namespace std;
int main() {
  string f = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> v;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (j % 2 == 0) {
        continue;
      }
      s[j] = f[s[j] - 'A'];
    }
    v.push_back({s, i});
  }
  sort(v.begin(), v.end());
  for (auto it : v) {
    cout << it.second << " ";
  }
  return 0;
}
