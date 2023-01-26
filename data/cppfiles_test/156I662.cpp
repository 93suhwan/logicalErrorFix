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
long long chk1(long long a[], long long n, long long k, long long s) {
  long long i, z, sm;
  sm = s;
  z = 0;
  for (i = 0; i < n - 1; i++) {
    sm -= a[n - 1 - i];
    sm += a[0];
    z++;
    if (sm <= k) return z;
  }
  sm -= k;
  if (sm > 0) z += sm / n + (sm % n == 0 ? 0 : 1);
  return z;
}
long long chk2(long long a[], long long n, long long k, long long s) {
  long long i, z = 0, p, sm;
  p = k / n;
  if (p < a[0]) z = a[0] - p;
  sm = s - a[0] + p;
  if (sm <= k) return z;
  for (i = 0; i < n - 1; i++) {
    sm -= a[n - 1 - i];
    sm += p;
    z++;
    if (sm <= k) return z;
  }
  return z;
}
long long chk3(long long a[], long long n, long long k, long long s) {
  long long i, z, sm;
  sm = s - a[0] - 1;
  z = a[0] + 1;
  if (sm <= k) return z;
  for (i = 0; i < n - 1; i++) {
    sm -= a[n - 1 - i];
    sm--;
    z++;
    if (sm <= k) return z;
  }
  return z;
}
long long chk4(long long a[], long long n, long long k, long long s) {
  long long i, z, sm;
  sm = s - a[0];
  z = a[0];
  if (sm <= k) return z;
  for (i = 0; i < n - 1; i++) {
    sm -= a[n - 1 - i];
    z++;
    if (sm <= k) return z;
  }
  return z;
}
void solution() {
  long long i, n, k, ans1, ans2, ans3, ans4, ans, s = 0;
  cin >> n >> k;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (i = 0; i < n; i++) s += a[i];
  if (s <= k) {
    _p(0);
    return;
  }
  ans1 = chk1(a, n, k, s);
  ans2 = chk2(a, n, k, s);
  ans3 = chk3(a, n, k, s);
  ans4 = chk4(a, n, k, s);
  ans = min(ans1, ans2);
  ans = min(ans, ans3);
  ans = min(ans, ans4);
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
