#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourDirection = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int>> eightDirection = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                                      {1, 0},  {1, -1}, {0, -1}, {-1, -1}};
long long int mod(long long int n, long long int M) { return (n % M + M) % M; }
long long int modAdd(long long int a, long long int b, long long int M) {
  return mod(mod(a, M) + mod(b, M), M);
}
long long int modMul(long long int a, long long int b, long long int M) {
  return mod(mod(a, M) * mod(b, M), M);
}
long long int modMinus(long long int a, long long int b, long long int M) {
  return mod(mod(a, M) - mod(b, M), M);
}
long long int modpow(long long int x, long long int n, long long int M) {
  if (n == 0) return 1 % M;
  if (n == 1) return x % M;
  long long int u = modpow(x, n / 2, M);
  u = modMul(u, u, M);
  if (n % 2) u = modMul(u, x, M);
  return u;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int extendedGcd(long long int a, long long int b, long long int &x,
                          long long int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long int x1, y1;
  long long int g = extendedGcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}
long long int modInverse(long long int a, long long int m) {
  long long int g, x, y;
  g = extendedGcd(a, m, x, y);
  if (g == 1) {
    return (x % m + m) % m;
  }
  return -1;
}
long long int modDiv(long long int a, long long int b, long long int M) {
  long long int inverse = modInverse(b, M);
  return modMul(inverse, a, M);
}
long long int crt(vector<long long int> &P, vector<long long int> &R) {
  int n = P.size();
  vector<long long int> X(n);
  long long int productOfAllP = 1;
  for (int i = 0; i < n; i++) productOfAllP *= P[i];
  for (int i = 0; i < n; i++) {
    X[i] = R[i];
    long long int mulOfInverse = 1;
    long long int mul = 1;
    for (int j = 0; j < i; j++) {
      mulOfInverse = modMul(mulOfInverse, modInverse(P[j], P[i]), P[i]);
      X[i] = modMinus(X[i], modMul(X[j], mul, P[i]), P[i]);
      mul = modMul(mul, P[j], P[i]);
    }
    X[i] = modMul(X[i], mulOfInverse, P[i]);
  }
  long long int finalX = 0;
  long long int mul = 1;
  for (int i = 0; i < n; i++) {
    finalX = modAdd(finalX, modMul(X[i], mul, productOfAllP), productOfAllP);
    mul = modMul(mul, P[i], productOfAllP);
  }
  return finalX;
}
bool isPrime(long long int n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
int getParent(vector<int> &parent, int s) {
  if (parent[s] == s) return s;
  return getParent(parent, parent[s]);
}
vector<int> primeNumbers;
void sieve() {
  int limit = 1e5;
  vector<bool> prime(limit, true);
  for (long long int i = 2; i < limit; i++) {
    if (prime[i]) {
      primeNumbers.push_back(i);
      for (long long int j = i * i; j < limit; j = j + i) prime[j] = false;
    }
  }
}
vector<pair<int, int>> primeFactors(long long int tQ) {
  vector<pair<int, int>> pf;
  for (int i = 2; i * i <= tQ; i++) {
    if (tQ % i == 0) {
      int cnt = 0;
      while (tQ % i == 0) {
        cnt += 1;
        tQ /= i;
      }
      pf.push_back({i, cnt});
    }
  }
  if (tQ != 1) {
    pf.push_back({tQ, 1});
  }
  return pf;
}
bool insideGrid(int x, int y, int n, int m) {
  if (x >= 0 && x < n && y >= 0 && y < m) return true;
  return false;
}
void solve() {
  int n;
  cin >> n;
  vector<int> data(n + 1);
  for (int i = 1; i <= n; i++) cin >> data[i];
  int inf = 2001;
  vector<vector<int>> dp(n + 1, vector<int>(2001, inf));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 2000; j++) {
      int new_j = max(0, j - data[i + 1]);
      int inc = max(data[i + 1] - j, 0);
      dp[i + 1][new_j] = min(dp[i + 1][new_j], dp[i][j] + inc);
      new_j = j + data[i + 1];
      inc = max(0, new_j - dp[i][j]);
      if (new_j <= 2000)
        dp[i + 1][new_j] = min(dp[i + 1][new_j], dp[i][j] + inc);
    }
  }
  int ans = inf;
  for (int i = 0; i <= 2000; i++) ans = min(ans, dp[n][i]);
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
