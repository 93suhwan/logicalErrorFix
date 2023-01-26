#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(bool t) { t ? cerr << "true" : cerr << "false"; }
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
void fun() {
  long long a, b, c, m;
  cin >> a >> b >> c >> m;
  if (m == 0) {
    cout << "YES\n";
    return;
  }
  long long mxPos = a + b + c - 3;
  if (m > mxPos) {
    cout << "NO\n";
    return;
  }
  long long mx = max({a, b, c});
  long long mn = min({a, b, c});
  long long md = a + b + c - mx - mn;
  long long mxLft = mx, mnLft = mn, mdLft = md;
  if (m >= mx - 1) {
    if (m >= mx + md - 2) {
      mxLft = 0;
      mdLft = 0;
      mnLft -= (m - mx - md + 2);
    } else {
      mxLft = 0;
      mdLft -= (m - mx + 1);
    }
  } else {
    mxLft -= (m + 1);
  }
  mx = max({mxLft, mdLft, mnLft});
  mn = min({mxLft, mdLft, mnLft});
  md = mxLft + mnLft + mdLft - mx - mn;
  long long t1 = mn + md;
  if (mx > t1 + 1 and t1 != 0) {
    cout << "NO\n";
    return;
  }
  if (t1 == 0 and mx > 2) {
    cout << "NO\n";
    return;
  }
  if (mx / 2 > mn) {
    md -= mn;
    md -= (mx - 1 - 2 * mn);
    mn = 0;
    if (md > 2) {
      cout << "NO\n";
      return;
    } else {
      cout << "YES\n";
      return;
    }
  } else {
    if (abs(mx - md) > 1) {
      cout << "NO\n";
      return;
    } else {
      cout << "YES\n";
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) fun();
  return 0;
}
