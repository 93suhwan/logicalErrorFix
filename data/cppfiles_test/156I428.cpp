#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
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
const long long int MOD = 1e9 + 7;
const long long int INF = 1e18;
const long long int maxn = 1e6 + 4;
long long int binpow(long long int b, long long int n, long long int mod) {
  long long int res = 1;
  while (n) {
    if (n & 1) res = res * b % mod;
    n /= 2;
    b = b * b % mod;
  }
  return res;
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort((v).begin(), (v).end());
  long long int sum = accumulate((v).begin(), (v).end(), 0LL);
  ;
  vector<long long int> suff(n, 0);
  suff[n - 1] = v[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suff[i] = v[i] + suff[i + 1];
  }
  long long int cnt = maxn;
  for (int i = n - 1; i > 1; i--) {
    long long int temp = suff[i] + v[0];
    long long int cont = n - i + 1;
    long long int rem = sum - temp - k;
    long long int reach = ceil(rem / cont);
    if (rem % cont) reach++;
    cnt = min(cnt, (abs(v[0] + reach) + cont - 1));
  }
  if (cnt == maxn) {
    if (sum <= k) {
      cout << "0\n";
      return;
    } else {
      cout << abs(v[0] - k) << "\n";
      return;
    }
  }
  cout << cnt << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
