#include <bits/stdc++.h>
using namespace std;
void _print(long long int t) { cerr << t; }
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
template <class T>
void print(const T *const arr, long long int count) {
  for (long long int i = 0; i < count; ++i) {
    _print(arr[i]);
    cerr << " ";
  }
  cerr << '\n';
}
void Solve() {
  string s;
  cin >> s;
  long long int n = ((long long int)(s).size());
  long long int c1 = 0, c2 = 0;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == '_')
      c1++;
    else if (s[i] == 'X')
      c2++;
  }
  if (c1 == 0 && c2 == 0) {
    long long int m = stoi(s);
    if (m % 25 == 0)
      cout << 1;
    else
      cout << 0;
    return;
  }
  if (n == 1) {
    cout << 0;
    return;
  }
  if (n == 2) {
    if (s[0] == '_') {
      if (s[1] == '_' || s[1] == 'X')
        cout << 3;
      else if (s[1] == '5')
        cout << 2;
      else if (s[1] == '0')
        cout << 1;
      else
        cout << 0;
    } else if (s[0] == 'X') {
      if (s[1] == '_')
        cout << 3;
      else if (s[1] == '5')
        cout << 2;
      else if (s[1] == '0')
        cout << 1;
      else
        cout << 0;
    }
    return;
  }
  if ((s[n - 1] != 'X' && s[n - 1] != '_') &&
      (s[n - 2] != 'X' && s[n - 2] != '_')) {
    string t = s.substr(n - 2, 2);
    if (t != "25" && t != "50" && t != "75" && t != "00")
      cout << 0;
    else {
      if (s[0] == '_') {
        cout << 9 * (max((c1 - 1) * 10, 1ll)) * (c2 > 0 ? 10 : 1);
      } else if (s[0] == 'X')
        cout << c1 * 10 * 9;
    }
    return;
  }
  if (s[n - 2] == '_') {
    if (s[n - 1] == 'X') {
      long long int ans;
      if (s[0] == '_') {
        ans = (max((c1 - 2) * 10, 1ll)) * 4 * 9;
      } else if (s[0] == 'X') {
        ans = (max((c1 - 1) * 10, 1ll)) * 2;
      } else {
        ans = (max((c1 - 1) * 10, 1ll)) * 4;
      }
      cout << ans;
    } else if (s[n - 1] == '_') {
      long long int ans;
      if (s[0] == '_') {
        ans = 4 * 9 * (c2 > 0 ? 10 : 1) * (max((c1 - 3) * 10, 1ll));
      } else if (s[0] == 'X') {
        ans = (max((c1 - 2) * 10, 1ll)) * 36;
      } else {
        ans = (c2 > 0 ? 10 : 1) * (max((c1 - 2) * 10, 1ll)) * 4;
      }
      cout << ans;
    } else if (s[n - 1] == '0' || s[n - 1] == '5') {
      long long int ans;
      if (s[0] == 'X')
        ans = 9 * (max((c1 - 1) * 10, 1ll));
      else if (s[0] == '_')
        ans = (c2 > 0 ? 10 : 1) * 9 * (max((c1 - 2) * 10, 1ll));
      else
        ans = (c2 > 0 ? 10 : 1) * (max((c1 - 1) * 10, 1ll));
      cout << ans * 2;
    } else
      cout << 0;
    return;
  }
  if (s[n - 2] == 'X') {
    long long int ans = 0;
    if (s[n - 1] == 'X') {
      if (s[0] == 'X')
        ans = 0;
      else if (s[0] == '_') {
        ans = 9;
        ans = 9 * (max((c1 - 1) * 10, 1ll));
      } else {
        ans = c1 * 10;
      }
      cout << ans;
    } else if (s[n - 1] == '_') {
      if (s[0] == 'X') {
        ans = 3 * (max((c1 - 1) * 10, 1ll));
      } else if (s[0] == '_') {
        ans = (max((c1 - 2) * 10, 1ll)) * 4 * 9;
      } else {
        ans = 4 * (max((c1 - 1) * 10, 1ll));
      }
      cout << ans;
    } else if (s[n - 1] == '0') {
      if (s[0] == 'X') {
        ans = 1;
        ans = c1 * 10;
      } else if (s[0] == '_') {
        ans = (max((c1 - 1) * 10, 1ll)) * 9 * 2;
      } else {
        ans = 2 * c1 * 10;
      }
      cout << ans;
    } else if (s[n - 1] == '5') {
      if (s[0] == '_') {
        ans = 9 * 2 * (max((c1 - 1) * 10, 1ll));
      } else {
        ans = c1 * 10 * 2;
      }
      cout << ans;
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T = 1;
  for (long long int i = 1; i < T + 1; i++) {
    Solve();
    cout << '\n';
  }
  return 0;
}
