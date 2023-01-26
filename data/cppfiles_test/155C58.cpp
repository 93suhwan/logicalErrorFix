#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long n, i, j, m;
  cin >> n;
  vector<long long> v(n), v1(n);
  string s;
  vector<pair<long long, long long> > zero, one;
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  cin >> s;
  for (i = 0; i < n; i++) {
    if (s[i] == '0') {
      zero.push_back({v[i], i});
    } else {
      one.push_back({v[i], i});
    }
  }
  sort(zero.begin(), zero.end());
  sort(one.begin(), one.end());
  long long p = 1;
  for (i = 0; i < zero.size(); i++) v1[zero[i].second] = p++;
  for (i = 0; i < one.size(); i++) v1[one[i].second] = p++;
  for (i = 0; i < n; i++) cout << v1[i] << " ";
  cout << '\n';
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
