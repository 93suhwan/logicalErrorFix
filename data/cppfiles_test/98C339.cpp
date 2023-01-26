#include <bits/stdc++.h>
using namespace std;
void __print(long long int x) { cerr << x; }
void __print(long x) { cerr << x; }
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
  long long int f = 0;
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
const long long int MAX_N = 1e5 + 1;
const long long int MOD = 1e9 + 7;
const long long int INF = 1e9;
const long long LINF = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct tdata {
  long long int val, pri, sz;
  tdata *ln, *rn;
  tdata(long long int val) : val(val), pri(rng()), sz(1), ln(), rn() {}
};
long long int sz(tdata *node) { return node ? node->sz : 0; }
void propagate(tdata *node) {
  if (!node) return;
}
void combine(tdata *node) {
  if (!node) return;
  propagate(node->ln);
  propagate(node->rn);
  node->sz = sz(node->ln) + sz(node->rn) + 1;
}
void heapify(tdata *node) {
  if (!node) return;
  auto mx = node;
  if (node->ln && node->ln->pri > node->pri) mx = node;
  if (node->rn && node->rn->pri > node->pri) mx = node;
  if (node != mx) {
    swap(node->pri, mx->pri);
    heapify(mx);
  }
}
tdata *build(vector<long long int> &arr, long long int start,
             long long int end) {
  if (start > end) return NULL;
  long long int mid = (start + end) / 2;
  auto node = new tdata(arr[mid]);
  node->ln = build(arr, start, mid - 1);
  node->rn = build(arr, mid + 1, end);
  heapify(node);
  combine(node);
  return node;
}
void split(tdata *node, tdata *&ln, tdata *&rn, long long int k) {
  propagate(node);
  if (!node) {
    ln = rn = NULL;
    return;
  }
  if (sz(node->ln) >= k)
    split(node->ln, ln, node->ln, k), rn = node;
  else
    split(node->rn, node->rn, rn, k - sz(node->ln) - 1), ln = node;
  combine(node);
}
void merge(tdata *&node, tdata *ln, tdata *rn) {
  propagate(ln);
  propagate(rn);
  if (!ln || !rn) {
    node = ln ? ln : rn;
    return;
  }
  if (ln->pri > rn->pri)
    merge(ln->rn, ln->rn, rn), node = ln;
  else
    merge(rn->ln, ln, rn->ln), node = rn;
  combine(node);
}
void print(tdata *node) {
  if (!node) return;
  print(node->ln);
  cout << node->val << " ";
  print(node->rn);
}
const long long int N = 300500;
long long int fact[N];
long long int invFact[N];
long long int C(long long int n, long long int r) {
  long long int ans = 1;
  if (r > n - r) r = n - r;
  for (long long int i = 1; i <= r; i++) {
    ans *= (n - i + 1), ans /= i;
  }
  return ans;
}
bool prime[10000007];
void SieveOfEratosthenes() {
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= 10000007; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= 10000007; i += p) prime[i] = false;
    }
  }
}
long long int modfnc(long long int x) {
  return ((x % 1000000007 + 1000000007) % 1000000007);
}
long long int add(long long int a, long long int b) {
  return modfnc(modfnc(a) + modfnc(b));
}
long long int mul(long long int a, long long int b) {
  return modfnc(modfnc(a) * modfnc(b));
}
long long int fast_pow(long long int a, long long int p, long long int m) {
  long long int res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = (a * a) % m;
      p /= 2;
    } else {
      res = (res * a) % m;
      p--;
    }
  }
  return res;
}
void Call_For_nCr() {
  fact[0] = invFact[0] = 1;
  for (long long int i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
    invFact[i] = fast_pow(fact[i], 1000000007 - 2, 1000000007);
  }
}
long long int nCR(long long int n, long long int k, long long int m) {
  if (k > n) {
    return 0;
  }
  return fact[n] * invFact[k] % m * invFact[n - k] % m;
}
void solve(long long int testcase) {
  string s1, s2;
  long long int ans = 0;
  cin >> s1 >> s2;
  map<char, long long int> mp;
  for (long long int i = 0; i < s1.length(); i++) mp[s1[i]] = i;
  for (long long int i = 1; i < s2.length(); i++) {
    ans += abs(mp[s2[i]] - mp[s2[i - 1]]);
  }
  cout << ans << "\n";
}
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
signed main() {
  init_code();
  long long int t = 1, i = 1;
  cin >> t;
  while (t--) {
    solve(i);
    i++;
  }
  return 0;
}
