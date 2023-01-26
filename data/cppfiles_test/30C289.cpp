#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
const int M = 1e9 + 7;
long long power(long long x, long long y) {
  long long v = 1;
  while (y > 0) {
    if (y & 1) v = v * x;
    y = y >> 1;
    x = x * x;
  }
  return v;
}
bool isPowerOfTwo(long long x) { return x && (!(x & (x - 1))); }
long long ceil(long long a, long long b) { return (a + b - 1) / b; }
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
void init() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = INT_MAX;
  for (char i = 'a'; i <= 'z'; i++) {
    int left = 0;
    int right = n - 1;
    int cnt = 0;
    bool check = true;
    while (left < right) {
      if (s[left] == s[right]) {
        left++;
        right--;
        continue;
      }
      if (s[left] == i) {
        left++;
        cnt++;
        continue;
      }
      if (s[right] == i) {
        right--;
        cnt++;
        continue;
      }
      check = false;
      break;
    }
    if (check) ans = min(ans, cnt);
  }
  cout << (ans == INT_MAX ? -1 : ans) << "\n";
}
int main() {
  init();
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
