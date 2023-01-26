#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long mod1 = 1000000007;
const long long mod2 = 998244353;
void _print(int a) { cerr << a; }
void _print(double a) { cerr << a; }
void _print(long double a) { cerr << a; }
void _print(long long a) { cerr << a; }
void _print(char a) { cerr << a; }
void _print(string a) { cerr << a; }
void _print(bool a) { cerr << a; }
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
void precomp() {}
void solve() {
  long long n, m;
  cin >> n >> m;
  ;
  string s;
  cin >> s;
  ;
  vector<vector<long long> > pref(6, vector<long long>(n + 1, 0));
  long long i = -1;
  for (char a : {'a', 'b', 'c'}) {
    for (char b : {'a', 'b', 'c'}) {
      for (char c : {'a', 'b', 'c'}) {
        if (a != b && b != c && c != a) {
          i++;
          for (long long j = (0); j < (n); ++j) {
            char d = (j % 3 == 0 ? a : (j % 3 == 1 ? b : c));
            pref[i][j + 1] = pref[i][j] + (d != s[j]);
          }
        }
      }
    }
  }
  long long l, r, ans;
  for (long long i = (0); i < (m); ++i) {
    cin >> l >> r;
    ans = 10000000000;
    for (long long i = (0); i < (6); ++i)
      ans = min(ans, pref[i][r] - pref[i][l - 1]);
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tc = 1;
  precomp();
  while (tc--) {
    solve();
  }
}
