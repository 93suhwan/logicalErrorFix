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
long long moduloExp(long long x, long long y) {
  long long res = 1;
  x %= 1000000007;
  while (y) {
    if (y & 1) res = (res * x) % 1000000007;
    y /= 2;
    x = (x * x) % 1000000007;
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  vector<long long> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<long long> color(n);
  bool flag = 1;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    color[i] = (c == 'B');
    if (arr[i] < 1) {
      if (color[i]) {
        flag = 0;
      }
    }
    if (arr[i] > n) {
      if (!color[i]) {
        flag = 0;
      }
    }
  }
  if (!flag) {
    cout << "NO\n";
  } else {
    vector<long long> inc, dec;
    for (int i = 0; i < n; i++) {
      if (color[i]) {
        dec.push_back(arr[i]);
      } else {
        inc.push_back(arr[i]);
      }
    }
    sort((inc).begin(), (inc).end());
    sort((dec).begin(), (dec).end());
    int curr = 1;
    for (int i = 0; i < dec.size(); i++) {
      if (dec[i] >= curr) {
        curr++;
        continue;
      } else {
        flag = 0;
        break;
      }
    }
    if (flag) {
      for (int i = 0; i < inc.size(); i++) {
        if (inc[i] <= curr) {
          curr++;
          continue;
        } else {
          flag = 0;
          break;
        }
      }
    }
    if (flag) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
