#include <bits/stdc++.h>
using namespace std;
void oggy() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &it : v) cin >> it;
  string s;
  cin >> s;
  int z = 0, o = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '0') {
      z++;
    } else {
      o++;
    }
  }
  if (z == 0 || o == 0) {
    for (auto it : v) cout << it << " ";
    return;
  }
  vector<pair<int, int>> p1, p2;
  int j = 0, k = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      j++;
      p1.push_back({v[i], j});
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      j++;
      p2.push_back({v[i], j});
    }
  }
  sort(p1.begin(), p1.end());
  sort(p2.begin(), p2.end());
  int g = 0, d = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      cout << p1[g].second << " ";
      g++;
    }
    if (s[i] == '1') {
      cout << p2[d].second << " ";
      d++;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    oggy();
    cout << "\n";
  }
  return 0;
}
