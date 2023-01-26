#include <bits/stdc++.h>
using namespace std;
template <class T>
void __p(T a) {
  cout << a << '\n';
}
template <class T>
void __p(T a[], long long n) {
  long long i;
  for (i = 0; i < n; i++) cout << a[i] << ' ';
  cout << '\n';
}
template <class T>
void __p(vector<T> v) {
  for (auto x : v) cout << x << ' ';
  cout << '\n';
}
template <class T>
void __p(list<T> l) {
  for (auto x : l) cout << x << ' ';
  cout << '\n';
}
template <class T>
void __p(set<T> s) {
  for (auto x : s) cout << x << ' ';
  cout << '\n';
}
template <class T>
void __p(multiset<T> s) {
  for (auto x : s) cout << x << ' ';
  cout << '\n';
}
template <class T>
void __p(unordered_set<T> s) {
  for (auto x : s) cout << x << ' ';
  cout << '\n';
}
template <class T1, class T2>
void __p(map<T1, T2> m) {
  for (auto x : m) cout << x.first << "->" << x.second << '\n';
  cout << '\n';
}
template <class T1, class T2>
void __p(unordered_map<T1, T2> m) {
  for (auto x : m) cout << x.first << "->" << x.second << '\n';
  cout << '\n';
}
template <class T1, class T2>
void __p(map<T1, vector<T2>> m) {
  for (auto x : m) {
    cout << x.first << "->";
    __p(x.second);
  }
  cout << '\n';
}
template <class T1, class T2>
void __p(unordered_map<T1, vector<T2>> m) {
  for (auto x : m) {
    cout << x.first << "->";
    __p(x.second);
  }
  cout << '\n';
}
bool chk1(long long n, long long m, long long k, long long z) {
  if (k == 0 and z == 0) return true;
  long long a, b, c, d;
  a = m / 2;
  b = k / a + (k % a == 0 ? 0 : 1);
  n -= b;
  c = n / 2;
  c *= m;
  if (n < 0) return false;
  if (n & 1) {
    d = k % a;
    if (d == 0) d = a;
    m -= d * 2;
    c += m / 2;
  }
  if (c >= z)
    return true;
  else
    return false;
}
bool chk2(long long n, long long m, long long k, long long z) {
  if (k == 0 and z == 0) return true;
  long long a, b = 0, c;
  a = k / n + (k % n == 0 ? 0 : 1);
  m -= a * 2;
  if (k % n != 0) b = n - k % n;
  if (m < 0) return false;
  c = (n / 2) * m;
  c += (b / 2) * 2;
  if (c >= z)
    return true;
  else
    return false;
}
void solution() {
  long long n, m, z, k;
  cin >> n >> m >> k;
  z = (n * m) / 2;
  z -= k;
  if (n == 1 and z > 0) {
    cout << "NO" << '\n';
    return;
  } else if (m == 1 and k > 0) {
    cout << "NO" << '\n';
    return;
  }
  if (n & 1) k -= min(k, m / 2), n--;
  if (m & 1) z -= min(z, n / 2), m--;
  if (chk1(n, m, k, z))
    cout << "YES" << '\n';
  else if (chk1(m, n, z, k))
    cout << "YES" << '\n';
  else if (chk2(n, m, k, z))
    cout << "YES" << '\n';
  else if (chk2(m, n, z, k))
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
}
int32_t main() {
  long long tcse;
  cin >> tcse;
  while (tcse--) solution();
}
