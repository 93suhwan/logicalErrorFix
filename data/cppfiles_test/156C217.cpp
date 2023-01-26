#include <bits/stdc++.h>
using namespace std;
template <class T>
void _p(T a) {
  cout << a << '\n';
}
template <class T>
void _pa(T a) {
  cout << a << ' ';
}
template <class T1, class T2>
void _p(T1 a, T2 b) {
  cout << a << ' ' << b << '\n';
}
template <class T1, class T2, class T3>
void _p(T1 a, T2 b, T3 c) {
  cout << a << ' ' << b << ' ' << c << '\n';
}
template <class T1, class T2, class T3, class T4>
void _p(T1 a, T2 b, T3 c, T4 d) {
  cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << '\n';
}
template <class T1, class T2, class T3, class T4, class T5>
void _p(T1 a, T2 b, T3 c, T4 d, T5 e) {
  cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << '\n';
}
template <class T>
void _pa(T a[], long long n) {
  long long i;
  for (i = 0; i < n; i++) cout << a[i] << ' ';
  cout << '\n';
}
template <class T>
void _p(vector<T> v) {
  for (auto x : v) cout << x << ' ';
  cout << '\n';
}
template <class T>
void _p(list<T> l) {
  for (auto x : l) cout << x << ' ';
  cout << '\n';
}
template <class T>
void _p(set<T> s) {
  for (auto x : s) cout << x << ' ';
  cout << '\n';
}
template <class T>
void _p(multiset<T> s) {
  for (auto x : s) cout << x << ' ';
  cout << '\n';
}
template <class T>
void _p(unordered_set<T> s) {
  for (auto x : s) cout << x << ' ';
  cout << '\n';
}
template <class T1, class T2>
void _p(map<T1, T2> m) {
  for (auto x : m) cout << x.first << "->" << x.second << '\n';
  cout << '\n';
}
template <class T1, class T2>
void _p(unordered_map<T1, T2> m) {
  for (auto x : m) cout << x.first << "->" << x.second << '\n';
  cout << '\n';
}
template <class T1, class T2>
void _p(map<T1, vector<T2>> m) {
  for (auto x : m) {
    cout << x.first << "->";
    _p(x.second);
  }
  cout << '\n';
}
template <class T1, class T2>
void _p(unordered_map<T1, vector<T2>> m) {
  for (auto x : m) {
    cout << x.first << "->";
    _p(x.second);
  }
  cout << '\n';
}
void solution() {
  long long i, n, k, ans = LLONG_MAX, s, p, z, sm;
  cin >> n >> k;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (i = 0; i < n; i++) s += a[i];
  sm = a[0] * n;
  vector<long long> v;
  for (i = 0; i < n; i++) {
    sm += (a[i] - a[0]);
    v.push_back(sm);
    if (sm <= k) ans = min(ans, n - 1 - i);
  }
  for (i = 0; i < n; i++)
    if (v[i] > k) {
      sm = v[i] - k;
      z = sm / (n - i) + (sm % (n - i) == 0 ? 0 : 1);
      ans = min(ans, n - 1 - i + z);
    }
  p = -1;
  sm = s;
  z = a[0] + 1;
  sm = s - a[0] - 1;
  if (sm <= k) ans = min(ans, z);
  for (i = 0; i < n - 1; i++) {
    sm -= a[n - 1 - i];
    sm--;
    z++;
    if (sm <= k) ans = min(ans, z);
  }
  p = 0;
  sm = s;
  z = a[0];
  sm = s - a[0];
  if (sm <= k) ans = min(ans, z);
  for (i = 0; i < n - 1; i++) {
    sm -= a[n - 1 - i];
    z++;
    if (sm <= k) ans = min(ans, z);
  }
  _p(ans);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tcse;
  cin >> tcse;
  while (tcse--) solution();
}
