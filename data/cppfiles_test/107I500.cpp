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
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
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
using namespace std;
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  long minN;
  if (abs(a - b) > 1) {
    cout << -1 << "\n";
    return;
  }
  vector<int> ans;
  if (a > b) {
    minN = 2 * a + 1;
    if (n < minN) {
      cout << -1 << "\n";
      return;
    }
    int i = 1;
    for (i = 1; i <= n - minN; i++) {
      ans.push_back(i);
    }
    int maxVal = n;
    int start = i;
    for (int i = 0; i < minN; i++) {
      if (i % 2 == 0) {
        ans.push_back(start);
        start++;
      } else {
        ans.push_back(maxVal);
        maxVal--;
      }
    }
  } else if (b > a) {
    minN = 2 * b + 1;
    if (n < minN) {
      cout << -1 << "\n";
      return;
    }
    int start = n;
    for (int i = 1; i <= n - minN; i++) {
      ans.push_back(start);
      start--;
    }
    int maxVal = start;
    start = 1;
    for (int i = 0; i < minN; i++) {
      if (i % 2 != 0) {
        ans.push_back(start);
        start++;
      } else {
        ans.push_back(maxVal);
        maxVal--;
      }
    }
  } else {
    minN = 2 * a + 2;
    if (n < minN) {
      cout << -1 << "\n";
      return;
    }
    int maxVal = n;
    int start = 1;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        ans.push_back(start);
        start++;
      } else {
        ans.push_back(maxVal);
        maxVal--;
      }
    }
  }
  for (int x : ans) cout << x << " ";
  cout << "\n";
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
