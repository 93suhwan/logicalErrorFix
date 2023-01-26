#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <typename T>
void print(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << '\n';
}
template <typename T>
void print(vector<vector<T>>& v) {
  for (vector<T>& vv : v) {
    for (T& i : vv) cout << i << " ";
    cout << '\n';
  }
}
template <typename T>
void read(vector<T>& v) {
  for (T& i : v) cin >> i;
}
template <typename T>
void read(T&& t) {
  cin >> t;
}
template <typename T, typename... Args>
void read(T&& t, Args&&... args) {
  cin >> t;
  read(forward<Args>(args)...);
}
template <typename T>
void print(T&& t) {
  cout << t << '\n';
}
template <typename T, typename... Args>
void print(T&& t, Args&&... args) {
  cout << t << " ";
  print(forward<Args>(args)...);
}
template <typename T>
vector<T>& operator--(vector<T>& v) {
  for (auto& i : v) --i;
  return v;
}
template <typename T>
vector<T>& operator++(vector<T>& v) {
  for (auto& i : v) ++i;
  return v;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
long double pie = 3.141592653589793238462643383279502884197169399;
long long mod = 1e9 + 7;
bool isprime(long long n) {
  if (n <= 1) {
    return false;
  }
  if (n <= 3) {
    return true;
  }
  if (n % 2 == 0 || n % 3 == 0) {
    return false;
  }
  for (long long i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
long long modInverse(long long n, long long mod) {
  return binpow(n, mod - 2, mod);
}
long long comb(long long n, long long r, long long p, vector<long long>& fac) {
  if (r == 0 or n == r) return 1;
  if (r > n) return 0;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
set<long long> divisors(long long n) {
  set<long long> s;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      s.insert(i);
      s.insert(n / i);
    }
  }
  return s;
}
long long add(long long a, long long b, long long mod) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long mul(long long a, long long b, long long mod) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long sub(long long a, long long b, long long mod) {
  a = a % mod;
  b = b % mod;
  return (((a - b) % mod) + mod) % mod;
}
map<long long, long long> primeFactors(long long n) {
  map<long long, long long> m;
  while (n % 2 == 0) {
    m[2]++;
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      m[i]++;
      n = n / i;
    }
  }
  if (n > 2) m[n]++;
  return m;
}
long long C(long long n, long long r) {
  long long res = 1;
  for (long long i = 0; i < r; i++) {
    res = res * (n - i) / (i + 1);
  }
  return res;
}
long long toint(string s) {
  long long num = 0;
  for (long long i = 0; i < s.size(); i++) {
    num = num * 10 + s[i] - '0';
  }
  return num;
}
long long sumstring(string s) {
  long long sum = 0;
  for (long long i = 0; i < s.size(); i++) {
    sum += (s[i] - '0');
  }
  return sum;
}
long long sumdigit(long long n) {
  long long sum = 0;
  while (n) {
    long long rem = n % 10;
    sum += rem;
    n /= 10;
  }
  return sum;
}
string tobinary(long long x) {
  string a;
  while (x > 0) {
    a += (x % 2) + '0';
    x /= 2;
  }
  reverse(begin(a), end(a));
  return a;
}
long long todecimal(string x) {
  long long sum = 0;
  long long n = x.size();
  long long j = 0;
  for (long long i = n - 1; i >= 0; i--) {
    if (x[i] == '1') {
      sum += (1LL << j);
    }
    j++;
  }
  return sum;
}
long long ceil(long long n, long long k) { return (n + k - 1) / k; }
bool ispalin(string s) {
  long long n = s.size();
  for (long long i = 0; i < n; i++) {
    if (s[i] != s[n - i - 1]) {
      return false;
    }
  }
  return true;
}
bool ispermutation(vector<long long> p) {
  sort(begin(p), end(p));
  for (long long i = 1; i <= p.size(); i++) {
    if (p[i - 1] != i) return false;
  }
  return true;
}
bool isperfect(long long x) {
  long long a = sqrtl(x);
  return a * a == x;
}
bool issubsequence(string t, string x) {
  long long j = 0;
  for (long long i = 0; i < x.size(); i++) {
    if (x[i] == t[j]) {
      j++;
    }
    if (j == t.size()) break;
  }
  return j == t.size();
}
long long power(long long base, long long exponent) {
  long long res = 1;
  while (exponent) {
    if (exponent & 1) {
      res = res * base;
    }
    base *= base;
    exponent >>= 1;
  }
  return res;
}
bool comp(string s1, string s2) {
  for (long long i = 0; i < s1.size(); i++) {
    if (s1[i] == s2[i]) continue;
    return s1[i] < s2[i];
  }
  return false;
}
double area(double dX0, double dY0, double dX1, double dY1, double dX2,
            double dY2) {
  double dArea = ((dX1 - dX0) * (dY2 - dY0) - (dX2 - dX0) * (dY1 - dY0)) / 2.0;
  return (dArea > 0.0) ? dArea : -dArea;
}
long long C(long long n, long long r, long long mod) {
  long long ans = 1;
  if (n - r < r) r = n - r;
  for (long long i = n; i > n - r; i--) ans = mul(ans, i, mod);
  for (long long i = 1; i <= r; i++) ans = mul(ans, modInverse(i, mod), mod);
  return ans;
}
struct Cmp {
  bool operator()(const array<long long, 2>& l,
                  const array<long long, 2>& r) const {
    if (l[0] == r[0]) return l[1] < r[1];
    return l[0] < r[0];
  }
};
void loop() {
  long long n;
  cin >> n;
  vector<vector<long long>> adj(n + 1);
  vector<long long> indegree(n + 1);
  long long total = n;
  for (long long i = 1; i <= n; i++) {
    long long z;
    cin >> z;
    for (long long j = 0; j < z; j++) {
      long long x;
      cin >> x;
      indegree[i]++;
      adj[x].push_back(i);
    }
  }
  vector<long long> vis(n + 1);
  queue<long long> q;
  for (long long i = 1; i <= n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
      vis[i] = 1;
    }
  }
  vector<long long> order;
  while (q.size()) {
    long long x = q.front();
    q.pop();
    total--;
    order.push_back(x);
    for (auto i : adj[x]) {
      indegree[i]--;
      if (indegree[i] == 0) q.push(i);
    }
  }
  if (total) {
    print(-1);
    return;
  } else {
    vector<long long> dp(n + 1, 1);
    for (auto i : order) {
      for (auto j : adj[i]) {
        if (j < i) {
          dp[j] = max(dp[j], dp[i] + 1);
        } else
          dp[j] = max(dp[j], dp[i]);
      }
    }
    print(*max_element(begin(dp), end(dp)));
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    loop();
  }
}
