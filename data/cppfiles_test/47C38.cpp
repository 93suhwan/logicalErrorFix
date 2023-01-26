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
vector<bool> isPrime(1e7, true);
void sieve() {
  for (int p = 2; p * p <= 1e7; p++)
    if (isPrime[p] == true)
      for (int i = p * p; i <= 1e7; i += p) isPrime[i] = false;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> posi, negt;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x < 0)
      negt.push_back(x);
    else if (x > 0)
      posi.push_back(x);
  }
  sort(posi.begin(), posi.end(), greater<int>());
  sort(negt.begin(), negt.end());
  vector<int> temp;
  for (int i = 0; i < posi.size(); i += k) temp.push_back(posi[i]);
  for (int i = 0; i < negt.size(); i += k) temp.push_back(abs(negt[i]));
  sort(temp.begin(), temp.end());
  long long ans = 0;
  for (int i = 0; i < temp.size() - 1 && n > 1; ++i) ans += (2 * temp[i]);
  if (!temp.empty()) ans += temp.back();
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
