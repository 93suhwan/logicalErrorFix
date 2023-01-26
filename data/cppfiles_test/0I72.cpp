#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int a, b;
  cin >> a >> b;
  vector<pair<string, int>> v;
  for (int i = 1; i <= a; i++) {
    string s;
    cin >> s;
    v.push_back({s, i});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < a; i++) {
    string t = v[i].first;
    vector<pair<string, int>> s;
    s.push_back({t, v[i].second});
    while (i + 1 < a) {
      i++;
      string q = v[i].first;
      if (t[0] != q[0]) {
        i--;
        break;
      }
      s.push_back({q, v[i].second});
    }
    if (b % 2) {
      sort(s.begin(), s.end());
      for (auto &it : s) cout << it.second << " ";
    } else {
      sort(s.rbegin(), s.rend());
      for (auto &it : s) cout << it.second << " ";
    }
  }
  return 0;
}
