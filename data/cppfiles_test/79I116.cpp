#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
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
void test_case() {
  int k;
  cin >> k;
  map<int, long long> mp;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    mp[s[i] - '0']++;
  }
  for (int i = 1; i < 10; i++) {
    if (i == 2 || i == 3 || i == 5 || i == 7)
      continue;
    else {
      if (mp[i] > 0) {
        cout << 1 << "\n";
        cout << i << "\n";
        return;
      }
    }
  }
  for (auto it : mp) {
    if (it.second >= 2) {
      cout << 2 << "\n";
      cout << it.first << it.first << "\n";
      return;
    }
  }
  if ((s[k - 1] == '2' || s[k - 1] == '5') && k > 2) {
    cout << k << "\n";
    cout << s << "\n";
    return;
  }
  for (int i = 0; i < s.length(); i++) {
    if ((s[i] == '2' || s[i] == '5') && (i != 0)) {
      cout << (i + 1) << "\n";
      for (int j = 0; j < (i + 1); j++) cout << s[j];
      cout << "\n";
      return;
    }
  }
  cout << k << "\n";
  cout << s << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t begin = clock();
  long long t = 1;
  cin >> t;
  while (t--) {
    test_case();
  }
  return 0;
}
