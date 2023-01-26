#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
void solve() {
  long long n, k;
  cin >> n >> k;
  map<long long, long long> mp;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    mp[v[i]]++;
  }
  sort(v.rbegin(), v.rend());
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    ans += v[i + k] / v[i];
  }
  for (int i = 2 * k; i < n; i++) ans += v[i];
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
