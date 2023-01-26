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
    string st;
    st += to_string(n) + "*" + to_string(k) + "*" + to_string(x) + "*";
    string s;
    cin >> s;
    st += s;
    if (te == 48) cout << st << "\n";
    long long t = 0;
    vector<string> val;
    for (long long i = n - 1; i >= 0; i--) {
      if (s[i] == '*') {
        t++;
      } else if (t) {
        val.push_back("");
        val.push_back("a");
        v.push_back(t * k + 1);
        t = 0;
      } else
        val.push_back("a");
    }
    if (t) {
      val.push_back("");
      v.push_back(t * k + 1);
    }
    n = v.size();
    x--;
    if (x == 0) {
      for (long long i = val.size() - 1; i >= 0; i--) cout << val[i];
      cout << "\n";
      continue;
    }
    vector<long long> vt;
    vt.push_back(1);
    for (long long i = 1; i <= n; i++) {
      vt.push_back(vt[i - 1] * v[i - 1]);
    }
    n = vt.size() - 2;
    vector<long long> ans;
    while (true) {
      ans.push_back(x / vt[n]);
      x = x % vt[n];
      n--;
      if (x == 0 && n == -1) break;
    };
    ;
    long long j = ans.size() - 1;
    for (long long i = 0; i < val.size() && j >= 0;) {
      while (val[i].length() != 0) {
        i++;
      }
      string sts = "";
      ;
      while (ans[j]) {
        sts += "b";
        ans[j]--;
      }
      j--;
      val[i] = sts;
    }
    for (long long i = val.size() - 1; i >= 0; i--) cout << val[i];
    cout << "\n";
  }
  return 0;
}
