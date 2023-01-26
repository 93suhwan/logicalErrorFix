#include <bits/stdc++.h>
using namespace std;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
pair<long long, long long> inv_help(long long a, long long b) {
  pair<long long, long long> res;
  res.first = 1;
  res.second = 0;
  if (b == 0)
    return res;
  else {
    pair<long long, long long> res1 = inv_help(b, a % b);
    res.first = res1.second;
    res.second = res1.first - (a / b) * res1.second;
    return res;
  }
}
long long inv(long long a, long long b) {
  pair<long long, long long> res = inv_help(a, b);
  long long x = res.first;
  if (x > 0) x = x % b;
  if (x < 0) x = (b - (-x) % b) % b;
  return x;
}
vector<int> l;
int N;
int binsearch(int p, int l_bnd) {
  int i = l_bnd, j = N - 1, k;
  if (l_bnd > N - 1) return -1;
  if (l[N - 1] < p)
    return -1;
  else if (l[i] > p)
    return i;
  else {
    while (i != j) {
      k = (i + j) / 2;
      if (i == j) {
        return i;
      } else if (i == j - 1) {
        if (l[i] == p)
          return i;
        else
          return i + 1;
      } else if (l[k] < p) {
        i = k + 1;
      } else if (l[k] >= p) {
        j = k;
      }
    }
    return i;
  }
}
vector<long long> fact(2000001, 1);
long long nCr(int n, int r) {
  if (n < 0 || r < 0) return 0;
  if (n < r) return 0;
  long long a1 = fact[n];
  long long a2 = fact[n - r];
  long long a3 = fact[r];
  long long ans =
      (((a1 * inv(a2, 998244353)) % 998244353) * inv(a3, 998244353)) %
      998244353;
  return ans;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int sorted(vector<int>& v, int n) {
  for (int i = 1; i <= n - 1; i++) {
    if (v[i] < v[i - 1]) return 0;
  }
  return 1;
}
long long pow(int n) {
  if (n == 0) return 1;
  long long k = pow(n / 2);
  if (n % 2 == 1)
    return (((2 * k) % 998244353) * k) % 998244353;
  else
    return (k * k) % 998244353;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  int tt = T;
  for (int i = 1; i <= 2000000; i++) fact[i] = (fact[i - 1] * i) % 998244353;
  while (T--) {
    int n;
    cin >> n;
    int ans = n;
    n++;
    ans -= n / 10;
    cout << n - ans - 1 << "\n";
  }
}
