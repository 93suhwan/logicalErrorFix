#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count() +
            reinterpret_cast<unsigned long>(new long long) +
            *(new unsigned long));
void eraseDups(vector<long long>& a) {
  a.erase(unique(a.begin(), a.end()), a.end());
}
long long strToInt(string& a) {
  stringstream x(a);
  long long b;
  x >> b;
  return b;
}
long long bitCnt(long long a) {
  bitset<64> b(a);
  return b.count();
}
long long bitCnt(string a) {
  bitset<64> b(a);
  return b.count();
}
vector<long long> readVI(long long n) {
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  return a;
}
vector<vector<long long> > readVVI(long long n, long long m) {
  vector<vector<long long> > a(n, vector<long long>(m));
  for (long long i = 0; i < n; i++) a[i] = readVI(m);
  return a;
}
vector<long long> readVLL(long long n) {
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  return a;
}
vector<vector<long long> > readVVLL(long long n, long long m) {
  vector<vector<long long> > a(n, vector<long long>(m));
  for (long long i = 0; i < n; i++) a[i] = readVLL(m);
  return a;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void print(vector<long long>& a) {
  for (auto el : a) {
    cout << el << ' ';
  }
  cout << '\n';
}
void print(vector<pair<long long, long long> >& a) {
  for (auto el : a) {
    cout << el.first << ',' << el.second << ' ';
  }
  cout << '\n';
}
void print(vector<long long>& a, long long n) {
  long long cnt = 0;
  for (auto el : a) {
    if (cnt++ == n) break;
    cout << el << ' ';
  }
  cout << '\n';
}
void print(vector<vector<long long> >& a) {
  for (auto el : a) {
    print(el);
  }
}
const long long INF = 2e9;
const long long INFF = INT64_MAX;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long dx[] = {-1, 0, 1, 0};
const long long dy[] = {0, 1, 0, -1};
long long n, MOD;
const long long N = 4e6 + 5;
vector<long long> dp(N, 0);
inline long long mul(long long a, long long b) {
  return (long long)a * (long long)b % MOD;
}
inline long long add(long long a, long long b) {
  return (((long long)a + long long(b)) % MOD + MOD) % MOD;
}
void go() {
  cin >> n >> MOD;
  dp[1] = 1;
  for (long long i = 2; i <= n; i++) {
    dp[i] = add(dp[i], (i == 2 ? 2 : dp[i - 1] * 2 + 1));
    for (long long k = 2; i * k <= n; k++)
      dp[i * k] = add(dp[i * k], dp[i] - dp[i - 1]);
  }
  cout << dp[n] << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  while (T--) go();
  return 0;
}
