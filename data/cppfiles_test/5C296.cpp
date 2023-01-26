#include <bits/stdc++.h>
using namespace std;
void _print(long long int t) { cerr << t; }
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
void _print(unordered_set<T> v) {
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
template <class T, class V>
void _print(multimap<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(unordered_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void solve() {
  long long int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  long long int cnt = 0;
  for (long long int i = 0; i < n; i++) {
    if (s2[i] == '1') {
      if (i == 0) {
        if (s1[0] == '0') {
          s1[0] = 'A';
          cnt++;
        } else if (s1[1] == '1') {
          s1[1] = 'A';
          cnt++;
        }
      } else if (i == n - 1) {
        if (s1[n - 2] == '1') {
          s1[n - 2] = 'A';
          cnt++;
        } else if (s1[n - 1] == '0') {
          s1[n - 1] = 'A';
          cnt++;
        }
      } else {
        if (s1[i - 1] == '1') {
          cnt++;
          s1[i - 1] = 'A';
        } else if (s1[i] == '0') {
          cnt++;
          s1[i] = 'A';
        } else if (s1[i + 1] == '1') {
          cnt++;
          s1[i + 1] = 'A';
        }
      }
    }
  }
  cout << cnt << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
