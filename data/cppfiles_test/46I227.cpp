#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
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
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
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
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
bool IsPrime(long long number) {
  if (number <= 1) return false;
  if (number == 2 || number == 3) return true;
  if (number % 2 == 0 || number % 3 == 0) return false;
  for (long long i = 5; i * i <= number; i += 2) {
    if (number % i == 0) return false;
  }
  return true;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> seq, arr;
  long long elem = -1;
  for (long long i = 0; i < n; i++) {
    long long m;
    cin >> m;
    seq.push_back(m);
    if (i == 0)
      elem = m;
    else
      elem = max(elem, m);
    arr.push_back(m);
  }
  long long elem2 = -1;
  for (int i = 0; i < n; i++) {
    if (seq[i] > elem2 and seq[i] != elem) {
      elem2 = seq[i];
    }
  }
  sort((arr).begin(), (arr).end());
  if (seq[n - 1] == elem) {
    cout << 0 << "\n";
    return;
  }
  long long ind1 = 0, ind2 = 0;
  for (int i = 0; i < n; i++) {
    if (seq[i] == elem) ind1 = i;
    if (seq[i] == elem2) ind2 = i;
  }
  long long ans = LLONG_MAX;
  if (ind2 < ind1) {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
      if (i >= ind1 and seq[i] > seq.back()) {
        cnt++;
      }
    }
    cout << cnt << "\n";
  } else {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
      if (i >= ind2 and seq[i] > seq.back()) {
        cnt++;
      }
    }
    cout << cnt + 1 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
