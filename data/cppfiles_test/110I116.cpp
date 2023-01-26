#include <bits/stdc++.h>
using namespace std;
long long prr[] = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,
                   41,  43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,
                   97,  101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151,
                   157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223,
                   227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
                   283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359,
                   367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
                   439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};
long long powmod(long long a, long long b, long long modulo) {
  if (b == 0 || a == 1) return 1;
  long long half = powmod(a, (b / 2), modulo) % modulo;
  long long full = (half * half) % modulo;
  if (b % 2) return (full * a) % modulo;
  return full % modulo;
}
long long invmod(long long a, long long modulo) {
  long long check = powmod(a, modulo - 2, modulo) % modulo;
  return check;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
bool isPrime[5000005];
int prime[5000005];
void sieve(long long N) {
  for (long long i = 0; i <= N; ++i) {
    isPrime[i] = true;
  }
  isPrime[0] = false;
  isPrime[1] = false;
  for (int i = 2; i * i <= N; ++i) {
    if (isPrime[i] == true) {
      for (int j = i * i; j <= N; j += i) isPrime[j] = false;
    }
  }
  int j = 0;
  for (int i = 2; i <= N; i++) {
    if (isPrime[i]) {
      prime[j] = i;
      j++;
    }
  }
}
unsigned long long nCrFermat(unsigned long long n, int r, int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  unsigned long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * invmod(fac[r], p) % p * invmod(fac[n - r], p) % p) % p;
}
bool palindrome(string s) {
  for (long long i = 0; i < (long long)s.length() / 2; i++) {
    if (s[i] != s[s.length() - i - 1]) return 0;
  }
  return 1;
}
void solve() {
  int n;
  cin >> n;
  vector<int> indegree(n + 1);
  vector<pair<int, int> > adj[n + 5];
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int a;
      cin >> a;
      if (a < i + 1)
        adj[a].push_back({i + 1, 0});
      else
        adj[a].push_back({i + 1, 1});
      indegree[i + 1]++;
    }
  }
  queue<int> q;
  int dp[n + 5];
  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0) q.push(i), dp[i] = 0;
  }
  int c = 0;
  int ans = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    bool flag = false;
    for (auto it : adj[u]) {
      if (--indegree[it.first] == 0)
        q.push(it.first), dp[it.first] = max(dp[u] + it.second, dp[it.first]);
    }
    c++;
  }
  if (c != n) {
    cout << -1 << "\n";
  } else {
    int mx = *max_element(dp, dp + n + 5);
    cout << max(1, mx + 1) << "\n";
  }
}
int main() {
  clock_t start, end;
  start = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  end = clock();
  double time = double(end - start) / (double)(CLOCKS_PER_SEC);
  return 0;
}
