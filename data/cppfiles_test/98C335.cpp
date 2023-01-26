#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long M = 1e9 + 7;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
bool isprime(long long n) {
  if (n == 2) return true;
  if (n % 2 == 0 || n == 1) return false;
  for (long long j = 3; j <= sqrt(n); j += 2) {
    if (n % j == 0) return false;
  }
  return true;
}
vector<bool> prime_num(1e5 + 10, 1);
vector<long long> lp(1e5 + 10, 0), hp(1e5 + 10, 0);
void prime_upto_n(long long n, vector<bool> &prime_num) {
  prime_num[0] = prime_num[1] = false;
  for (long long i = 2; i < (long long)n; ++i) {
    if (prime_num[i] && (long long)i * i <= n) {
      lp[i] = hp[i] = i;
      for (long long j = 2 * i; j < n; j += i) {
        prime_num[j] = false;
        hp[j] = i;
        if (lp[j] == 0) lp[j] = i;
      }
    }
  }
}
long long mins(long long a, long long b) {
  if (a > b) return b;
  return a;
}
long long maxs(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long power_it(long long a, long long b) {
  a %= M;
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * 1ll * a) % M;
    a = (a * a * 1ll) % M, b >>= 1;
  }
  return ans;
}
const long long N = 1e3 + 10;
long long arr[N], seg[4 * N];
void build(long long ind, long long low, long long high) {
  long long mid = low + (high - low) / 2;
  if (low == high) {
    seg[ind] = arr[low];
    return;
  }
  build(2 * ind + 1, low, mid), build(2 * ind + 2, mid + 1, high);
  seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}
long long query(long long ind, long long low, long long high, long long l,
                long long r) {
  if (low >= l and high <= r) return seg[ind];
  if (high < l || low > r) {
    return INT_MIN;
  }
  long long mid = low + (high - low) / 2,
            left = query(2 * ind + 1, low, mid, l, r),
            right = query(2 * ind + 2, mid + 1, high, l, r);
  return max({left, right});
}
void update(long long ind, long long low, long long high, long long node,
            long long val) {
  if (low == high) {
    seg[ind] += val, arr[node] += val;
  } else {
    long long mid = low + (high - low) >> 1;
    if (node <= mid and node >= low)
      update(2 * ind + 1, low, high, node, val);
    else
      update(2 * ind + 2, mid + 1, high, node, val);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
  }
}
void z_func(string s) {
  long long n = s.length();
  long long z[n];
  z[0] = 0;
  for (long long i = 1, l = 0, r = 1; i < n; i++, r = i < r ? r : i)
    for (z[i] = min(r - i, z[i - l]); s[i + z[i]] == s[z[i]];
         z[i]++, r = i + z[i], l = i)
      ;
  for (long long i = 0; i < (long long)n; ++i) cout << z[i] << " ";
}
vector<long long> fact;
void fact_func(vector<long long> &fact, long long n) {
  fact.push_back(1);
  for (long long i = 1; i < (long long)n; ++i) {
    fact.push_back(fact[i - 1] * i);
  }
}
void solve() {
  string s, t;
  cin >> s >> t;
  unordered_map<char, long long> mp;
  long long ans = 0;
  for (long long i = 0; i < (long long)s.size(); ++i) {
    mp[s[i]] = i;
  }
  for (long long i = 0; i < (long long)t.size() - 1; ++i) {
    ans += abs(mp[t[i]] - mp[t[i + 1]]);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  ;
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  long long temp = t;
  while (t--) {
    solve();
  }
  return 0;
}
