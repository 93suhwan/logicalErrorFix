#include <bits/stdc++.h>
using namespace std;
const int md = 1000000007;
long long int add(long long int a, long long int b) {
  return (a % md + b % md + md) % md;
}
long long int sub(long long int a, long long int b) {
  return (a % md + md - b % md) % md;
}
long long int mul(long long int a, long long int b) {
  return ((a % md) * (b % md) + md) % md;
}
const long long int INF = 1e18;
long long int dirA[] = {0, -1, 0, 1};
long long int dirB[] = {-1, 0, 1, 0};
long long int dirX[] = {0, -1, 0, 1, -1, -1, 1, 1};
long long int dirY[] = {-1, 0, 1, 0, -1, 1, -1, 1};
long long int power(long long int a, long long int b, long long int p) {
  if (a == 0) return 0;
  long long int res = 1;
  a %= p;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    b >>= 1;
    a = (a * a) % p;
  }
  return res;
}
long long int max(long long int a, long long int b) { return (a > b) ? a : b; }
long long int min(long long int a, long long int b) { return (a < b) ? a : b; }
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
vector<bool> is_prime(100000001, true);
vector<long long int> primes;
void isPrime() {
  long long int n = 1000000;
  is_prime[0] = is_prime[1] = false;
  for (long long int i = 2; i <= n; i++) {
    if (is_prime[i] && i * i <= n) {
      for (long long int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
}
bool sortbysec(const pair<long long int, long long int>& a,
               const pair<long long int, long long int>& b) {
  return (a.second < b.second);
}
vector<long long int> two;
vector<vector<long long int>> a;
vector<vector<vector<long long int>>> dp;
long long int fun(long long int i, long long int cnt,
                  vector<long long int> ans) {
  long long int m = a.size();
  long long int n = a[0].size();
  if (i == m || cnt == n - 1) {
    sort((ans).begin(), (ans).end());
    return ans[0];
  }
  if (dp[i][cnt][0] != -1 && dp[i][cnt][1] != -1) {
    return max(dp[i][cnt][0], dp[i][cnt][1]);
  }
  long long int res = fun(i + 1, cnt, ans);
  dp[i][cnt][0] = res;
  for (int j = 0; j < n; j++) {
    ans[j] = max(ans[j], a[i][j]);
  }
  long long int res2 = fun(i + 1, cnt + 1, ans);
  dp[i][cnt + 1][1] = res2;
  return max(res2, res);
}
void solve() {
  long long int m, n;
  cin >> m >> n;
  vector<long long int> ans;
  a.resize(m);
  dp.resize(m);
  ans.resize(n);
  for (long long int i = 0; i < n; i++) {
    ans[i] = 0;
  }
  for (long long int i = 0; i < m; i++) {
    a[i].resize(n);
    dp[i].resize(n);
    for (long long int j = 0; j < n; j++) {
      cin >> a[i][j];
      dp[i][j].resize(2);
      dp[i][j][0] = dp[i][j][1] = -1;
    }
  }
  long long int res = fun(0, 0, ans);
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  isPrime();
  long long int t = 1;
  cin >> t;
  long long int a = 1;
  while (t--) {
    solve();
  }
  return 0;
}
