#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
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
string make(string a1, string a2) {
  string made = a1;
  for (auto x : a2) {
    string t = "";
    for (auto y : a1)
      if (x != y) {
        t += (y);
        made += (y);
      }
    a1 = t;
  }
  return made;
}
void solve() {
  string ans1 = "", ans2 = "";
  string f;
  cin >> f;
  map<char, long long> m;
  for (long long i = ((int)(f).size()) - 1; i >= 0; i--) {
    m[f[i]]++;
    if (m[f[i]] == 1) ans2 += f[i];
  }
  reverse((ans2).begin(), (ans2).end());
  long long l1 = 0;
  long long j = 0;
  for (; j < ((int)(ans2).size()); j++) {
    l1 = l1 + m[ans2[j]] / (j + 1);
    m[ans2[j]] = m[ans2[j]] / (j + 1);
  }
  for (long long i = 0; i < min((int)l1, ((int)(f).size())); i++) ans1 += f[i];
  string made = make(ans1, ans2);
  ;
  if (made == f)
    cout << ans1 << " " << ans2 << endl;
  else
    cout << "-1" << endl;
  char end = '\n';
  ;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
}
