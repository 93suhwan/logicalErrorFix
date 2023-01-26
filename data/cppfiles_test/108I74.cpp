#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, i, a, b, c;
  vector<pair<long long int, long long int> > v1, v2;
  vector<long long int> v3, v4;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    v3.push_back(a);
    v1.push_back(make_pair(a, i));
  }
  for (i = 0; i < n; i++) {
    cin >> a;
    v4.push_back(a);
    v2.push_back(make_pair(a, i));
  }
  sort(v1.rbegin(), v1.rend());
  sort(v2.rbegin(), v2.rend());
  b = 0;
  c = 0;
  map<int, int> m;
  for (i = 0; i < n; i++) {
    a = v1[i].second;
    if (v1[i].first > c) {
      m[a] = 1;
    }
    a = v2[i].second;
    if (v2[i].first > b) {
      m[a] = 1;
    }
    c = v3[a];
    b = v4[v1[i].second];
  }
  for (i = 0; i < n; i++) {
    if (m[i] == 1) {
      cout << 1;
    } else
      cout << 0;
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
