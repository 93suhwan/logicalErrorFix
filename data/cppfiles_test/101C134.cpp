#include <bits/stdc++.h>
using namespace std;
void _print(int a) { cerr << a; }
void _print(long long int a) { cerr << a; }
void _print(char a) { cerr << a; }
void _print(string a) { cerr << a; }
void _print(bool a) { cerr << a; }
void _print(long double a) { cerr << a; }
void _print(unsigned long long int a) { cerr << a; }
void _print(double a) { cerr << a; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(map<T, V> v);
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
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  string s;
  cin >> s;
  vector<long long int> r, b;
  for (long long int i = 0; i < s.size(); i++) {
    if (s[i] == 'R')
      r.push_back(a[i]);
    else
      b.push_back(a[i]);
  }
  sort(b.begin(), b.end());
  sort(r.begin(), r.end());
  for (long long int i = 0; i < b.size(); i++) {
    if (b[i] <= 0) {
      cout << "NO" << '\n';
      return;
    } else {
      if (b[i] >= i + 1)
        continue;
      else {
        cout << "NO" << '\n';
        return;
      }
    }
  }
  for (long long int i = 0; i < r.size(); i++) {
    if (r[i] > n) {
      cout << "NO" << '\n';
      return;
    } else {
      long long int x = (b.size() + i + 1);
      if (r[i] <= x) {
        continue;
      } else {
        cout << "NO" << '\n';
        return;
      }
    }
  }
  cout << "YES" << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int ttt;
  cin >> ttt;
  while (ttt--) {
    solve();
  }
}
