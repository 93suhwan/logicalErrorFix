#include <bits/stdc++.h>
using namespace std;
const int mod = int(1e9) + 7;
const int inf = int(1e9) + 5;
void google(int t) { cout << "Case #" << t << ": "; }
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long int t) { cerr << t; }
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
  cerr << "]" << endl;
}
template <class T>
void _print(stack<T> v) {
  cerr << "[ ";
  while (!v.empty()) {
    _print(v.top());
    v.pop();
    cerr << " ";
  }
  cerr << "]" << endl;
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]" << endl;
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]" << endl;
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]" << endl;
}
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(stack<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
vector<int> ans;
void generate() {
  set<int> s;
  int i = 1, n = 1e9;
  while ((i * i) <= n) {
    i++;
    s.insert(i * i);
  }
  i = 1;
  while ((i * i * i) <= n) {
    i++;
    s.insert(i * i * i);
  }
  for (auto &x : s) {
    ans.push_back(x);
  }
}
void solve() {
  int n;
  cin >> n;
  int val = upper_bound(ans.begin(), ans.end(), n) - ans.begin();
  cout << val + 1 << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  generate();
  while (tc--) {
    solve();
  }
  return 0;
}
