#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long int t) { cerr << t; }
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
int min(int arg_count, ...) {
  int i;
  int Min, a;
  va_list ap;
  va_start(ap, arg_count);
  Min = va_arg(ap, int);
  for (i = 2; i <= arg_count; i++)
    if ((a = va_arg(ap, int)) < Min) Min = a;
  va_end(ap);
  return Min;
}
int max(int arg_count, ...) {
  int i;
  int Max, a;
  va_list ap;
  va_start(ap, arg_count);
  Max = va_arg(ap, int);
  for (i = 2; i <= arg_count; i++)
    if ((a = va_arg(ap, int)) > Max) Max = a;
  va_end(ap);
  return Max;
}
template <typename T>
T Exgcd(T a, T b, T &x, T &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  T x1, y1;
  T d = Exgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
template <typename T>
T modpow(T x, T n, T p) {
  if (n == 0) return 1 % p;
  T y = 0;
  if (n % 2 == 0) {
    y = modpow(x, n / 2, p);
    y = (y * y) % p;
  } else {
    y = x % p;
    y = (y * modpow(x, n - 1, p)) % p;
  }
  return (int)((y + p) % p);
}
template <typename T>
T ModInv(T a, T m) {
  T x, y;
  Exgcd(a, m, x, y);
  return (x % m + m) % m;
}
template <typename T>
bool IsPrime(T n) {
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
const long long maxNN = 100005;
long long fact[maxNN];
void pre(long long M) {
  fact[0] = 1;
  for (int i = 1; i < maxNN; i++) fact[i] = (i * fact[i - 1]) % M;
}
long long nCk(long long n, long long r, long long M) {
  long long ans = 1;
  ans = (ans * fact[n]) % M;
  ans = (ans * ModInv(fact[n - r], M)) % M;
  ans = (ans * ModInv(fact[r], M)) % M;
  return M;
}
int find(int n, vector<int> &parent) {
  if (parent[n] < 0) return n;
  return parent[n] = find(parent[n], parent);
}
void Union(int a, int b, vector<int> &parent, vector<int> &rank) {
  int l1 = find(a, parent);
  int l2 = find(b, parent);
  if (l1 == l2) return;
  if (rank[l1] < rank[l2]) {
    parent[l1] = l2;
    rank[l2] += rank[l1];
  } else {
    parent[l2] = l1;
    rank[l1] += rank[l2];
  }
}
int get_component_size(int u, vector<int> rank, vector<int> parent) {
  u = find(u, parent);
  return rank[u];
}
int func(string a, string b) {
  int cnt = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[i]) cnt++;
  }
  return cnt;
}
bool iscomposite(string str) {
  return str == "25" || str == "27" || str == "22" || str == "35" ||
         str == "32" || str == "33" || str == "52" || str == "57" ||
         str == "55" || str == "72" || str == "75" || str == "77";
}
bool isin(char ch) {
  return ch == '1' || ch == '4' || ch == '6' || ch == '8' || ch == '9';
}
void solve() {
  int k;
  cin >> k;
  string str;
  cin >> str;
  for (int i = 0; i < k; i++) {
    if (isin(str[i])) {
      cout << 1 << endl << str[i] << endl;
      return;
    }
  }
  for (int i = 0; i < k - 1; i++) {
    for (int j = i + 1; j < k; j++) {
      string ans = "";
      ans = str[i];
      ans += str[j];
      if (iscomposite(ans)) {
        cout << 2 << endl << ans << endl;
        return;
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
