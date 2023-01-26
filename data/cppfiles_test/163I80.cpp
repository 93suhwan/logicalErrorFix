#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(time(nullptr));
void __print(int first) { cerr << first; }
void __print(long first) { cerr << first; }
void __print(long long first) { cerr << first; }
void __print(unsigned first) { cerr << first; }
void __print(unsigned long first) { cerr << first; }
void __print(unsigned long long first) { cerr << first; }
void __print(float first) { cerr << first; }
void __print(double first) { cerr << first; }
void __print(long double first) { cerr << first; }
void __print(char first) { cerr << '\'' << first << '\''; }
void __print(const char *first) { cerr << '\"' << first << '\"'; }
void __print(const string &first) { cerr << '\"' << first << '\"'; }
void __print(bool first) { cerr << (first ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &first) {
  cerr << '{';
  __print(first.first);
  cerr << ", ";
  __print(first.second);
  cerr << '}';
}
template <typename T>
void __print(const T &first) {
  int f = 0;
  cerr << '{';
  for (auto &i : first) cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long long mod = 1e9 + 7;
long long ppow(long long first, long long second) {
  long long res = 1;
  while (second) {
    if (second & 1) res = res * first % mod;
    first = first * first % mod;
    second >>= 1LL;
  }
  return res;
}
void solve() {
  int n, m;
  cin >> n >> m;
  int x1, y1;
  cin >> x1 >> y1;
  int x2, y2;
  cin >> x2 >> y2;
  int d1 = 1, d2 = 1;
  long long p;
  cin >> p;
  long long P = (1 - p * ppow(100, mod - 2) + mod) % mod;
  set<pair<pair<int, int>, pair<int, int>>> st;
  vector<pair<pair<int, int>, pair<int, int>>> states;
  states.push_back({{x1, y1}, {d1, d1}});
  while (true) {
    if (x1 + d1 < 1 || x1 + d1 > n) {
      d1 = -d1;
      continue;
    }
    if (y1 + d2 < 1 || y1 + d2 > m) {
      d2 = -d2;
      continue;
    }
    x1 += d1, y1 += d2;
    auto cur = make_pair(make_pair(x1, y1), make_pair(d1, d2));
    if (st.find(cur) != st.end()) break;
    states.push_back(cur);
    st.insert(cur);
  }
  auto last = make_pair(make_pair(x1, y1), make_pair(d1, d2));
  long long ind = 0;
  long long prob = 1;
  long long ans = 0;
  for (ind = 0; ind < states.size(); ++ind) {
    if (states[ind] == last) break;
    if (states[ind].first.first == x2 || states[ind].first.second == y2) {
      ans += ind * prob % mod * p % mod, ans %= mod;
      prob *= P, prob %= mod;
    }
  }
  long long cur_prob = 1;
  long long ans_cyc = 0;
  for (long long i = ind; i < states.size(); ++i) {
    if (states[ind].first.first == x2 || states[ind].first.second == y2) {
      ans_cyc += (i - ind) * cur_prob % mod * p % mod, ans_cyc %= mod;
      cur_prob *= P, cur_prob %= mod;
    }
  }
  ans_cyc += cur_prob * (long long)states.size() % mod, ans_cyc %= mod;
  cout << cur_prob * (long long)states.size() % mod << " "
       << ppow((1 - cur_prob + mod) % mod, mod - 2) << " ";
  ans_cyc *= ppow((1 - cur_prob + mod) % mod, mod - 2), ans_cyc %= mod;
  cout << ans_cyc << " ";
  ans += ans_cyc, ans %= mod;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
