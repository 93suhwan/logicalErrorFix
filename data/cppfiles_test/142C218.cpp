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
void solve() {
  long long int m, n;
  cin >> m >> n;
  vector<vector<long long int> > joy(m, vector<long long int>(n, 0));
  for (long long int i = 0; i < m; i++) {
    for (long long int j = 0; j < n; j++) {
      cin >> joy[i][j];
    }
  }
  long long int lo = 0, hi = INF, mid = 0;
  long long int ans = 0;
  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;
    set<long long int> s;
    bool valid = false, shops = false;
    for (long long int i = 0; i < n; i++) {
      valid = false;
      for (long long int j = 0; j < m; j++) {
        if (joy[j][i] >= mid) {
          valid = true;
          if (s.count(j)) {
            shops = true;
          }
          s.insert(j);
        }
      }
      if (!valid) break;
    }
    if (valid && shops) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  cout << ans << "\n";
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
