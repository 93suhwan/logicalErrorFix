#include <bits/stdc++.h>
using namespace std;
void _print(long long int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(vector<vector<T>> v);
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
    cerr << " , ";
  }
  cerr << "]";
}
template <class T>
void _print(vector<vector<T>> v) {
  cerr << "[ ";
  for (auto& row : v) {
    cerr << " {";
    for (auto& col : row) {
      _print(col);
      cerr << " , ";
    }
    cerr << "}\n";
  }
  cerr << " ]";
}
const long long int no = 1e6 + 5, modulo = 1e9 + 7, inf = 1e18, N = 1e3 + 1;
long long int ar[no], br[no];
void solve() {
  long long int n = 0, m = 0, a = 0, b = 0, c = 0, d = 0, x = 0, y = 0, z = 0,
                w = 0, k = 0;
  cin >> n;
  for (long long int i = 0; i < n; i += 1) {
    cin >> ar[i];
  }
  string s;
  cin >> s;
  vector<long long int> red, blue;
  for (long long int i = 0; i < n; i += 1) {
    if (s[i] == 'R') {
      if (ar[i] > n) {
        cout << "NO\n";
        return;
      }
      red.push_back(ar[i]);
    } else {
      if (ar[i] <= 0) {
        cout << "NO\n";
        return;
      }
      blue.push_back(ar[i]);
    }
  }
  sort(red.begin(), red.end());
  sort(blue.begin(), blue.end());
  a = 1;
  for (long long int i = 0; i < (long long int)(blue.size()); i += 1) {
    if (blue[i] < a) {
      cout << "NO\n";
      return;
    }
    a++;
  }
  for (long long int i = 0; i < (long long int)(red.size()); i += 1) {
    if (red[i] > a) {
      cout << "NO\n";
      return;
    }
    a++;
  }
  cout << "YES\n";
}
inline void runn() {}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  runn();
  long long int t = 1;
  cout << fixed << setprecision(15);
  cin >> t;
  for (long long int i = 1; i < t + 1; i += 1) {
    solve();
  }
}
