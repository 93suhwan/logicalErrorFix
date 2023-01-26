#include <bits/stdc++.h>
using namespace std;
template <class t, class u>
bool chmax(t& a, u b) {
  if (a < b) {
    a = b;
    return true;
  } else
    return false;
}
template <class t, class u>
bool chmin(t& a, u b) {
  if (b < a) {
    a = b;
    return true;
  } else
    return false;
}
template <class t>
using vc = vector<t>;
template <class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.fi << "," << p.sc << "}";
}
template <class t>
ostream& operator<<(ostream& os, const vc<t>& v) {
  os << "{";
  for (auto e : v) os << e << ",";
  return os << "}";
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
  size_t operator()(pair<int, int> x) const {
    return operator()(uint64_t(x.first) << 32 | x.second);
  }
};
void solve3rd() {
  long long n, k, cnt = 0;
  cin >> n >> k;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] % k == 0) cnt++;
  }
  cout << cnt;
}
void solve4th() {
  long long n, m, rb, cb, rd, cd, res = 0, X = 1, Y = 1;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  bool flag = true;
  while (flag == true) {
    if (rd == rb or cd == cb) break;
    if (cb + Y < 1 or cb + Y > m) Y = Y * (-1);
    if (rb + X < 1 or rb + X > n) X = X * (-1);
    res = res + 1;
    cb = cb + Y;
    rb = rb + X;
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve4th();
    cin.clear();
    cout.clear();
  }
  return 0;
}
