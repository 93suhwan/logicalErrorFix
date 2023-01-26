#include <bits/stdc++.h>
using namespace std;
bool isprime(long long k) {
  for (long long i = 2; i <= sqrt(k); i++)
    if (k % i == 0) return false;
  return true;
}
long long bm(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  long long t = bm(a, b / 2, mod);
  t = t * t % mod;
  return (b % 2 == 1 ? t * a % mod : t);
}
long long inv(long long a, long long mod) { return bm(a, mod - 2, mod); }
void gay(long long TC) { cout << "Case #" << TC << ": "; }
vector<long long> lis;
long long bs(long long x) {
  long long l = 0, r = lis.size() - 1;
  if (lis[r] <= x) return r + 1;
  if (lis[l] > x) return 0;
  while (l < r) {
    long long m = (l + r) / 2;
    if (lis[m] <= x)
      l = m + 1;
    else
      r = m;
  }
  return l;
}
void solve(long long TC) {
  long long n;
  cin >> n;
  long long arr[n + 5];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  for (long long i = 0; i < n; i++) arr[i] = i + 1 - arr[i];
  long long i = 0;
  while (i < n && !(arr[i] >= 0 && arr[i] <= i)) i++;
  lis.emplace_back(arr[i]);
  i++;
  for (; i < n; i++) {
    if (arr[i] < 0) continue;
    long long k = bs(arr[i]);
    if (arr[i] + k > i) continue;
    if (k == lis.size())
      lis.emplace_back(arr[i]);
    else
      lis[k] = arr[i];
  }
  cout << lis.size() << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
