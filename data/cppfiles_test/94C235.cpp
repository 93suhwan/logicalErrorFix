#include <bits/stdc++.h>
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
template <class T>
void _print(stack<T> v) {
  int k = v.size();
  cerr << "-> ";
  while (k--) {
    _print(v.top());
    v.pop();
    cerr << " ";
  }
  cerr << "||";
}
template <class T>
void _print(queue<T> v) {
  int k = v.size();
  cerr << "-> ";
  while (k--) {
    _print(v.front());
    v.pop();
    cerr << " ";
  }
  cerr << "->";
}
template <class T>
void _print(priority_queue<T> v) {
  int k = v.size();
  cerr << "-> ";
  while (k--) {
    _print(v.top());
    v.pop();
    cerr << " ";
  }
  cerr << "->";
}
void printans(bool ans) {
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
void solve() {
  string s;
  cin >> s;
  ;
  string s1, s2;
  for (int i = 0; i < s.size(); i++) {
    if (i % 2)
      s1 += s[i];
    else
      s2 += s[i];
  }
  if (s1.size() == 0) s1 = "0";
  if (s2.size() == 0) s1 = "0";
  ;
  ;
  int ans = (stoi(s1) + 1) * (stoi(s2) + 1);
  ans -= 2;
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
