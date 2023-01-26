#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void _print(int x) { cerr << x; }
void _print(float x) { cerr << x; }
void _print(string x) { cerr << x; }
void _print(ll x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(bool x) { cerr << x; }
template <class T, class V>
void _print(pair<T, V> x) {
  cerr << "[";
  _print(x.first);
  cerr << " ";
  _print(x.second);
  cerr << "]";
}
template <class T>
void _print(vector<T> x) {
  cerr << "[ ";
  for (int i = 1; i < x.size() + 1; ++i) {
    cerr << "(" << i - 1 << ")";
    _print(x[i - 1]);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> x) {
  cerr << "[ ";
  for (T i : x) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> x) {
  cerr << "[ ";
  for (T i : x) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(priority_queue<T, vector<T>, greater<T>> x) {
  cerr << "[ ";
  while (!x.empty()) {
    _print(x.top());
    cerr << " ";
    x.pop();
  }
  cerr << "]";
}
template <class T>
void _print(priority_queue<T> x) {
  cerr << "[ ";
  while (!x.empty()) {
    _print(x.top());
    cerr << " ";
    x.pop();
  }
  cerr << "]";
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U> p) {
  os << p.first << ' ' << p.second;
  return os;
}
template <typename T, typename U>
istream& operator>>(istream& is, vector<pair<T, U>>& p) {
  for (auto& i : p) {
    is >> i.first >> i.second;
  }
  return is;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, vector<pair<T, U>>& p) {
  for (auto& i : p) {
    os << i.first << " " << i.second << endl;
  }
  return os;
}
template <typename T>
pair<T, bool> getNthElement(set<T>& searchSet, int index) {
  pair<T, bool> result;
  if (searchSet.size() > index) {
    result.first = *(std::next(searchSet.begin(), index));
    result.second = true;
  } else
    result.second = false;
  return result;
}
template <typename T>
istream& operator>>(istream& is, set<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, set<T> v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
const ll mod = 1e9 + 7;
const int N = 5e4 + 20;
template <typename T, typename U>
ll modMul(T a, U b) {
  return ((a % mod) * 1LL * (b % mod)) % mod;
}
template <typename T, typename U>
ll binpower(T n, U k) {
  T res = 1;
  while (k) {
    if (k & 1) {
      res = modMul(res, n);
    }
    n = modMul(n, n);
    k >>= 1;
  }
  return res % mod;
}
template <typename T>
T moduloInverse(T a) {
  return binpower(a, mod - 2);
}
template <typename T, typename U>
ll modAdd(T a, U b) {
  return ((a % mod) + (b % mod)) % mod;
}
template <typename T, typename U>
ll modSub(T a, U b) {
  return ((a % mod) - (b % mod) + mod) % mod;
}
template <typename T, typename U>
ll modDiv(T a, U b) {
  return modMul(a, moduloInverse(b));
}
void precision(int a) { cout << setprecision(a) << fixed; }
void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  cin >> A;
  int k = binpower(3, n);
  for (int i = 1; i < k; ++i) {
    int a = i;
    int sum = 0;
    for (int j = 0; j < n; ++j) {
      int d = a % 3;
      if (d == 1) sum += A[j];
      if (d == 2) sum -= A[j];
      a /= 3;
    }
    if (sum == 0) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
void initialise() { return; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  initialise();
  for (int i = 1; i < t + 1; ++i) {
    solve();
  }
  return 0;
}
