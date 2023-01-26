#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const long long N = 2e5 + 5;
void solve() {
  long long n;
  cin >> n;
  long long a[n][5];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < 5; j++) cin >> a[i][j];
  vector<pair<long long, long long> > ch(n);
  map<long long, long long> m;
  for (long long i = 0; i < n; i++) {
    long long sum = 0;
    for (long long j = 0; j < 5; j++) {
      sum += a[i][j];
    }
    ch[i].first = sum;
    ch[i].second = i;
  }
  sort((ch).begin(), (ch).end());
  if (n >= 10) n = 10;
  for (long long i = 0; i < n; i++) {
    long long x = ch[i].second;
    map<long long, long long> mp;
    for (long long j = 0; j < 5; j++) {
      long long v = a[x][j];
      for (long long k = 0; k < n; k++) {
        if (v < a[ch[k].second][j]) mp[k]++;
      }
    }
    long long cnt = 0;
    for (long long j = 0; j < n; j++) {
      if (mp[ch[j].second] >= 3) cnt++;
    }
    if (cnt == n - 1) {
      cout << x + 1 << endl;
      return;
    }
  }
  cout << -1 << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
