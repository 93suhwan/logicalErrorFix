#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = 1;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
    first = 0;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using db = double;
using ldb = long double;
const int maxn = 300000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    auto cal = [&](int x, int d) {
      x++;
      int N = 1 << (d + 1);
      int c = x / N;
      int res = x % N >= N / 2 ? N / 2 : x % N;
      res += c * (N / 2) - 1;
      return res;
    };
    int l, r;
    scanf("%d%d", &l, &r);
    int ans = inf;
    for (auto i = 0; i <= 20; i++) chmin(ans, cal(r, i) - cal(l - 1, i));
    printf("%d\n", ans);
  }
  return 0;
}
