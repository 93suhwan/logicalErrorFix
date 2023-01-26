#include <bits/stdc++.h>
using namespace std;
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
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
long long int mulMod(long long int a, long long int b) {
  a = ((a % 1000000007) * (b % 1000000007)) % 1000000007;
  return a;
}
long long int addMod(long long int a, long long int b) {
  long long int c = (a % 1000000007 + b % 1000000007) % 1000000007;
  return c;
}
long long int powMod(long long int a, long long int b, long long int m) {
  if (b == 0) return 1;
  if (b % 2 == 0)
    return powMod((a * a) % m, b / 2, m);
  else
    return ((a % m) * powMod((a * a) % m, b / 2, m)) % m;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, j, k;
    cin >> n >> k;
    vector<long long int> a(n);
    vector<pair<long long int, long long int> > b;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      b.push_back({a[i], i});
    }
    sort(b.begin(), b.end());
    long long int c = 0;
    for (i = 0; i < n - 1; i++) {
      if (b[i].second + 1 == b[i + 1].second) {
        c++;
      }
    };
    if (k >= n - c)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
