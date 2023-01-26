#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.first != b.first.first) return a.first.first > b.first.first;
  if (a.first.second != b.first.second) return a.first.second < b.first.second;
  return a.second < b.second;
}
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
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
void solve() {
  int t = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for (long long i = 0; i < int((s).size()) - 1; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b') {
        cnt1++;
      }
      if (s[i] == 'b' && s[i + 1] == 'a') {
        cnt2++;
      }
    }
    if (cnt1 != cnt2) {
      if (s[int((s).size()) - 1] == 'a') {
        s[int((s).size()) - 1] = 'b';
      } else {
        s[int((s).size()) - 1] = 'a';
      }
    }
    cout << s << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
