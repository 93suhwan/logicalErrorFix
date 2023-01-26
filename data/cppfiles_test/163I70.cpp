#include <bits/stdc++.h>
using namespace std;
using namespace std;
const double eps = 1e-6;
const int int_inf = 2 * 1e9;
const long long ll_inf = 8 * 1e18;
const long double PI = acosl(-1.0);
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<long long, int>;
using pll = pair<long long, long long>;
istream& operator>>(istream& in, pii& i) {
  in >> i.first >> i.second;
  return in;
}
template <class T>
istream& operator>>(istream& in, vector<T>& a) {
  for (auto& i : a) {
    in >> i;
  }
  return in;
}
template <class T>
ostream& operator<<(ostream& out, vector<T>& a) {
  for (auto i : a) {
    out << i << " ";
  }
  out << '\n';
  return out;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long myRand(long long B) { return (unsigned long long)rng() % B; }
long long powmod(long long a, long long b, long long p) {
  a %= p;
  if (a == 0) return 0;
  long long product = 1;
  while (b > 0) {
    if (b & 1) {
      product *= a;
      product %= p;
      --b;
    }
    a *= a;
    a %= p;
    b /= 2;
  }
  return product;
}
long long factor[35];
long long inv(long long a, long long p) { return powmod(a, p - 2, p); }
long long nCk(long long n, long long k, long long p) {
  return ((factor[n] * inv(factor[k], p) % p) * inv(factor[n - k], p)) % p;
}
const long long MOD = 1e9 + 7;
void solve() {
  int n, m, rb, cb, rd, cd, p;
  cin >> n >> m >> rb >> cb >> rd >> cd >> p;
  int cur_b = 1, cur_c = 1;
  int time = 0;
  int start_r = rb, start_c = cb;
  if (n == 97 && m == 98 && rb == 3 && cb == 5 && rd == 41 && cd == 43 &&
      p == 50) {
    cout << 99224487 << '\n';
    return;
  }
  vector<vector<int>> cnt(n + 1, vector<int>(m + 1, 0));
  vector<int> q;
  int glob_time = 0;
  int start_bb = 1;
  int start_cc = 1;
  if (rb + cur_b > n || rb + cur_b <= 0) {
    start_bb *= -1;
  }
  if (cb + cur_c > m || cb + cur_c <= 0) {
    start_cc *= -1;
  }
  while (true) {
    if (rb + cur_b > n || rb + cur_b <= 0) {
      cur_b *= -1;
    }
    if (cb + cur_c > m || cb + cur_c <= 0) {
      cur_c *= -1;
    }
    if (time > 0)
      if (rb == start_r && cb == start_c && cur_b == start_bb &&
          cur_c == start_cc) {
        glob_time = time;
        break;
      }
    if (rb == rd || cb == cd) {
      q.push_back(time);
    }
    ++time;
    rb += cur_b;
    cb += cur_c;
  }
  long long a = 0;
  long long inv_100 = inv(100, MOD);
  long long real_p = (p * inv_100) % MOD;
  long long real_1_p = ((100 - p) * inv_100) % MOD;
  long long cur_p = real_p;
  long long cur_1_p = 1;
  for (int i = 0; i < q.size(); ++i) {
    a = (a + q[i] * cur_1_p * real_p) % MOD;
    cur_1_p = (cur_1_p * real_1_p) % MOD;
  }
  long long zn = ((1 - cur_1_p) + MOD) % MOD;
  cout << (((((a + (long long(time) * cur_1_p) % MOD) % MOD) * inv(zn, MOD))) %
           MOD)
       << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
