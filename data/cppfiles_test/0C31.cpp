#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s;
  vector<pair<string, int>> vp;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < s.length(); j++) {
      if (j & 1) {
        s[j] = 90 - (s[j]) + 65;
      }
    }
    vp.push_back(make_pair(s, i + 1));
  }
  sort(vp.begin(), vp.end());
  for (int i = 0; i < n; i++) {
    cout << vp[i].second << " ";
  }
  return 0;
}
