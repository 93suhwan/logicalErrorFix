#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000 * 1000 * 1000 + 7;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
bool sortinrev(long long x, long long y) { return x > y; }
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<string> v(n);
  map<string, long long> mp;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    for (long long j = 0; j < m; j++) {
      if (j & 1) {
        v[i][j] = 'Z' - v[i][j] + 'A';
      }
    }
    mp[v[i]] = i + 1;
  }
  sort((v).begin(), (v).end());
  for (auto x : v) cout << mp[x] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
