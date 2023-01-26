#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void print(long long a) { cerr << a; }
void print(string a) { cerr << a; }
void print(char a) { cerr << a; }
void print(int a) { cerr << a; }
void print(bool a) { cerr << a; }
void print(long double a) { cerr << a; }
void print(unsigned long long a) { cerr << a; }
template <class S>
void print(vector<S> v);
template <class S, class T>
void print(pair<S, T> p);
template <class S, class T>
void print(map<S, T> m);
template <class S, class T>
void print(unordered_map<S, T> m);
template <class S, class T>
void print(multimap<S, T> m);
template <class S>
void print(set<S> s);
template <class S>
void print(unordered_set<S> s);
template <class S>
void print(multiset<S> s);
template <class S>
void print(stack<S> s);
template <class S>
void print(vector<S> v) {
  cerr << "[ ";
  for (S it : v) {
    print(it);
    cerr << " ";
  }
  cerr << "]";
}
template <class S, class T>
void print(pair<S, T> p) {
  cerr << "{ ";
  print(p.first);
  cerr << ", ";
  print(p.second);
  cerr << "}";
}
template <class S, class T>
void print(map<S, T> m) {
  cerr << "[ ";
  for (auto it : m) {
    print(it);
    cerr << " ";
  }
  cerr << "]";
}
template <class S, class T>
void print(unordered_map<S, T> m) {
  cerr << "[ ";
  for (auto it : m) {
    print(it);
    cerr << " ";
  }
  cerr << "]";
}
template <class S, class T>
void print(multimap<S, T> m) {
  cerr << "[ ";
  for (auto it : m) {
    print(it);
    cerr << " ";
  }
  cerr << "]";
}
template <class S>
void print(set<S> s) {
  cerr << "[ ";
  for (S it : s) {
    print(it);
    cerr << " ";
  }
  cerr << "]";
}
template <class S>
void print(unordered_set<S> s) {
  cerr << "[ ";
  for (S it : s) {
    print(it);
    cerr << " ";
  }
  cerr << "]";
}
template <class S>
void print(multiset<S> s) {
  cerr << "[ ";
  for (S it : s) {
    print(it);
    cerr << " ";
  }
  cerr << "]";
}
template <class S>
void print(stack<S> s) {
  cerr << "[ ";
  while (!s.empty()) {
    print(s.top());
    cerr << " ";
    s.pop();
  }
  cerr << "]";
}
long long _gcd(long long a, long long b) {
  if (b == 0) return a;
  return _gcd(b, (a % b));
}
long long lcm(long long a, long long b) { return ((a * b) / _gcd(a, b)); }
long long power(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * a) % (long long)(1e9 + 7);
    a = (a * a) % (long long)(1e9 + 7);
    n >>= 1;
  }
  return res;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 == x2 || y1 == y2) {
    cout << 0 << "\n";
    return;
  }
  if (x2 < x1) {
    if (y2 > y1) {
      long long ansr = x1 - x2 + 2 * (n - x1);
      cout << min(ansr, y2 - y1) << "\n";
    } else {
      long long ansr = x1 - x2 + 2 * (n - x1);
      long long ansc = y1 - y2 + 2 * (m - y1);
      cout << min(ansr, ansc) << "\n";
    }
  } else {
    if (y2 < y1) {
      long long ansc = y1 - y2 + 2 * (m - y1);
      cout << min(ansc, x2 - x1) << "\n";
      return;
    } else {
      cout << min((y2 - y1), (x2 - x1)) << "\n";
      return;
    }
  }
}
void tests() {
  long long test = 1;
  long long testcases = 1;
  cin >> test;
  cout << setprecision(12);
  cerr << setprecision(6);
  while (test--) {
    solve();
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  auto clock_start = high_resolution_clock::now();
  tests();
  auto clock_end = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(clock_end - clock_start);
  cerr << "\nTime taken: " << (double)duration.count() << " MS\n";
  return 0;
}
