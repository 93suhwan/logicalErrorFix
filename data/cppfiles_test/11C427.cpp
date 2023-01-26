#include <bits/stdc++.h>
using namespace std;
void input() { return; }
template <typename T1, typename... T2>
void input(T1& x, T2&... args) {
  ((cin >> x), input(args...));
}
void wrt() {
  cout << "\n";
  return;
}
template <typename T1, typename... T2>
void wrt(T1 x, T2... args) {
  ((cout << x << ' '), wrt(args...));
}
template <typename T>
void inputlst(T& lst, int x, int y) {
  for (int i = x; i < y; i++) cin >> lst[i];
}
template <typename T>
void printlst(T& lst, int x, int y) {
  for (int i = x; i < y; i++) cout << lst[i] << ' ';
  wrt();
}
void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(double t) { cout << t; }
void _print(long long int t) { cout << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cout << "{";
  _print(p.first);
  cout << ",";
  _print(p.second);
  cout << "}";
}
template <class T>
void _print(vector<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(set<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(multiset<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cout << "[ ";
  for (auto i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
const int MOD = 1000000007;
long long gcd(long long a, long long b) {
  return (b == 0) ? (a) : (gcd(b, a %= b));
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long _sum(vector<int> a) { return accumulate(a.begin(), a.end(), 0ll); }
long long _add(long long x, long long y) {
  x %= MOD, y %= MOD;
  return (x + y) % MOD;
}
long long _sub(long long x, long long y) {
  x %= MOD, y %= MOD;
  return (x - y + MOD) % MOD;
}
long long _mul(long long x, long long y) {
  x %= MOD, y %= MOD;
  return (x * 1ll * y) % MOD;
}
long long _pow(long long x, long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0) {
    long long _tmp = _pow(x, y / 2);
    return _mul(_tmp, _tmp);
  } else
    return _mul(x, _pow(x, y - 1));
}
long long _inv(long long p) { return _pow(p, MOD - 2); }
long long _div(long long x, long long y) {
  x %= MOD, y %= MOD;
  return _mul(x, _inv(y));
}
long long _nCr(long long n, long long r, vector<long long>& fact) {
  return _mul(fact[n], _inv(_mul(fact[r], fact[n - r])));
}
const int L = 26;
vector<int> balance[L];
long long i = 0;
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < L; i++) balance[i].clear();
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int initBalance = -(int)s.length();
    for (int j = 0; j < L; j++) balance[j].push_back(initBalance);
    for (auto c : s) balance[c - 'a'].back() += 2;
  }
  int bestCount = 0;
  int bestLetter = 0;
  for (int i = 0; i < L; i++) {
    auto& b = balance[i];
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    if (b[0] <= 0) continue;
    int sumBalance = b[0];
    int j = 1;
    for (; j < n && sumBalance > 0; j++) sumBalance += b[j];
    if (sumBalance <= 0) j--;
    if (j > bestCount) {
      bestCount = j;
      bestLetter = i;
    }
  };
  ;
  cout << bestCount << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
