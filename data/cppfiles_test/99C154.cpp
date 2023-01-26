#include <bits/stdc++.h>
using namespace std;
void _print(double x) { cerr << x; }
void _print(int x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(float x) { cerr << x; }
void _print(long long x) { cerr << x; }
void _print(string x) { cerr << x; }
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << ", ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(pair<T, V> v) {
  cerr << "[ ";
  cerr << v.first << ", " << v.second;
  cerr << " ]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << ", ";
  }
  cerr << "]";
}
template <class T>
void _print(unordered_set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << ", ";
  }
  cerr << " ]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << ", ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> m) {
  cerr << "[ ";
  cerr << '\n';
  for (auto i : m) {
    _print(i);
    cerr << '\n';
  };
  cerr << " ]";
}
template <class T, class V>
void _print(unordered_map<T, V> m) {
  cerr << "[ ";
  cerr << '\n';
  for (auto i : m) {
    _print(i);
    cerr << '\n';
  };
  cerr << " ]";
}
template <class T, class V>
void _print(multimap<T, V> m) {
  cerr << "[ ";
  cerr << '\n';
  for (auto i : m) {
    _print(i);
    cerr << '\n';
  };
  cerr << " ]";
}
void pre() {}
long long getVal(long long x, long long div) {
  if (x & 1) {
    return x - (4 * div);
  } else {
    return x + (4 * div);
  }
}
void solve() {
  long long x, n;
  cin >> x >> n;
  if (n % 4 == 0) {
    cout << x << endl;
    return;
  }
  long long div = (n / 4);
  int md = (n % 4);
  long long a, b, c;
  a = (x & 1 ? x + 1 : x - 1);
  b = (a & 1 ? a + 2 : a - 2);
  c = (b & 1 ? b + 3 : b - 3);
  long long sum = 0;
  if (md == 1) {
    sum += getVal(a, div);
  }
  if (md == 2) {
    sum = b;
  }
  if (md == 3) {
    sum += getVal(c, div);
  }
  cout << sum << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  pre();
  while (t--) {
    solve();
  }
  return 0;
}
