#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 1e18 + 10;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  unordered_map<long long, vector<long long> > m;
  long long tot = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]].push_back(i);
  }
  vector<long long> paint(n, -1);
  long long p = 1;
  for (auto x : m) {
    vector<long long> temp = x.second;
    long long cursz = temp.size();
    tot += min(k, cursz);
  }
  tot /= k;
  tot = (tot * k);
  for (auto x : m) {
    vector<long long> temp = x.second;
    long long cursz = temp.size();
    long long N = min(cursz, k);
    for (long long i = 0; i < N && tot > 0; i++) {
      paint[temp[i]] = p % k;
      p++;
      tot--;
    }
  }
  for (auto x : paint) cout << x + 1 << " ";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(15);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
