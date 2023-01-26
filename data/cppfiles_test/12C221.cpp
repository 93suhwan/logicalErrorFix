#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _read(T& t);
template <typename T>
void _read(vector<T>& v);
template <typename T1, typename T2>
void _read(pair<T1, T2>& p);
template <typename T>
void _read(T& t) {
  cin >> t;
}
template <typename T>
void _read(vector<T>& v) {
  for (unsigned _i = 0; _i < v.size(); _i++) _read(v[_i]);
}
template <typename T1, typename T2>
void _read(pair<T1, T2>& p) {
  _read(p.first);
  _read(p.second);
}
void _masterread() {}
template <typename T, typename... V>
void _masterread(T& t, V&... v) {
  _read(t);
  _masterread(v...);
}
stringstream _effout;
template <typename T>
void _print(T t);
template <typename T>
void _print(vector<T>& v);
template <typename T1, typename T2>
void _print(pair<T1, T2>& p);
template <typename T>
void _print(T t) {
  cout << t;
}
template <typename T>
void _print(vector<T>& v) {
  for (unsigned _i = 0; _i < v.size(); _i++)
    _print(v[_i]), cout << (_i == v.size() - 1 ? "" : " ");
}
template <typename T1, typename T2>
void _print(pair<T1, T2>& p) {
  _print(p.first);
  cout << " ";
  _print(p.second);
}
void _masterprint() {}
template <typename T, typename... V>
void _masterprint(T t, V... v) {
  _print(t);
  if (sizeof...(v)) cout << " ";
  _masterprint(v...);
}
template <typename T>
void _debug(T t);
template <typename T1, typename T2>
void _debug(pair<T1, T2> p);
template <typename T>
void _debug(vector<T> v);
template <typename T>
void _debug(set<T> s);
template <typename T>
void _debug(unordered_set<T> s);
template <typename T>
void _debug(multiset<T> s);
template <typename T>
void _debug(unordered_multiset<T> s);
template <typename T1, typename T2>
void _debug(map<T1, T2> mp);
template <typename T1, typename T2>
void _debug(unordered_map<T1, T2> mp);
template <typename T1, typename T2>
void _debug(multimap<T1, T2> mp);
template <typename T1, typename T2>
void _debug(unordered_multimap<T1, T2> mp);
template <typename T>
void _debug(T t) {
  cerr << t;
}
template <typename T1, typename T2>
void _debug(pair<T1, T2> p) {
  cerr << "{";
  _debug(p.first);
  cerr << ", ";
  _debug(p.second);
  cerr << "}";
}
template <typename T>
void _debug(vector<T> v) {
  cerr << "(";
  for (unsigned _i = 0; _i < v.size(); _i++)
    _debug(v[_i]), cerr << (_i == v.size() - 1 ? "" : ", ");
  cerr << ")";
}
template <typename T>
void _debug(set<T> s) {
  cerr << "(";
  for (auto e = s.begin(); e != s.end();)
    _debug(*e), cerr << ((++e) == s.end() ? "" : ", ");
  cerr << ")";
}
template <typename T>
void _debug(unordered_set<T> s) {
  cerr << "(";
  for (auto e = s.begin(); e != s.end();)
    _debug(*e), cerr << ((++e) == s.end() ? "" : ", ");
  cerr << ")";
}
template <typename T>
void _debug(multiset<T> s) {
  cerr << "(";
  for (auto e = s.begin(); e != s.end();)
    _debug(*e), cerr << ((++e) == s.end() ? "" : ", ");
  cerr << ")";
}
template <typename T>
void _debug(unordered_multiset<T> s) {
  cerr << "(";
  for (auto e = s.begin(); e != s.end();)
    _debug(*e), cerr << ((++e) == s.end() ? "" : ", ");
  cerr << ")";
}
template <typename T1, typename T2>
void _debug(map<T1, T2> mp) {
  cerr << "(";
  for (auto e = mp.begin(); e != mp.end();)
    _debug(*e), cerr << ((++e) == mp.end() ? "" : ", ");
  cerr << ")";
}
template <typename T1, typename T2>
void _debug(unordered_map<T1, T2> mp) {
  cerr << "(";
  for (auto e = mp.begin(); e != mp.end();)
    _debug(*e), cerr << ((++e) == mp.end() ? "" : ", ");
  cerr << ")";
}
template <typename T1, typename T2>
void _debug(multimap<T1, T2> mp) {
  cerr << "(";
  for (auto e = mp.begin(); e != mp.end();)
    _debug(*e), cerr << ((++e) == mp.end() ? "" : ", ");
  cerr << ")";
}
template <typename T1, typename T2>
void _debug(unordered_multimap<T1, T2> mp) {
  cerr << "(";
  for (auto e = mp.begin(); e != mp.end();)
    _debug(*e), cerr << ((++e) == mp.end() ? "" : ", ");
  cerr << ")";
}
void _masterdebug() { cerr << "]" << endl; }
template <typename T, typename... V>
void _masterdebug(T t, V... v) {
  _debug(t);
  if (sizeof...(v)) cerr << ", ";
  _masterdebug(v...);
}
void prep();
void testcase(signed testcase);
signed main() {
  if (!0) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  }
  _masterprint(setprecision(10));
  _masterprint(fixed);
  prep();
  if (1) {
    int t = 0;
    signed __T;
    cin >> __T;
    while (__T--) testcase(++t);
  } else {
    testcase(1);
  }
  cout << _effout.str();
}
void prep() {}
void testcase(signed testcase) {
  int n, m, k;
  _masterread(n, m, k);
  vector<string> res(n, string(m, '.'));
  if (n & 1) {
    for (int j = 0; j < m; j += 2) {
      res[0][j] = 'x';
      res[0][j + 1] = 'x';
      k--;
    }
  }
  if (k < 0) {
    (_masterprint("No"), cout << endl);
    return;
  } else if (k == 0) {
    (_masterprint("Yes"), cout << endl);
    return;
  }
  for (int i = n & 1; i < n; i += 2) {
    for (int j = 0; j < m / 2 * 2; j += 2) {
      res[i][j] = 'x';
      res[i][j + 1] = 'x';
      res[i + 1][j] = 'x';
      res[i + 1][j + 1] = 'x';
      k -= 2;
      if (k < 0) {
        (_masterprint("No"), cout << endl);
        return;
      } else if (k == 0) {
        (_masterprint("Yes"), cout << endl);
        return;
      }
    }
  }
  (_masterprint("No"), cout << endl);
  return;
}
