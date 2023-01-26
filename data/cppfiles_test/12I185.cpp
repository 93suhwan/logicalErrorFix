#include <bits/stdc++.h>
long long dx[4] = {-1, 0, 1, 0};
long long dy[4] = {0, -1, 0, 1};
long long mod = 1e9 + 7;
long long inf = 5e18;
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
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
int fun(int i, int g1, int g2, int r1, int r2, string &a) {
  if (i == a.size()) {
    return 10;
  }
  if (g1 > g2 + r2) {
    return i;
  }
  if (g2 > g1 + r1) {
    return i;
  }
  if (a[i] == '1') {
    if (i % 2 == 0) {
      g1++;
      r1--;
    } else {
      g2++;
      r2--;
    }
    return fun(i + 1, g1, g2, r1, r2, a);
  } else if (a[i] == '0') {
    if (i % 2 == 0) {
      r1--;
    } else {
      r2--;
    }
    return fun(i + 1, g1, g2, r1, r2, a);
  } else {
    if (i % 2 == 0) {
      return min(fun(i + 1, g1 + 1, g2, r1 - 1, r2, a),
                 fun(i + 1, g1, g2, r1 - 1, r2, a));
    } else {
      return min(fun(i + 1, g1, g2 + 1, r1, r2 - 1, a),
                 fun(i + 1, g1, g2, r1, r2 - 1, a));
    }
  }
}
bool sortbysecdesc(const pair<long long, long long> &a,
                   const pair<long long, long long> &b) {
  return (a.second - a.first) > (b.second - b.first);
}
void solve(long long t) {
  long long r, c, k;
  cin >> r >> c >> k;
  if (r % 2 == 0 && c % 2 == 0) {
    if (k % 2 == 0) {
      cout << "YES"
           << "\n";
      return;
    } else {
      cout << "NO"
           << "\n";
      return;
    }
  }
  if (c % 2 == 1) {
    if (k % 2 == 0) {
      cout << "YES"
           << "\n";
      return;
    } else {
      cout << "NO"
           << "\n";
    }
  } else {
    k = (r * c) / 2 - k;
    if (k % c == 0) {
      cout << "YES"
           << "\n";
      return;
    } else {
      cout << "NO"
           << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
