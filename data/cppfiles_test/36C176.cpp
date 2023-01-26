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
bool isprime(long long n) {
  bool found = true;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      found = false;
      break;
    }
  }
  return found;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += v[i];
  bool found = false;
  for (int i = 2; i <= sqrt(sum); i++) {
    if (sum % i == 0) {
      found = true;
      break;
    }
  }
  if (found) {
    cout << n << endl;
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << endl;
    return;
  }
  if (n == 2) {
    if (v[0] == 2 && isprime(v[1]))
      cout << "0" << endl;
    else if (v[1] == 2 && isprime(v[0]))
      cout << "0" << endl;
    else if (v[0] == 2) {
      cout << "1" << endl;
      cout << "2" << endl;
    } else if (v[1] == 2) {
      cout << "1" << endl;
      cout << "1" << endl;
    }
  }
  int ind = -1;
  for (int i = 0; i < n; i++) {
    if (v[i] % 2 == 1) {
      ind = i;
      break;
    }
  }
  cout << n - 1 << endl;
  for (int i = 0; i < n; i++) {
    if (i != ind) cout << i + 1 << " ";
  }
  cout << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  cin >> test;
  for (int i = 1; i <= test; i++) {
    solve();
  }
}
