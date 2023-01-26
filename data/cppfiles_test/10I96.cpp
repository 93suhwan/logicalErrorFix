#include <bits/stdc++.h>
using namespace std;
long long solve();
vector<long long> a;
string s;
long long n;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
long long in(vector<long long> &a, long long n) {
  long long i = 0, x, sum = 0;
  for (i = 0; i < n; i++) {
    cin >> x;
    a.push_back({x});
  }
  return sum;
}
long long expow(long long val, long long p) {
  if (p == 0) return 1;
  if (p == 1) return val;
  if (p & 1) return (val * expow((val * val) % 1000000007, p / 2)) % 1000000007;
  return expow((val * val) % 1000000007, p / 2) % 1000000007;
}
long long solve() {
  a.clear();
  s.clear();
  long long i = 0, j = 0, k = 0;
  long long flag = 0;
  long long x = 0, y = 0, z = 0;
  cin >> n;
  long long m;
  cin >> m;
  cin >> k;
  long long r, c;
  cin >> r >> c;
  pair<long long, long long> fir, sec;
  cin >> fir.first >> fir.second;
  cin >> sec.first >> sec.second;
  long long totalpts = (n * m - r * c) % 1000000007;
  cout << expow(k, totalpts) << "\n";
  return 0;
}
