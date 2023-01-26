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
  int n;
  cin >> n;
  char c;
  cin >> c;
  string s;
  cin >> s;
  ;
  bool f = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != c) {
      f = true;
      break;
    }
  }
  if (!f) {
    cout << 0 << endl;
    return;
  }
  if (s[n - 1] == c) {
    cout << 1 << endl;
    cout << n << endl;
    return;
  }
  for (int i = n - 2; i >= n / 2; i--) {
    if (s[i] == c) {
      cout << 1 << endl;
      cout << i + 1 << endl;
      return;
    }
  }
  cout << 2 << endl;
  cout << n << " " << n - 1 << endl;
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
