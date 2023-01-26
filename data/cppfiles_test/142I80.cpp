#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.141592653589793238463;
inline bool checkBit(long long n, long long i) {
  return n & ((long long)1 << i);
}
inline long long setBit(long long n, long long i) {
  return n | ((long long)1 << i);
}
inline long long resetBit(long long n, long long i) {
  return n & (~((long long)1 << i));
}
inline void normal(long long& a) { a = (a + 1000000007) % 1000000007; }
inline long long modMul(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a * b) % 1000000007;
}
inline long long modAdd(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a + b) % 1000000007;
}
inline long long modSub(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInv(long long a) { return modPow(a, 1000000007 - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInv(b));
}
inline long long fact(long long r) {
  long long ans = 1;
  while (r) ans = modMul(ans, r), r--;
  return ans;
}
inline long long invfact(long long r) {
  long long ans = 1;
  while (r) ans = modMul(ans, modInv(r)), r--;
  return ans;
}
inline double dgcd(double a, double b) {
  if (a < b) return dgcd(b, a);
  if (b < .0001) return a;
  return dgcd(b, fmod(a, b));
}
inline long long toint(const std::string& s) {
  std::stringstream ss;
  ss << s;
  long long x;
  ss >> x;
  return x;
}
inline std::string tostring(long long number) {
  std::stringstream ss;
  ss << number;
  return ss.str();
}
inline std::string tobin(long long x) { return std::bitset<63>(x).to_string(); }
clock_t start;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& q) {
  in >> q.first >> q.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& q) {
  out << q.first << " " << q.second;
  return out;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(pair<T1, T2> p1, pair<T1, T2> p2) {
  return {p1.first + p2.first, p1.second + p2.second};
}
template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> p1, pair<T1, T2> p2) {
  return {p1.first - p2.first, p1.second - p2.second};
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <typename T>
T allmin(T t) {
  return t;
}
template <typename T, typename... Args>
T allmin(T t, Args... args) {
  return min(t, allmin(args...));
}
template <typename T>
T allmax(T t) {
  return t;
}
template <typename T, typename... Args>
T allmax(T t, Args... args) {
  return max(t, allmax(args...));
}
template <typename T>
void Unique(vector<T>& v) {
  sort((v).begin(), (v).end()),
      v.resize(distance(v.begin(), unique((v).begin(), (v).end())));
}
const long long N = 2e5;
const long long INF = 2e18;
long long power(long long base, long long exp) {
  long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base) % 1000000007;
    base = (base * base) % 1000000007;
    exp /= 2;
  }
  return res % 1000000007;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void Timelimitexceeded() {
  long long m, n;
  cin >> m >> n;
  long long p[m][n];
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> p[i][j];
    }
  }
  long long lo = 0, hi = 1e9;
  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    string temp[m];
    for (long long i = 0; i < m; i++) {
      string curr = "";
      for (long long j = 0; j < n; j++) {
        curr += ('0' + ((p[i][j] < mid) ? 0 : 1));
      }
      temp[i] = curr;
    }
    sort(temp, temp + m);
    long long pos[n];
    memset(pos, 0, sizeof(pos));
    for (long long i = 0; i < min(m, n - 1); i++) {
      for (long long j = 0; j < n; j++) {
        pos[j] += (temp[m - 1 - i][j] - '0');
      }
    }
    bool flag = true;
    for (long long i = 0; i < n; i++)
      if (pos[i] == 0) flag = false;
    if (flag) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  cout << lo - 1 << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  clock_t start, end;
  start = clock();
  cout << fixed << setprecision(20);
  cin >> t;
  while (t--) {
    Timelimitexceeded();
  }
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
}
