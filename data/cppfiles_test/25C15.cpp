#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void google(int t) { cout << "Case #" << t << ": "; }
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
void solve(int case_number) {
  long long i, j, k, l, m, n;
  string s, p, q, c;
  cin >> s;
  cin >> p;
  for (i = 0; i < s.length(); i++) {
    for (j = i; j < s.length(); j++) {
      c = "";
      for (k = i; c.length() < p.length() && k <= j; k++) {
        c += s[k];
      }
      for (k = j - 1; c.length() < p.length() && k >= 0; k--) {
        c += s[k];
      }
      if (c == p) {
        printf("YES\n");
        return;
      }
    }
  }
  printf("NO\n");
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  long long i;
  t = 1;
  cin >> t;
  for (int case_number = 1; case_number <= t; case_number++) {
    solve(case_number);
  }
}
