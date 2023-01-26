#include <bits/stdc++.h>
using namespace std;
const long long maxN = 1e6 + 7;
const long long maxM = 5e5;
const long long mod = 1e9 + 7;
long long di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
long long dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
template <typename T>
ostream& operator<<(ostream& cout, vector<T> res) {
  for (long long i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return cout;
}
template <typename T>
istream& operator>>(istream& cin, vector<T>& input) {
  for (long long i = 0; i < input.size(); i++) {
    cin >> input[i];
  }
  return cin;
}
vector<bool> isPrime(maxN, true);
vector<long long> primes;
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1LL;
  }
  return res;
}
void seive() {
  for (long long i = 2; i * i <= maxN; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
      for (long long j = i * i; j < maxN; j += i) isPrime[j] = false;
    }
  }
}
void solve() {
  string s, t;
  cin >> s >> t;
  long long sz = s.size();
  long long tz = t.size();
  vector<long long> inds;
  for (long long i = 0; i < sz; ++i) {
    if (s[i] == t[0]) {
      inds.push_back(i);
    }
  }
  long long e = -1, o = -1;
  for (long long start : inds) {
    if (o == -1 and start & 1) o = start;
    if (e == -1 and start % 2 == 0) e = start;
  }
  if (e != -1) {
    long long j = 0;
    while (j < tz and e < sz) {
      if (s[e] == t[j]) {
        e++;
        j++;
      } else {
        e += 2;
      }
    }
    if (j == tz and ((sz - e) % 2 == 0)) {
      cout << "YES\n";
      return;
    }
  }
  if (o != -1) {
    long long j = 0;
    while (j < tz and o < sz) {
      if (s[o] == t[j]) {
        o++;
        j++;
      } else {
        o += 2;
      }
    }
    if (j == tz and ((sz - o) % 2 == 0)) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long testCase = 1;
  cin >> testCase;
  while (testCase--) {
    solve();
  }
  return 0;
}
