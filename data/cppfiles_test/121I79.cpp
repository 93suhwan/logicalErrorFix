#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
static inline void umin(T1 &x, T2 y) {
  if (y < x) x = y;
}
template <class T1, class T2>
static inline void umax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <class T>
void print(T t) {
  cerr << t;
}
template <class T1, class T2>
void print(pair<T1, T2> p) {
  cerr << "{ ";
  print(p.first);
  cerr << ", ";
  print(p.second);
  cerr << " }";
};
template <class T>
void print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
};
template <class T>
void print(set<T> s) {
  cerr << "[ ";
  for (T i : s) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
};
template <class T>
void print(multiset<T> ms) {
  cerr << "[ ";
  for (T i : ms) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
};
template <class T1, class T2>
void print(map<T1, T2> m) {
  cerr << "[ ";
  for (auto i : m) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long can(bool alter, long long m0, long long m1, long long nm0,
              long long nm1, long long n, long long mtc) {
  if ((m1 + nm0 + nm1 == n and m1 >= 1 and nm0 >= 0 and nm1 >= 0) or
      (m1 + m0 == n))
    return min(mtc, n - mtc);
  while (m0 >= 0 and m1 >= 0 and nm1 >= 0 and nm0 >= 0) {
    if (alter) {
      swap(m0, nm1);
      long long temp = nm0 + 1;
      nm0 = m1 - 1;
      m1 = temp;
    } else {
      swap(m1, nm0);
      long long temp = m0 + 1;
      m0 = nm1 - 1;
      nm1 = temp;
    }
    if ((m1 + nm0 + nm1 == n and m1 >= 1 and nm0 >= 0 and nm1 >= 0) or
        (m1 + m0 == n))
      return min(mtc, n - mtc);
    alter = !alter;
  }
  return -1;
}
void Solve() {
  long long n = 0;
  cin >> n;
  string a, b;
  cin >> a >> b;
  long long mtc = 0;
  long long m0 = 0, m1 = 0, nm0 = 0, nm1 = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == '0' and b[i] == '0')
      m0++, mtc++;
    else if (a[i] == '1' and b[i] == '1')
      m1++, mtc++;
    else if (a[i] == '0' and b[i] == '1')
      nm0++;
    else if (a[i] == '1' and b[i] == '0')
      nm1++;
  }
  long long ans = -1, a1 = can(0, m0, m1, nm0, nm1, n, mtc),
            a2 = can(0, m0, m1, nm0, nm1, n, mtc);
  if (a1 != -1 and a2 != -1)
    ans = min(a1, a2);
  else if (a1 != -1)
    ans = a1;
  else if (a2 != -1)
    ans = a2;
  cout << ans << '\n';
}
signed main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long TestCases = 1;
  cin >> TestCases;
  for (long long test = 1; test <= TestCases; test++) {
    Solve();
  }
  return 0;
}
