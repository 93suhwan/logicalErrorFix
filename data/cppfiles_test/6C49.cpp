#include <bits/stdc++.h>
const long long INF = 1000000001;
const long long MOD = 1000000007;
using namespace std;
vector<vector<long long>> del;
vector<long long> was, num;
long long C = 0;
long long sum_gcd_fast(vector<long long> &a, long long cnt) {
  vector<long long> all;
  for (long long q : a) {
    for (long long q1 : del[q]) {
      if (was[q1] != cnt) {
        was[q1] = cnt, num[q1] = 0;
        all.push_back(q1);
      }
      num[q1]++;
    }
  }
  for (long long q : all) {
    num[q] = num[q] * num[q];
  }
  sort(all.rbegin(), all.rend());
  long long ans = 0;
  for (long long q : all) {
    ans += num[q] * q;
    for (long long q1 : del[q]) {
      num[q1] -= num[q];
    }
  }
  return ans;
}
void prepare() {
  del.resize(C), was.assign(C, -1), num.assign(C, 0);
  for (long long q = 1; q < C; q++) {
    for (long long q1 = q; q1 < C; q1 += q) {
      del[q1].push_back(q);
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n;
  cin >> n;
  C = n + 1;
  vector<long long> a(n + 1);
  for (long long q = 1; q <= n; q++) {
    cin >> a[q];
    C = max(C, a[q] + 1);
  }
  prepare();
  vector<long long> sums(n + 1);
  long long cnt = 0;
  for (long long q = 1; q <= n; q++) {
    vector<long long> now;
    for (long long q1 = q; q1 <= n; q1 += q) {
      now.push_back(a[q1]);
    }
    sums[q] = sum_gcd_fast(now, cnt++);
  }
  long long ans = 0;
  for (long long q = n; q > 0; q--) {
    ans += sums[q] % MOD * q % MOD;
    for (long long q1 : del[q]) {
      if (q1 != q) {
        sums[q1] -= sums[q];
      }
    }
  }
  cout << ans % MOD << '\n';
  return 0;
}
