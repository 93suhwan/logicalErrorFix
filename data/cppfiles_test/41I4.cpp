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
  vector<pair<long long, long long> > count(n);
  count[0] = {1, 0};
  long long curr;
  if (s[1] != s[0]) {
    count[1] = {2, 0};
    curr = 0;
  } else {
    count[1] = {1, 1};
    curr = 1;
  }
  long long wild = 0;
  for (long long i = (2); i < (n); ++i) {
    count[i] = count[i - 1];
    if (s[i] != s[i - 1] && s[i] != s[i - 2]) {
      if (s[i - 2] == s[i - 1])
        wild++;
      else {
        if (curr == 0) {
          count[i].first++;
        } else
          count[i].second++;
      }
    } else {
      if (s[i - 1] != s[i - 2]) {
        if (curr == 0) {
          count[i].second++;
          curr = 1;
        } else {
          count[i].first++;
          curr = 0;
        }
      } else {
        wild++;
      }
    }
  }
  count.insert(count.begin(), {0, 0});
  for (long long i = (0); i < (m); ++i) {
    long long l, r;
    cin >> l >> r;
    ;
    if (l == r)
      cout << 0 << "\n";
    else
      cout << min(count[r].first - count[l - 1].first,
                  count[r].second - count[l - 1].second) +
                  wild
           << "\n";
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
