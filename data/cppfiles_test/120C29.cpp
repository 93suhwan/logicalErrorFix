#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
const int rN = 1e5 + 1;
constexpr long double PI = 3.141592653589793238462;
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) {
  return (istream >> p.first >> p.second);
}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v) {
  for (auto &it : v) cin >> it;
  return istream;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) {
  return (ostream << p.first << " " << p.second);
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
  for (auto &it : c) cout << it << " ";
  return ostream;
}
bool prime[N];
void process() {
  for (int i = 2; i < N; i++) prime[i] = true;
  prime[0] = prime[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (prime[i] == true) {
      for (int j = i * i; j < N; j += i) {
        prime[j] = false;
      }
    }
  }
}
long long power(long long a, long long n, long long num) {
  long long res = a;
  long long x = 1;
  while (n) {
    if (n % 2 == 1) x = (x * res) % num;
    res = (res * res) % num;
    n /= 2;
  }
  return x % num;
}
long long inverse(long long n, long long num) { return power(n, num - 2, num); }
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int dp[31][200001];
void solve() {
  int l, r;
  cin >> l >> r;
  int ans = INT_MAX;
  for (int i = 0; i < 31; i++) {
    ans = min(ans, dp[i][r] - dp[i][l - 1]);
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  memset((dp), 0, sizeof((dp)));
  int temp;
  int idx;
  for (int i = 1; i < 200001; i++) {
    for (int j = 0; j < 31; j++) {
      dp[j][i] += dp[j][i - 1] + (!(i & (1 << j)));
    }
  }
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
