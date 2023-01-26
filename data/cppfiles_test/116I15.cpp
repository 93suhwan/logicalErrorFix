#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vi = vector<int>;
using vl = vector<ll>;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 998244353;
int n;
ll a[500005];
ll binExp(ll b, ll e) {
  if (e < 0) return 0;
  ll res = 1;
  while (e) {
    if (e & 1) res = res * b % MOD;
    b = b * b % MOD;
    e >>= 1;
  }
  return res;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  vl cndseq(n + 5, 0);
  map<int, ll> cnt;
  for (int i = 0; i < n; i++) cnt[a[i]]++;
  ll ans = (binExp(2, cnt[1]) - 1 + MOD) % MOD;
  for (int i = 0; i < n; i++) {
    if (!a[i]) {
      cndseq[0] = (cndseq[0] * 2 + 1) % MOD;
    } else {
      cndseq[a[i]] = (cndseq[a[i]] * 2 + cndseq[a[i] - 1]) % MOD;
    }
    if (a[i] >= 2) {
      ans += (binExp(2, cnt[a[i]]) - 1 + MOD) * (cndseq[a[i] - 2] % MOD);
      ans %= MOD;
    }
    if (a[i] >= 1) {
      ans += (binExp(2, cnt[a[i] - 1]) - 1 + MOD) * (cndseq[a[i]] % MOD);
      ans %= MOD;
    }
    cnt[a[i]]--;
  }
  for (int i = 0; i <= n; i++) (ans += cndseq[i]) %= MOD;
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
