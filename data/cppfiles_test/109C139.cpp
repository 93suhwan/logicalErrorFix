#include <bits/stdc++.h>
using namespace std;
using pi = pair<long long, long long>;
using vi = vector<long long>;
using vvi = vector<vector<long long> >;
template <typename T, typename Y>
istream& operator>>(istream& is, pair<T, Y>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename Y>
ostream& operator<<(ostream& os, pair<T, Y> p) {
  os << p.first << ' ' << p.second << ' ';
  return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
const long long NUM = 1000030;
const long long N = 10000000;
vector<long long> lp, sieve;
vector<long long> pr;
void primefactor();
long long binpow(long long a, long long b);
long long binpow(long long a, long long b, long long mod);
long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
bool comp(long long a, long long b);
long long inversemod(long long a, long long mod);
void calc_sieve();
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  long long n;
  cin >> n;
  long long t = 0;
  long long sum = 0;
  string str;
  cin >> str;
  for (long long i = 0; i < n; i++) {
    sum += (str[i] - '0');
    if (i == n - 1 && str[i] != '0') t--;
    if (str[i] != '0') t++;
  }
  cout << (sum + t) << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
