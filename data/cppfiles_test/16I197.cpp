#include <bits/stdc++.h>
using namespace std;
pair<int, int> maxx(vector<pair<int, int> > v) {
  pair<int, int> p;
  int mx = INT_MIN;
  int ind = -1;
  for (int i = 0; i < v.size(); i++) {
    if ((v[i].first) > mx) {
      mx = v[i].first;
      ind = i;
    }
  }
  p.first = mx;
  p.second = ind;
  return p;
}
pair<int, int> minn(vector<pair<int, int> > v) {
  pair<int, int> p;
  int mx = INT_MAX;
  int ind = -1;
  for (int i = 0; i < v.size(); i++) {
    if ((v[i].first) < mx) {
      mx = v[i].first;
      ind = i;
    }
  }
  p.first = mx;
  p.second = ind;
  return p;
}
void solve() {
  int n;
  int ans = 0;
  cin >> n;
  string s;
  cin >> s;
  char a = s[0];
  for (int i = 1; i < n; i++) {
    if (a > s[i]) {
      ans++;
    }
    a = max(a, s[i]);
  }
  if (ans != 0)
    cout << ans + 1 << endl;
  else
    cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
