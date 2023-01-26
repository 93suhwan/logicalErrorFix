#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long inf = 1e18;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
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
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long dx[] = {-1, 0, 1, 0};
long long dy[] = {0, -1, 0, 1};
void swap(long long &a, long long &b);
long long m_m(long long a, long long b, long long m);
long long fxp(long long a, long long b, long long m);
long long msum(long long a, long long b, long long m);
long long msub(long long a, long long b, long long m);
long long mpro(long long a, long long b, long long m);
void solve() {
  string s, t;
  cin >> s >> t;
  long long n = s.size();
  long long i;
  sort(s.begin(), s.end());
  vector<bool> isPresent(3, false);
  string res;
  string temp;
  for (i = 0; i < n; i++) {
    if (s[i] == t[0])
      isPresent[0] = true;
    else if (s[i] == t[1])
      isPresent[1] = true;
    else if (s[i] == t[2])
      isPresent[2] = true;
    if (s[i] == t[1]) {
      temp += s[i];
    } else
      res += s[i];
  }
  long long cnt = 0;
  for (i = 0; i < 3; i++)
    if (isPresent[i]) cnt++;
  if (cnt < 3) {
    cout << s << "\n";
    return;
  }
  string ans = res + temp;
  ;
  ;
  for (i = res.size() - 1; i >= 0; i--) {
    if (res[i] == t[2]) {
      string val;
      if (i + 1 < res.size()) val = res.substr(i + 1, res.size() - i - 1);
      ans = res.substr(0, i + 1) + temp + val;
      break;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  freopen("Error.txt", "w", stderr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
long long fxp(long long a, long long b, long long m) {
  if (b == 0) return 1;
  if (b % 2 == 0) return fxp((a * a) % m, b / 2, m);
  return (fxp(a, b - 1, m) * a) % m;
}
long long m_m(long long a, long long b, long long m) {
  long long res = 0;
  a = a % m;
  while (b) {
    if (b & 1) {
      res += a;
      res = res % m;
    }
    a = (a * 2) % m;
    b = b / 2;
  }
  return res;
}
void swap(long long &a, long long &b) {
  long long t = a;
  a = b;
  b = t;
}
long long msum(long long a, long long b, long long m) {
  return ((a % m + b % m) + m) % m;
}
long long msub(long long a, long long b, long long m) {
  return ((a % m - b % m) + m) % m;
}
long long mpro(long long a, long long b, long long m) {
  return (((a % m) * (b % m) + m)) % m;
}
