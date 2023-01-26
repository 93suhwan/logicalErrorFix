#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
vector<long long> psum;
vector<long long> cnt;
long long calc(long long l, long long r) {
  long long items = cnt[r] - cnt[l - 1];
  return psum[r] - psum[r - items];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, i, j, ans, temp, sum, x, m, q;
  string sans;
  t = 1;
  while (t--) {
    sans = "NO";
    ans = temp = sum = 0;
    cin >> n >> m >> q;
    vector<pair<long long, long long> > v = {{0, 0}};
    for (i = 1; i <= n; i++) {
      cin >> x;
      v.push_back({x, 1});
      ans += x;
    }
    for (i = 1; i <= m; i++) {
      cin >> x;
      v.push_back({x, 0});
    }
    psum.assign(n + m + 1, 0);
    cnt.assign(n + m + 1, 0);
    sort((v).begin() + 1, (v).end());
    for (i = 1; i <= n + m; i++) {
      psum[i] = psum[i - 1] + v[i].first;
      cnt[i] = cnt[i - 1] + v[i].second;
    }
    set<pair<long long, long long> > diff;
    for (i = 1; i <= n + m - 1; i++) {
      diff.insert({v[i + 1].first - v[i].first, i});
    }
    set<pair<long long, long long> > ranges;
    for (i = 1; i <= n + m; i++) ranges.insert({i, i});
    vector<pair<long long, long long> > query(q + 1);
    for (i = 1; i <= q; i++) {
      cin >> query[i].first;
      query[i].second = i;
    }
    sort((query).begin() + 1, (query).end());
    vector<long long> ansvec(q + 1);
    for (i = 1; i <= q; i++) {
      while ((long long)diff.size() > 0 and
             diff.begin()->first <= query[i].first) {
        long long leftl, leftr, rightl, rightr;
        temp = diff.begin()->second;
        diff.erase(diff.begin());
        auto itr = ranges.upper_bound({temp, temp});
        auto itl = prev(itr);
        leftl = itl->first;
        leftr = itl->second;
        rightl = itr->first;
        rightr = itr->second;
        ans -= calc(leftl, leftr) + calc(rightl, rightr);
        ans += calc(leftl, rightr);
        ranges.erase({leftl, leftr});
        ranges.erase({rightl, rightr});
        ranges.insert({leftl, rightr});
      }
      ansvec[query[i].second] = ans;
    }
    for (i = 1; i <= q; i++) cout << ansvec[i] << '\n';
  }
  return 0;
}
