#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(vector<T> a) {
  int n = a.size();
  for (long long i = 0; i < n; ++i) {
    cout << a[i] << (i == n - 1 ? "\n" : " ");
  }
}
int sum_vector(vector<int> v) { return accumulate(v.begin(), v.end(), 0); }
void sort_vector(vector<int> &v) { sort(v.begin(), v.end()); }
void sort_comp(vector<int> &v, bool func(int, int)) {
  sort(v.begin(), v.end(), func);
}
bool comp0(array<long long, 4> a, array<long long, 4> b) {
  if (a[0] == b[0]) {
    return a[1] < b[1];
  }
  return a[0] < b[0];
}
bool comp1(array<long long, 4> a, array<long long, 4> b) {
  if (a[1] == b[1]) {
    return a[0] < b[0];
  }
  return a[1] < b[1];
}
struct CustomCompare {
  bool operator()(pair<int, int> lhs, pair<int, int> rhs) {
    return lhs.first > rhs.first;
  }
};
long long gcd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  while (a) {
    long long temp = a;
    a = b % a;
    b = temp;
  }
  return abs(b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
string binary(long long num) {
  string ans = "";
  do {
    ans = to_string(num % 2) + ans;
    num /= 2;
  } while (num);
  return ans;
}
const int mxn = 5e5 + 7;
const int d = 18;
const int mill = 1e6 + 3;
const long long mod = 1e9 + 7;
long long pwr(long long num, long long p) {
  num %= mod;
  num += mod;
  num %= mod;
  long long res = 1;
  while (p > 0) {
    if (p & 1) res = (res * num) % mod;
    num = (num * num) % mod;
    p /= 2;
  }
  return res;
}
long long inverse(long long num) { return pwr(num, mod - 2); }
long long get_rand(long long n) { return ((rand() << 15) + rand()) % n; }
void solve() {
  long long n, m, orb, ocb, rd, cd, p;
  cin >> n >> m >> orb >> ocb >> rd >> cd >> p;
  long long rb = orb;
  long long cb = ocb;
  long long ans = 0;
  long long vx = 1;
  long long vy = 1;
  long long tim = 0;
  vector<long long> v;
  if (rb + vx > n || rb + vx <= 0) {
    vx = -vx;
  }
  if (cb + vy > m || cb + vy <= 0) {
    vy = -vy;
  }
  long long ovx = vx;
  long long ovy = vy;
  do {
    if (rb == rd || cb == cd) {
      if (v.size() == 0 || v.back() != tim) v.push_back(tim);
    }
    tim++;
    if (rb + vx <= n && rb + vx > 0) {
      rb += vx;
    }
    if (cb + vy <= m && cb + vy > 0) {
      cb += vy;
    }
    if (rb + vx > n || rb + vx <= 0) {
      vx = -vx;
    }
    if (cb + vy > m || cb + vy <= 0) {
      vy = -vy;
    }
  } while (rb != orb || cb != ocb || vx != ovx || vy != ovy);
  long long tims = v.size();
  long long a, b, c, d;
  for (int i = 0; i < tims; i++) {
    a = p * inverse(100);
    b = v[i] * pwr((100 - p) * inverse(100), i);
    c = pwr(100, tims) * inverse(pwr(100, tims) - (pwr(100 - p, tims)));
    a %= mod;
    b %= mod;
    c %= mod;
    d = ((((a * b) % mod) * c) % mod);
    ans += d;
    ans %= mod;
    a = p * inverse(100);
    b = tim * pwr((100 - p) * inverse(100), tims + i);
    c = pwr(pwr(100, tims) * inverse(pwr(100, tims) - pwr(100 - p, tims)), 2);
    a %= mod;
    b %= mod;
    c %= mod;
    d = ((((a * b) % mod) * c) % mod);
    ans += d;
    ans %= mod;
  }
  ans += mod;
  ans %= mod;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  cin >> t;
  for (int ii = 1; ii <= t; ii++) {
    solve();
  }
  return 0;
}
