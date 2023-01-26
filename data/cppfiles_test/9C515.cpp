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
  string a;
  cin >> a;
  long long n = (long long)((a).size());
  long long k = 2;
  vector<long long> f(26 + 1);
  vector<long long> diff(n + 2);
  vector<vector<long long>> occ(26 + 1);
  vector<long long> pr(n);
  long long rem = n;
  for (long long i = 0; i < n; i++) {
    a[i] -= 'a' - 1;
    f[a[i]]++;
    occ[a[i]].push_back(i);
  }
  for (long long i = 1; i < 26 + 1; i++) {
    diff[0]++;
    diff[f[i] + 1]--;
  }
  long long push_front = 0;
  long long ans = 0;
  long long num;
  for (long long i = 1; i < k + 1; i++) {
    diff[i] += diff[i - 1];
    push_front += diff[i];
    long long tmp = push_front / i * i;
    if (i == k) {
      ans = tmp;
      num = i;
    }
  }
  long long e = ans / num;
  long long cnt = 0;
  for (long long i = 1; i < 26 + 1; i++) {
    for (long long j = 0; j < min(num, f[i]); j++) {
      long long x = occ[i][j];
      pr[x] = ++cnt;
      if (cnt == num) {
        cnt = 0;
        e--;
        if (e == 0) break;
      }
    }
    if (e == 0) break;
  }
  cout << ans / 2;
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
