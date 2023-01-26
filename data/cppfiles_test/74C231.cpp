#include <bits/stdc++.h>
using namespace std;
long long bin_pow(long long base, long long deg, long long md) {
  if (!deg) return 1;
  if (deg % 2) return base * bin_pow(base, deg - 1, md) % md;
  long long res = bin_pow(base, deg / 2, md);
  return res * res % md;
}
template <typename T1, typename T2>
bool cmin(T1& a, const T2& b) {
  if (a <= b) return false;
  a = b;
  return true;
}
template <typename T1, typename T2>
bool cmax(T1& a, const T2& b) {
  if (a >= b) return false;
  a = b;
  return true;
}
mt19937 rnd(0);
long long get_rand_int(long long mn, long long mx) {
  return rnd() % (mx - mn + 1) + mn;
}
const long long md = 1e9 + 7;
long long inv(long long a) { return bin_pow(a, md - 2, md); }
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long get_bit(long long m, long long index) {
  return bool((m >> index) & 1ll);
}
long long get_fact(long long n) {
  if (n == 0) return 1;
  return n * get_fact(n - 1) % md;
}
long long get_c(long long n, long long k) {
  return get_fact(n) / get_fact(k) / get_fact(n - k);
}
void debug_assert(bool a) { assert(a); }
set<long long> result;
bool is_correct(long long num, long long max) { return num >= 0 && num <= max; }
void solve(long long a, long long b) {
  long long first_play = (a + b + 1) / 2;
  long long first_get = a + b - first_play;
  for (long long x = 0; x <= first_get; ++x) {
    long long first_get_lost = first_get - x;
    long long first_play_win = a - x;
    long long first_play_lost = first_play - first_play_win;
    if (!is_correct(x, a) || !is_correct(first_play_win, a) ||
        !is_correct(first_get_lost, b) || !is_correct(first_play_lost, b))
      continue;
    long long res = x + first_play_lost;
    if (res == 4) res = 4;
    result.insert(x + first_play_lost);
  }
}
void run() {
  long long a, b;
  cin >> a >> b;
  solve(a, b);
  solve(b, a);
  cout << long long(result.size()) << '\n';
  for (auto u : result) {
    cout << u << ' ';
  }
  cout << '\n';
  result.clear();
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; ++i) {
    run();
  }
}
