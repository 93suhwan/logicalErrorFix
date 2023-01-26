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
  vector<long long> abc(n + 1, 0), cba(n + 1, 0), acb(n + 1, 0), cab(n + 1, 0),
      bca(n + 1, 0), bac(n + 1, 0);
  vector<long long> ok = {'a', 'b', 'c'};
  vector<long long> ok2 = {'c', 'b', 'a'};
  for (long long i = (0); i < (n); ++i) {
    if (s[i] != ok[i % 3])
      abc[i + 1] = abc[i] + 1;
    else
      abc[i + 1] = abc[i];
    if (s[i] != ok[(i + 1) % 3])
      bca[i + 1] = bca[i] + 1;
    else
      bca[i + 1] = bca[i];
    if (s[i] != ok[(i + 2) % 3])
      cab[i + 1] = cab[i] + 1;
    else
      cab[i + 1] = cab[i];
    if (s[i] != ok2[i % 3])
      cba[i + 1] = cba[i] + 1;
    else
      cba[i + 1] = cba[i];
    if (s[i] != ok2[(i + 1) % 3])
      bac[i + 1] = bac[i] + 1;
    else
      bac[i + 1] = bac[i];
    if (s[i] != ok2[(i + 2) % 3])
      acb[i + 1] = acb[i] + 1;
    else
      acb[i + 1] = acb[i];
  }
  for (long long i = (0); i < (m); ++i) {
    long long l, r;
    cin >> l >> r;
    ;
    long long ans =
        min(abc[r] - abc[l - 1],
            min(acb[r] - acb[l - 1],
                min(bca[r] - bca[l - 1],
                    min(bac[r] - bac[l - 1],
                        min(cab[r] - cab[l - 1], cba[r] - cba[l - 1])))));
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
