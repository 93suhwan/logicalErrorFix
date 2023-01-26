#include <bits/stdc++.h>
using namespace std;
void oggy() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i;
  }
  string s;
  cin >> s;
  sort(v.begin(), v.end());
  int y = n;
  for (int i = n - 1; i >= 0; i--) {
    if (s[v[i].second] == '1') {
      v[i].first = y;
      y--;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[v[i].second] == '0') {
      v[i].first = y;
      y--;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    swap(v[i].first, v[i].second);
  }
  sort(v.begin(), v.end());
  for (auto it : v) cout << it.second << " ";
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
