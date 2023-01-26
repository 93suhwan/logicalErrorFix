#include <bits/stdc++.h>
using namespace std;
void solve() {
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
  int result = n;
  for (int i = n - 1; i >= 0; i--) {
    if (s[v[i].second] == '1') {
      v[i].first = result;
      result--;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[v[i].second] == '0') {
      v[i].first = result;
      result--;
    }
  }
  for (int i = n - 1; i >= 0; i--) swap(v[i].first, v[i].second);
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    cout << v[i].second << " ";
  }
  cout << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
