#include <bits/stdc++.h>
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
template <typename T>
void Print(T a[], T n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
const long long int N = 5005;
const long long int M = 998244353;
long long int fact[N], inv[N];
long long int power(long long int a, long long int b, long long int M) {
  long long int ans = 1;
  while (b) {
    if (b % 2 != 0) {
      ans *= a;
    }
    ans %= M;
    a *= a;
    a %= M;
    b /= 2;
  }
  return ans;
}
void fun() {
  fact[0] = 1;
  inv[0] = 1;
  for (long long int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= M;
    inv[i] = power(fact[i], M - 2, M);
  }
}
long long int ncr(long long int n, long long int r) {
  long long int ans = fact[n] * inv[r];
  ans %= M;
  ans *= inv[n - r];
  return ans % M;
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (count(s.begin(), s.end(), '1') < k) {
    cout << 1 << "\n";
    return;
  }
  if (k == 0) {
    cout << 1 << "\n";
    return;
  }
  long long int z = 0, o = 0;
  long long int ans = 0;
  long long int flag = 0;
  long long int overlap[n];
  fill(overlap, overlap + n, 0);
  long long int j = 0;
  for (long long int i = 0; i < n; i++) {
    z += s[i] == '0';
    o += s[i] == '1';
    if (o > k) {
      while (o > k && j < i) {
        o -= s[j] == '1';
        z -= s[j] == '0';
        j++;
      }
    }
    if (o == k && z > 0) {
      if (overlap[j] == 1) {
        if (s[i] == '0') {
          ans += ncr(o + z - 1, z);
          ans %= M;
        } else {
          ans += ncr(o + z - 1, o);
          ans %= M;
        }
        fill(overlap + j, overlap + i + 1, 1);
        continue;
      }
      fill(overlap + j, overlap + i + 1, 1);
      if (flag == 0)
        ans += ncr(z + o, o), flag = 1;
      else
        ans += ncr(z + o, o) - 1;
      ans %= M;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  fun();
  solve();
}
