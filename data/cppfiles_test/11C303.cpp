#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (T i : v) os << i << ' ';
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& v) {
  for (T i : v) os << i << ' ';
  return os;
}
template <class T, class S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << v.first << ' ' << v.second;
  return os;
}
template <class T, class S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' ';
  return os;
}
template <class T, class S>
ostream& operator<<(ostream& os, const unordered_map<T, S>& v) {
  for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' ';
  return os;
}
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const long long mod = 1e9 + 7;
long long takemod(long long a) { return ((a % mod) + mod) % mod; }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long fast_exp(long long base, long long expo) {
  long long res = 1;
  while (expo > 0) {
    if (expo & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    expo >>= 1;
  }
  return res;
}
long long modinv(long long a) { return takemod(fast_exp(takemod(a), mod - 2)); }
void solve() {
  long long n;
  cin >> n;
  vector<long long> v1[5];
  long long cntarr[5];
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    memset(cntarr, 0, sizeof(cntarr));
    for (long long j = 0; j < s.size(); j++) {
      cntarr[s[j] - 'a']++;
    }
    long long k = s.size();
    for (long long j = 0; j < 5; j++) {
      v1[j].push_back(cntarr[j] - (k - cntarr[j]));
    }
  }
  for (long long i = 0; i < 5; i++) {
    sort(v1[i].rbegin(), v1[i].rend());
  }
  long long ans = 0;
  for (long long i = 0; i < 5; i++) {
    long long currsum = 0, currcount = 0;
    for (long long j = 0; j < v1[i].size(); j++) {
      if (currsum + v1[i][j] > 0) {
        currsum += v1[i][j];
        currcount++;
      } else {
        break;
      }
    }
    ans = max(ans, currcount);
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1, l = 1;
  cin >> t;
  while (t--) {
    solve();
    l++;
  }
  return 0;
}
