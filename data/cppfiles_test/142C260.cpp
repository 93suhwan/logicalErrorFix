#include <bits/stdc++.h>
using namespace std;
#pragma warning disable format
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
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long powm(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
void extendgcd(long long a, long long b, long long* v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  long long x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
}
long long mminv(long long a, long long b) {
  long long arr[3];
  extendgcd(a, b, arr);
  return arr[0];
}
long long mminvprime(long long a, long long b) { return powm(a, b - 2, b); }
vector<long long> sieve(int n) {
  int* arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
vector<string> split(string s, char delimeter) {
  vector<string> tokens;
  stringstream check1(s);
  string intermediate;
  while (getline(check1, intermediate, delimeter)) {
    tokens.push_back(intermediate);
  }
  return tokens;
}
void toLower(string& s) { transform(s.begin(), s.end(), s.begin(), ::tolower); }
void toUpper(string& s) { transform(s.begin(), s.end(), s.begin(), ::toupper); }
long long addm(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mulm(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long subm(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long divm(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (mulm(a, mminvprime(b, m), m) + m) % m;
}
const long long SIZE = 2;
long long fact[SIZE], ifact[SIZE];
void gen_factorial(long long n, long long mod) {
  fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
  for (long long i = 2; i <= n; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
  ifact[n] = mminvprime(fact[n], mod);
  for (long long i = n - 1; i >= 2; i--) {
    ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
  }
}
long long choose(long long n, long long r, long long m) {
  long long val1 = fact[n];
  long long val2 = ifact[n - r];
  long long val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}
long long i, j, k;
const int MOD = 1000000007;
const int MOD1 = 998244353;
#pragma warning restore format
bool isPossible(long long joy, vector<vector<long long> >& p, int n, int m) {
  set<int> visited;
  if ((m <= n - 1)) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (p[i][j] >= joy) visited.insert(j);
      }
    }
    return (visited.size() == n);
  }
  int index = -1;
  for (int i = 0; i < m; i++) {
    int count = 0;
    for (int j = 0; j < n; j++) {
      if (p[i][j] >= joy) count++;
    }
    if (count >= 2) {
      index = i;
      break;
    }
  }
  if (index == -1) return false;
  for (int j = 0; j < n; j++) {
    if (p[index][j] >= joy) visited.insert(j);
  }
  for (int i = 0; i < m; i++) {
    bool flag = false;
    if (i == index) continue;
    for (int j = 0; j < n; j++) {
      if ((p[i][j] >= joy) && (visited.find(j) == visited.end())) {
        flag = true;
        break;
      }
    }
    if (!flag) continue;
    for (int j = 0; j < n; j++) {
      if (p[i][j] >= joy) visited.insert(j);
    }
  }
  return (visited.size() == n);
}
void solve() {
  int n, m;
  cin >> m >> n;
  vector<vector<long long> > p(m, vector<long long>(n));
  long long low = 0, high, maxE = 0;
  for (int i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      cin >> p[i][j];
      maxE = max(maxE, p[i][j]);
    }
  };
  high = maxE;
  long long ans = 0;
  while (low <= high) {
    ;
    int mid = (low + high) / 2;
    ;
    if (isPossible(mid, p, n, m)) {
      ans = mid;
      low = mid + 1;
    } else
      high = mid - 1;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
