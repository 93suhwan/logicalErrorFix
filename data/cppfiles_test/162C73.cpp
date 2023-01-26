#include <bits/stdc++.h>
using namespace std;
using std::ofstream;
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
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
long long P = 998244353;
ofstream out;
ifstream in;
const long long N = 2e5 + 5;
long long factorialNumInverse[N + 1];
long long naturalNumInverse[N + 1];
long long fact[N + 1];
void InverseofNumber(long long p) {
  naturalNumInverse[0] = naturalNumInverse[1] = 1;
  for (long long i = 2; i <= N; i++)
    naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(long long p) {
  factorialNumInverse[0] = factorialNumInverse[1] = 1;
  for (long long i = 2; i <= N; i++)
    factorialNumInverse[i] =
        (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(long long p) {
  fact[0] = 1;
  for (long long i = 1; i <= N; i++) {
    fact[i] = (fact[i - 1] * i) % p;
  }
}
long long Binomial(long long N, long long R, long long p) {
  long long ans =
      ((fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R]) % p;
  return ans;
}
long long func(vector<long long>& v, long long idx, long long k) {
  long long r = v.size() - 1;
  long long l = idx;
  long long m;
  while (l < r) {
    m = (l + r) / 2 + 1;
    long long sm = v[m];
    if (idx > 0) sm -= v[idx - 1];
    if (sm <= k)
      l = m;
    else
      r = m - 1;
  }
  long long sm = v[r];
  if (idx > 0) sm -= v[idx - 1];
  if (sm == k)
    return r;
  else
    return -1;
}
void solve1() {
  long long n, m, rb, cb, rd, cd;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  long long ans = 0;
  long long dr = 1;
  long long dc = 1;
  while (1) {
    ;
    ;
    if (rb == rd || cb == cd) {
      break;
    }
    long long x = rb + dr;
    long long y = cb + dc;
    if (x > n || x < 1) dr = -dr;
    if (y > m || y < 1) dc = -dc;
    x = rb + dr;
    y = cb + dc;
    rb = x;
    cb = y;
    ans++;
  }
  cout << ans << "\n";
  ;
}
void func(vector<priority_queue<long long>>& v, long long l) {
  if (l >= v.size()) return;
  if (v[l].size() == 0) return;
  auto i = v[l].top();
  v[l].pop();
  if (v[l].size() == 0) {
    cout << l << " " << i << " " << l << "\n";
    func(v, l + 1);
    return;
  }
  auto j = v[l].top();
  ;
  cout << l << " " << i << " " << j + 1 << "\n";
  func(v, l);
  func(v, j + 2);
}
void solve2() {
  long long n;
  cin >> n;
  vector<priority_queue<long long>> v(n + 1);
  for (long long i = 0; i < n; i++) {
    long long l, r;
    cin >> l >> r;
    v[l].push(r);
  }
  func(v, 1);
}
bool func(vector<long long>& v, long long m) {
  long long n = v.size();
  vector<long long> temp(n, 0);
  for (long long i = n - 1; i >= 0; i--) {
    if (temp[i] + v[i] < m) return false;
    if (i <= 1) continue;
    long long l1 = min(temp[i] + v[i] - m, v[i]);
    long long x = l1 / 3;
    temp[i - 2] += 2 * x;
    temp[i - 1] += x;
  }
  return true;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long l = 0;
  long long r = 1e9;
  long long m;
  while (l < r) {
    m = (l + r) / 2 + 1;
    if (func(v, m)) {
      l = m;
    } else
      r = m - 1;
  }
  cout << r << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc = 1;
  cin >> tc;
  for (long long t1 = 1; t1 <= tc; t1++) {
    solve();
  }
}
