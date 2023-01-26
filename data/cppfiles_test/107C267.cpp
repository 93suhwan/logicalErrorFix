#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  cin >> x;
}
template <typename T, typename T0>
void read(T &x, T0 &y) {
  cin >> x >> y;
}
template <typename T, typename T0, typename T1>
void read(T &x, T0 &y, T1 &z) {
  cin >> x >> y >> z;
}
template <typename T, typename T0, typename T1, typename T2>
void read(T &x, T0 &y, T1 &z, T2 &w) {
  cin >> x >> y >> z >> w;
}
template <typename T, typename T0>
void read(pair<T, T0> &p) {
  cin >> p.first >> p.second;
}
template <typename T>
void read(vector<T> &oneD, long long n) {
  for (long long(i) = 0; (i) < (n); ++(i)) {
    long long x;
    read(x);
    oneD.push_back(x);
  }
}
template <typename T>
void read(T oneD[], long long n) {
  for (long long i = 0; i < n; i++) {
    read(oneD[i]);
  }
}
template <typename T>
void write(T &x) {
  cout << x << " ";
}
template <typename T>
void wrtline(T &x) {
  cout << x << "\n";
}
template <typename T, typename T0>
void write(T &x, T0 &y) {
  cout << x << " " << y << "\n";
}
template <typename T, typename T0, typename T1>
void write(T &x, T0 &y, T1 &z) {
  cout << x << " " << y << " " << z << "\n";
}
template <typename T, typename T0, typename T1, typename T2>
void write(T &x, T0 &y, T1 &z, T2 &w) {
  cout << x << " " << y << " " << z << " " << w << "\n";
}
template <typename T, typename T0>
void write(pair<T, T0> &p) {
  write(p.first);
  write(p.second);
  cout << "\n";
}
template <typename T>
void write(vector<T> &oneD, long long n) {
  for (long long i = 0; i < n; i++) {
    cout << oneD[i] << " ";
  }
  cout << "\n";
}
template <typename T>
void write(T oneD[], int &n) {
  for (long long i = 0; i < n; i++) {
    write(oneD[i]);
  }
  cout << "\n";
}
template <typename T, typename T0>
void write(map<T, T0> &mpp) {
  for (auto it : mpp) {
    write(it.first);
    cout << ": ";
    write(it.second);
    cout << "\n";
  }
  cout << "\n";
}
template <typename T>
void write(vector<vector<T>> &rc, T &n, T &m) {
  for (long long(i) = 0; (i) < (n); ++(i)) {
    for (long long(j) = 0; (j) < (m); ++(j)) {
      cout << rc[i][j] << " ";
    }
    cout << "\n";
  }
}
template <typename T>
void _print(T &t) {
  cerr << t;
}
template <class T, class V>
void _print(pair<T, V> &p);
template <class T>
void _print(vector<T> &v);
template <class T>
void _print(set<T> &v);
template <class T, class V>
void _print(map<T, V> &v);
template <class T>
void _print(multiset<T> &v);
template <class T, class V>
void _print(pair<T, V> &p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> &v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> &v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> &v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> &v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void solve() {
  long long n, a, b;
  read(n, a, b);
  if (a == 0 and b == 0) {
    for (long long(i) = 1; (i) <= (n); ++(i)) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }
  if (abs(a - b) > 1 or a + b > n - 2) {
    cout << -1 << "\n";
    return;
  }
  vector<long long> ans;
  for (long long(i) = 1; (i) <= (n); ++(i)) {
    ans.push_back(i);
  }
  if (a > b) {
    long long cnt = 0;
    for (long long i = n - 1; i >= 1 and cnt != a; i -= 2) {
      swap(ans[i], ans[i - 1]);
      cnt++;
    }
  } else if (a < b) {
    long long cnt = 0;
    for (long long i = 0; i < n - 1 and cnt != b; i += 2) {
      swap(ans[i], ans[i + 1]);
      cnt++;
    }
  } else {
    long long cnt = 0;
    for (long long i = n - 1; i >= 1 and cnt != a; i -= 2) {
      swap(ans[i], ans[i - 1]);
      cnt++;
    }
    swap(ans[0], ans[1]);
  }
  write(ans, n);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  read(t);
  while (t--) solve();
  return 0;
}
