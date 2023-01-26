#include <bits/stdc++.h>
using namespace std;
void __print(long long x) { cerr << x; }
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
  long long f = 0;
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
vector<long long> factorise(long long x) {
  vector<long long> v;
  for (long long i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      v.push_back(i);
      if (i * i != x) v.push_back(x / i);
    }
  }
  return v;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x %= p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long nCk(long long x, long long k) {
  long long num = 1;
  for (long long i = 0; i < k; i++) {
    num *= (x - i) % 1000000007;
    num %= 1000000007;
  }
  long long den = 1;
  for (long long i = 1; i <= k; i++) {
    den *= i % 1000000007;
    den %= 1000000007;
  }
  return (num * power(den, 1000000007 - 2, 1000000007)) % 1000000007;
}
template <typename T>
bool is_palindrome(T v, long long n) {
  bool bl = true;
  for (long long i = 0; i < n / 2; i++) {
    if (v[i] != v[n - i - 1]) {
      bl = false;
      break;
    }
  }
  return bl;
}
bool cmp(vector<long long> &a, vector<long long> &b) {
  if (a[0] < b[0])
    return true;
  else if (a[0] > b[0])
    return false;
  else {
    if (a[1] - a[0] < b[1] - b[0]) return true;
    return false;
  }
  return false;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test;
  cin >> test;
  long long te = 0;
  while (test--) {
    te++;
    long long n, k, x;
    cin >> n >> k >> x;
    vector<long long> v;
    v.push_back(1);
    string s;
    cin >> s;
    long long t = 0;
    for (long long i = n - 1; i >= 0; i--) {
      if (s[i] == '*') {
        t++;
      } else if (t) {
        if (v[v.size() - 1] > x / (t * k + 1))
          v.push_back(LLONG_MAX);
        else
          v.push_back(1ll * (t * k + 1) * v[v.size() - 1]);
        t = 0;
      }
    }
    if (t) {
      if (v[v.size() - 1] > x / (t * k + 1))
        v.push_back(LLONG_MAX);
      else
        v.push_back(1ll * (t * k + 1) * v[v.size() - 1]);
    };
    long long i = v.size() - 2;
    long long j = 0;
    x--;
    while (j < s.length()) {
      while (j < s.length() && s[j] != '*') {
        cout << s[j];
        j++;
      }
      if (j < s.length() && s[j] == '*') {
        long long temp = x / v[i];
        x = x % v[i];
        ;
        cout << string(temp, 'b');
        i--;
      }
      while (j < s.length() && s[j] == '*') j++;
    }
    cout << "\n";
  }
  return 0;
}
