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
int t;
void ggg() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int siv[1000001];
void sieve() {
  int mx = 1000000;
  siv[0] = siv[1] = 0;
  for (int i = 2; i <= mx; i++) siv[i] = 1;
  for (int i = 2; i * i <= mx; i++) {
    if (siv[i]) {
      for (int j = i * i; j <= mx; j += i) siv[j] = 0;
    }
  }
}
int main() {
  ggg();
  sieve();
  vector<int> a;
  for (int i = 0; i < 100000; i++) {
    if (siv[i] == 0 and i != 1 and i != 2) a.push_back(i);
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = false;
    for (int i = 0; i < n; i++) {
      int x = (s[i] - '0');
      if (x == 4 or x == 6 or x == 8 or x == 9) {
        cout << 1 << "\n";
        cout << x << "\n";
        ok = true;
        break;
      }
    }
    if (!ok) {
      for (int i = 0; i < a.size(); i++) {
        if (s.find(to_string(a[i])) != string::npos) {
          cout << to_string(a[i]).size() << "\n";
          cout << to_string(a[i]) << "\n";
          break;
        }
      }
    }
  }
  return 0;
}
