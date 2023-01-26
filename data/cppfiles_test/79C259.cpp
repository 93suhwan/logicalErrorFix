#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
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
bool IsPrime(long long number) {
  if (number <= 1) return false;
  if (number == 2 || number == 3) return true;
  if (number % 2 == 0 || number % 3 == 0) return false;
  for (long long i = 5; i * i <= number; i += 2) {
    if (number % i == 0) return false;
  }
  return true;
}
int func(vector<int> &v, int base, string s) {
  int ind = -1;
  for (int i = 0; i < s.size(); i++) {
    if ((s[i] - '0') == base) {
      ind = i;
      break;
    }
  }
  if (ind == -1) {
    return -1;
  }
  int ans = 0;
  for (int i = ind + 1; i < s.size(); i++) {
    int val = s[i] - '0';
    for (int j = 0; j < v.size(); j++) {
      if (val == v[j]) {
        ans = val;
        break;
      }
    }
    if (ans > 0) {
      break;
    }
  }
  if (ans == 0) {
    return -1;
  } else {
    return base * 10 + ans;
  }
}
void solve() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  int ans = 0;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (IsPrime(s[i] - '0') == false) {
      ans = s[i] - '0';
      cout << 1 << "\n";
      cout << ans << "\n";
      return;
      break;
    }
  }
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[s[i] - '0']++;
  }
  vector<int> v2 = {0, 1, 2, 4, 5, 6, 7, 8}, v3 = {0, 2, 3, 4, 5, 6, 8, 9},
              v5 = {0, 1, 2, 4, 5, 6, 7, 8}, v7 = {0, 2, 4, 5, 6, 7, 8};
  ans = func(v2, 2, s);
  if (ans != -1) {
    cout << 2 << "\n";
    cout << ans << "\n";
    return;
  }
  ans = func(v3, 3, s);
  if (ans != -1) {
    cout << 2 << "\n";
    cout << ans << "\n";
    return;
  }
  ans = func(v5, 5, s);
  if (ans != -1) {
    cout << 2 << "\n";
    cout << ans << "\n";
    return;
  }
  ans = func(v7, 7, s);
  cout << 2 << "\n";
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
