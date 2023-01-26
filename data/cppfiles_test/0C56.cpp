#include <bits/stdc++.h>
using namespace std;
ifstream fi(
    "easy"
    ".inp");
ofstream fo(
    "easy"
    ".out");
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s;
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    s.push_back(x);
  }
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    string tmp = "";
    for (int j = 0; j < m; j++) {
      tmp += (j & 1 ? ('Z' - s[i][j]) : (s[i][j] - 'A')) + 'A';
    }
    a[i] = tmp;
  }
  vector<pair<string, int>> mp;
  for (int i = 0; i < n; i++) {
    mp.push_back({a[i], i});
  }
  sort((mp).begin(), (mp).end());
  for (int i = 0; i < n; i++) {
    cout << mp[i].second + 1 << " ";
  }
}
