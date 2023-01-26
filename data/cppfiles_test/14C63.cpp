#include <bits/stdc++.h>
using namespace std;
long long mod1 = 998244353, mod2 = 1000000007, limit = 9223372036854775807;
long double pi = 3.1415926535897932;
long long modpow(long long x, long long n, long long m) {
  if (x > m) {
    x %= m;
  }
  if (n == 0) return 1 % m;
  long long u = modpow(x, n / 2, m);
  u = (u * u) % m;
  if (n % 2 == 1) u = (u * x) % m;
  return u;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool isprime(long long n) {
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long power(long long x, long long n) {
  if (n < 0) {
    return 0;
  }
  long long x_n = 1;
  for (long long i = 0; i < n; i++) {
    x_n *= x;
  }
  return x_n;
}
int n, k, mid;
int arr[2005];
int dp[2005][2005];
int getans(int pos, int index) {
  if (pos == n) {
    if (n - index <= mid) {
      return 0;
    }
    return INT_MIN;
  }
  if (dp[pos][index] != -1) {
    return dp[pos][index];
  }
  int ans = INT_MIN;
  if (getans(pos + 1, index) != INT_MIN) {
    ans = getans(pos + 1, index);
  }
  int score = 0;
  if (arr[pos] == index + 1) {
    score = 1;
  }
  if (getans(pos + 1, index + 1) != INT_MIN) {
    ans = max(ans, score + getans(pos + 1, index + 1));
  }
  return dp[pos][index] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int l = 0, r = n - 1;
    int ans = -1;
    while (l <= r) {
      mid = (l + r) / 2;
      for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
          dp[i][j] = -1;
        }
      }
      if (getans(0, 0) >= k) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans << endl;
  }
}
