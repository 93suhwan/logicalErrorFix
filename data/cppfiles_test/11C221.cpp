#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const double eps = 1e-12;
const double PI = acos(-1.0);
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const long long nax = 5e5 + 5;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool isPowerOfTwo(long long int x) { return x && (!(x & (x - 1))); }
void solve() {
  long long int i, n, ans, k, m, j;
  cin >> n;
  vector<long long> balance[26];
  for (i = 0; i < n; i++) {
    string s;
    cin >> s;
    long long initial = -(long long int)s.size();
    for (j = 0; j < 26; j++) balance[j].push_back(initial);
    for (auto c : s) {
      balance[c - 'a'].back() += 2;
    }
  }
  ans = 0;
  long long best = 0;
  for (i = 0; i < 26; i++) {
    auto& tmp = balance[i];
    sort((tmp).begin(), (tmp).end());
    reverse((tmp).begin(), (tmp).end());
    if (tmp[0] <= 0) continue;
    long long int cnt = tmp[0];
    for (j = 1; j < n && cnt > 0; j++) cnt += tmp[j];
    if (cnt <= 0) j--;
    if (j > ans) {
      ans = j;
      best = i;
    }
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int t = 1, i;
  cin >> t;
  while (t--) solve();
  return 0;
}
