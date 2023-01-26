#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
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
void printvector(vector<long long> V) {
  for (auto i : V) {
    cout << i << " ";
  }
  cout << "\n";
}
vector<long long> sieve(long long n1) {
  vector<long long> prime(n1 + 1, 1);
  for (long long i = 2; i * i <= n1; i++) {
    if (prime[i] == 1) {
      for (long long j = i * 2; j <= n1; j += i) {
        prime[j] = 0;
      }
    }
  }
  return prime;
}
long long testcase;
void solve() {
  long long x, y, z;
  cin >> x >> y >> z;
  if (x == y) {
    if (z % 2 == 0) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  if (y == z) {
    if (x % 2 == 0) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  if (x == z) {
    if (y % 2 == 0) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  if (x + y == z || y + z == x || x + z == y) {
    cout << "YES"
         << "\n";
    return;
  }
  cout << "NO"
       << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  testcase = 1;
  while (T--) {
    solve();
    testcase++;
  }
  return 0;
}
