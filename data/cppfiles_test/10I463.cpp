#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  map<int, vector<int> > m;
  map<int, vector<int> >::iterator it;
  vector<int> a(n), c(n);
  for (long long i = 0; i < (n); i++) {
    cin >> a[i];
    m[a[i]].push_back(i);
  }
  long long cnt = 0;
  for (it = m.begin(); it != m.end(); it++) {
    vector<int> b = it->second;
    if (b.size() >= k) {
      for (long long j = 0; j < (k); j++) c[b[j]] = j + 1;
    } else {
      for (long long j = 0; j < (b.size()); j++) c[b[j]] = j + 1;
    }
  }
  for (long long i = 0; i < (n); i++) cout << c[i] << ' ';
  cout << '\n';
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
