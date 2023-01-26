#include <bits/stdc++.h>
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
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
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <class T>
void re(T &x) {
  cin >> x;
}
template <class T>
void read(vector<T> &a) {
  for (auto &x : a) re(x);
}
const long long INF = 1010000000;
struct segment {
  int a, id;
};
struct segment2 {
  int s, e;
};
bool operator<(segment a, segment b) { return a.a > b.a; }
bool Prime(string t) {
  int x = (t[0] - '0') * 10 + t[1] - '0';
  if (x % 2 == 0) return false;
  for (int i = 3; i * i <= x; i += 2) {
    if (x % i == 0) return false;
  }
  return true;
}
int changchar(char s) {
  if (s == '0') {
    return 0;
  }
  if (s == '1') {
    return 1;
  }
  if (s == '2') {
    return 2;
  }
  if (s == '3') {
    return 3;
  }
  if (s == '4') {
    return 4;
  }
  if (s == '5') {
    return 5;
  }
  if (s == '6') {
    return 6;
  }
  if (s == '7') {
    return 7;
  }
  if (s == '8') {
    return 8;
  }
  if (s == '9') {
    return 9;
  }
  return 0;
}
bool isPalindrome(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != s[s.length() - 1 - i]) {
      return 0;
    }
  }
  return 1;
}
const long long inf = 1e18;
string solve1(string n) {
  string res(n.length(), '9');
  for (char c = '8'; c >= '0'; c--) {
    string t(n.length(), c);
    if (t >= n) res = t;
  }
  return res;
}
string solve2(string n) {
  string res = solve1(n);
  for (char a = '0'; a <= '9'; a++)
    for (char b = a + 1; b <= '9'; b++) {
      bool n_ok = true;
      for (int i = 0; i < n.length(); i++) {
        if (n[i] < b) {
          string t = n;
          if (t[i] < a)
            t[i] = a;
          else
            t[i] = b;
          for (int j = i + 1; j < n.length(); j++) t[j] = a;
          if (res > t) res = t;
        }
        if (n[i] != a && n[i] != b) {
          n_ok = false;
          break;
        }
      }
      if (n_ok) return n;
    }
  return res;
}
string solve() {
  string n;
  int k;
  cin >> n >> k;
  if (k == 1)
    return solve1(n);
  else
    return solve2(n);
}
void HUY() {
  int n;
  cin >> n;
  vector<int> v1(n);
  read(v1);
  sort(v1.begin(), v1.end());
  int k = count(v1.begin(), v1.end(), v1.back());
  int kk = count(v1.begin(), v1.end(), v1.back() - 1);
  long long ans = 1;
  long long ans2 = 1;
  const long long mod = 998244353;
  for (int i = 1; i <= n; i++) {
    ans *= i;
    ans %= mod;
    if (i != kk + 1) {
      ans2 *= i;
      ans2 %= mod;
    }
  }
  cout << (k >= 2 ? ans : (ans - ans2 + mod) % mod) << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    HUY();
  }
  return 0;
}
