#include <bits/stdc++.h>
using namespace std;
const long long int huge = 1e18;
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int abbs(long long int a, long long int b) {
  if (a - b < 0) return b - a;
  return a - b;
}
void _pr(long long int t) { cerr << t; }
void _pr(string t) { cerr << t; }
void _pr(char t) { cerr << t; }
void _pr(long double t) { cerr << t; }
void _pr(double t) { cerr << t; }
void _pr(unsigned long long t) { cerr << t; }
template <class T, class V>
void _pr(pair<T, V> p);
template <class T>
void _pr(vector<T> v);
template <class T>
void _pr(set<T> v);
template <class T, class V>
void _pr(map<T, V> v);
template <class T>
void _pr(multiset<T> v);
template <class T, class V>
void _pr(pair<T, V> p) {
  cerr << "{";
  _pr(p.first);
  cerr << ",";
  _pr(p.second);
  cerr << "}";
}
template <class T>
void _pr(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _pr(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _pr(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _pr(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _pr(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _pr(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _pr(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _pr(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _pr(queue<T> q) {
  cerr << "[ ";
  while (!q.empty()) {
    cerr << q.front() << " ";
    q.pop();
  }
  cerr << "]";
}
template <class T>
void _pr(stack<T> s) {
  cerr << "[ ";
  while (!s.empty()) {
    cerr << s.top() << " ";
    s.pop();
  }
  cerr << "]";
};
void solve() {
  long long int n;
  cin >> n;
  vector<string> v;
  for (long long int i = 0; i < n - 2; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  string ans = v[0];
  bool f = 0;
  for (long long int i = 1; i < v.size(); i++) {
    if (v[i][0] == v[i - 1][1]) {
      ans += v[i][1];
    } else {
      f = 1;
      ans += v[i];
    }
  }
  if (f == 0) {
    ans += 'a';
  }
  assert(ans.size() == n);
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
