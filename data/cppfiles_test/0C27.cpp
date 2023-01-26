#include <bits/stdc++.h>
using namespace std;
long long n, m;
bool cmp(string a, string b) {
  for (long long i = 0; i < m; i++) {
    if (i % 2 == 0) {
      if (a[i] != b[i]) return a[i] < b[i];
    } else {
      if (a[i] != b[i]) return a[i] > b[i];
    }
  }
  return a < b;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  map<string, long long> p;
  vector<string> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    p[v[i]] = i + 1;
  }
  sort(v.begin(), v.end(), cmp);
  for (long long i = 0; i < n; i++) {
    cout << p[v[i]] << " ";
  }
}
