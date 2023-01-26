#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  map<int, vector<int> > m;
  map<int, vector<int> >::iterator it;
  cin >> n >> k;
  vector<int> a(n), z, c(n);
  for (long long i = 0; i < (n); i++) cin >> a[i];
  for (long long i = 0; i < (n); i++) {
    if (m[a[i]].size() < k) m[a[i]].push_back(i);
  }
  for (it = m.begin(); it != m.end(); it++)
    for (int i = 0; i < it->second.size(); i++) z.push_back(it->second[i]);
  int y = z.size();
  y = y - y % k;
  for (long long i = 0; i < (y); i++) c[z[i]] = i % k + 1;
  for (long long i = 0; i < (n); i++) cout << c[i] << ' ';
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long T = 1;
  cin >> T;
  for (long long t = 1; t <= T; t++) {
    solve();
  }
  return 0;
}
