#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
long long rand_int(long long l, long long r) {
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<long long>(l, r)(gen);
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e % 2)
    return ((b * power((b) * (b), (e - 1) / 2)));
  else
    return power((b) * (b), e / 2);
}
long long modpower(long long b, long long e, long long q) {
  long long MOD = q;
  if (e == 0) return 1;
  if (e % 2)
    return ((b % MOD) * modpower((b % MOD) * (b % MOD), (e - 1) / 2, q)) % MOD;
  else
    return modpower((b % MOD) * (b % MOD), e / 2, q) % MOD;
}
void dpv(vector<long long> v) {
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << '\n';
}
void dpv(vector<pair<long long, long long> > v) {
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << '\n';
  }
}
void dpv(set<long long> v) {
  for (auto i : v) {
    cout << i << " ";
  }
  cout << '\n';
}
long long ceil1(long long x, long long y) {
  long long r = x / y;
  if (x % y == 0) {
    return r;
  } else {
    return r + 1;
  }
}
void oblivious() {
  long long n, h;
  cin >> n >> h;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    v.push_back(x);
  }
  long long l = 1;
  long long ans = -1;
  long long r = 1e18;
  while (l <= r) {
    long long mid = (l + r) / 2;
    long long i = 0;
    long long val = 0;
    while (i < n) {
      long long z = v[i] + mid;
      auto it = upper_bound(v.begin(), v.end(), z);
      it--;
      val += (*it - v[i]);
      long long ix = it - v.begin();
      if (ix == n - 1) {
        val += (mid);
        ix++;
        i = ix;
      } else if (i == ix) {
        val += mid;
        i++;
      } else {
        i = ix;
      }
    }
    if (val >= h) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    oblivious();
  }
  return 0;
}
