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
const int N = 2e5 + 10;
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
int ar[5][N];
vector<string> A;
int curr;
bool comp(int a, int b) {
  int cnt_a = 2 * ar[curr][a] - A[a].length();
  int cnt_b = 2 * ar[curr][b] - A[b].length();
  return cnt_a > cnt_b;
}
void solve() {
  int n;
  cin >> n;
  A.clear();
  ((A).resize(n));
  cin >> A;
  vector<int> B(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      ar[j][i] = 0;
    }
  }
  for (int i = 0; i < n; ++i) B[i] = i;
  for (int i = 0; i < n; ++i) {
    for (auto j : A[i]) {
      ar[j - 'a'][i]++;
    }
  }
  ll ans = 0;
  for (curr = 0; curr < 5; ++curr) {
    sort((B).begin(), (B).end(), comp);
    ll cnt = 0, calc = 0;
    for (int i = 0; i < n; ++i) {
      int a = calc + ar[curr][B[i]], b = A[B[i]].length() - ar[curr][B[i]];
      if (a > b) {
        cnt++;
        calc += 2 * ar[curr][B[i]] - A[B[i]].length();
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << "\n";
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
