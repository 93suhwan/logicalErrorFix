#include <bits/stdc++.h>
using namespace std;
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) long long idx,
               __attribute__((unused)) long long LINE_NUM) {
  cerr << '\n';
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, long long idx, long long LINE_NUM, Head H,
               Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
void run() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
}
const long long N = 100 + 5, mod = 1e9 + 7, mod2 = 998244353, MAXN = 1e6 + 29;
void files() {}
long long k = 30;
long long bb(long long x) {
  return log2(x) + 1;
  k--;
}
long long rev(long long x) {
  long long bts = bb(x) - 1;
  long long xx = 0;
  while (bts >= 0) {
    if (x & 1) {
      xx |= (1LL << bts);
    }
    k--;
    bts--;
    x >>= 1;
  }
  return xx;
}
long long one(long long x) {
  long long bts = bb(x);
  if (bts == 63) return -1;
  x *= 2;
  x++;
  k--;
  return rev(x);
}
long long zero(long long x) {
  while (!(x & 1LL)) x >>= 1;
  long long bts = bb(x);
  if (bts == 63) return -1;
  x *= 2;
  k--;
  return rev(x);
}
bool solve(long long x, long long y) {
  k--;
  if (k == 0) {
    cout << "NO" << '\n';
    exit(0);
  }
  if (x == y) {
    cout << "YES" << '\n';
    exit(0);
  }
  long long a = one(x);
  if ((~a) || a < 0) solve(a, y);
  long long b = zero(x);
  if ((~b) || b < 0) solve(b, y);
  return false;
}
signed main() {
  files();
  run();
  long long x, y;
  cin >> x >> y;
  if (x == y) return cout << "YES", 0;
  k = 1e5;
  string xx;
  for (long long i = 0; i < 64; ++i) {
    xx.push_back(bool((1LL << i) & x) + '0');
  }
  string yy;
  for (long long i = 0; i < 64; ++i) {
    yy.push_back(bool((1LL << i) & y) + '0');
  }
  long long z = 0, tt = y;
  while (!(tt & 1)) {
    tt++;
    tt >>= 1;
  }
  while (xx.back() == '0') xx.pop_back();
  long long z1 = 0, z2 = 0;
  while (y) {
    z2 += (y % 2 == 0);
    y >>= 1;
  }
  while (x) {
    z1 += (x % 2 == 0);
    x >>= 1;
  }
  if (z > 0 || z1 != z2) return cout << "NO", 0;
  if (yy.find(xx) != yy.npos) {
    cout << "YES" << '\n';
    return 0;
  }
  reverse(((xx).begin()), ((xx).end()));
  if (yy.find(xx) != yy.npos) {
    cout << "YES" << '\n';
    return 0;
  }
  cout << "NO";
  return 0;
}
