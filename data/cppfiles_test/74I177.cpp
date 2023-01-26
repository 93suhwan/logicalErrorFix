#include <bits/stdc++.h>
using namespace std;
long long int mul(long long int a, long long int b) {
  return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
}
long long int add(long long int a, long long int b) {
  return (a % 1000000007 + b % 1000000007) % 1000000007;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int extgcd(long long int a, long long int b, long long int& x,
                     long long int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long int x1, y1;
  long long int d = extgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool isPowerOfTwo(long long int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
vector<long long int> factors(long long int n) {
  vector<long long int> f;
  for (long long int x = 2; x * x <= n; x++) {
    while (n % x == 0) {
      f.push_back(x);
      n /= x;
    }
  }
  if (n > 1) f.push_back(n);
  return f;
}
long long int bin_exp_mod(long long int a, long long int n) {
  long long int res = 1;
  a %= 1000000007;
  if (a == 0) return 0;
  while (n > 0) {
    if (n & 1) res = ((res % 1000000007) * (a % 1000000007)) % 1000000007;
    n = n >> 1;
    a = ((a % 1000000007) * (a % 1000000007)) % 1000000007;
  }
  res %= 1000000007;
  return res;
}
void solve() {
  long long int n, m, k;
  cin >> n;
  vector<vector<long long> > arr;
  vector<long long> v;
  vector<pair<long long, long long> > vp;
  long long int sm = 0, x, mx;
  vector<long long> a;
  for (long long int i = 0; i < n; i++) {
    cin >> k;
    sm = mx = 0;
    v.clear();
    for (long long int j = 0; j < k; j++) {
      cin >> x;
      v.push_back(x);
      sm += x;
      mx = max(mx, x + 1 - (j));
    }
    vp.push_back({mx, i});
    arr.push_back(v);
  }
  sort(vp.begin(), vp.end());
  long long int hp = 0;
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < arr[vp[i].second].size(); j++) {
      ans += max({0ll, arr[vp[i].second][j] + 1 - hp});
      hp = max(hp, arr[vp[i].second][j] + 1);
      hp++;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
