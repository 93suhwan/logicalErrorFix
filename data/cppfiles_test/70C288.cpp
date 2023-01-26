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
  string s;
  cin >> s;
  long long n = s.size();
  long long i;
  string order;
  string tmp = s;
  reverse(s.begin(), s.end());
  map<char, int> hm;
  map<char, int> cnt;
  string res;
  i = 0;
  int len = 0;
  for (i = 0; i < n; i++) {
    cnt[s[i]]++;
    if (hm[s[i]] == 0) {
      len++;
      order += s[i];
      hm[s[i]] = len;
    }
  }
  reverse(order.begin(), order.end());
  long long flag = 1;
  long long ansLen = 0;
  for (i = 0; i < len; i++) {
    long long ttcnt = cnt[order[i]];
    if (ttcnt % (i + 1) != 0 || ttcnt < (i + 1)) {
      flag = 0;
      break;
    }
    ansLen += ttcnt / (i + 1);
  }
  if (!flag) {
    cout << -1 << "\n";
    return;
  }
  string ans = tmp.substr(0, ansLen);
  string str = ans;
  string verifyS;
  for (i = 0; i < len; i++) {
    verifyS += str;
    string temp;
    long long j;
    for (j = 0; j < str.size(); j++) {
      if (str[j] == order[i]) continue;
      temp += str[j];
    }
    str = temp;
  }
  if (verifyS != tmp) {
    cout << -1 << "\n";
    return;
  }
  cout << tmp.substr(0, ansLen) << " " << order << "\n";
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
