#include <bits/stdc++.h>
constexpr bool testcase = true;
using namespace std;
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
struct HASH {
  size_t operator()(const pair<int, int>& x) const {
    size_t ans = 0;
    for (int i = 0; i < x.first; i++) ans += x.second;
    return ans;
  }
};
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<int, int>> vp(n + n, make_pair(0, 0));
  for (int i = 0; i < n; ++i) {
    int s;
    cin >> s;
    vp[i] = make_pair(s, i);
  }
  for (int i = 0; i < n; ++i) {
    int s;
    cin >> s;
    vp[i + n] = make_pair(s, i);
  }
  sort((vp).begin(), (vp).end());
  bool hitDouble = false;
  set<int> s1;
  vector<int> color(n, 0);
  vector<char> ans(n, '#');
  for (long long i = n + n - 1; i >= 0; --i) {
    auto p = vp[i];
    int idx = p.second;
    if (ans[idx] == '#') {
      bool win = true;
      if (hitDouble && ((int)(s1).size()) == 0) win = false;
      ans[idx] = win ? '1' : '0';
    }
    color[idx]++;
    if (color[idx] == 2) {
      s1.erase(idx);
      hitDouble = true;
    }
    if (color[idx] == 1 && hitDouble == false) {
      s1.insert(idx);
    }
  }
  for (auto c : ans) cout << c;
  cout << endl;
}
int main() {
  init_code();
  int tc = 1;
  if (testcase) std::cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
