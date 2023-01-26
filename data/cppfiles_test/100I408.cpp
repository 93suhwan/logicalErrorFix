#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long per[N];
const long long M = 998244353;
void precal() {
  per[1] = 1;
  for (long long i = 2; i < N; i++) {
    per[i] = ((per[i - 1]) % M * (i % M)) % M;
  }
}
int main() {
  long long t = 1;
  precal();
  scanf("%lld", &t);
  while (t--) {
    long long n, i, j, k, mx = 0, smx, cnt = 0, l, r, ans = 0;
    scanf("%lld", &n);
    vector<long long> v(n);
    map<long long, long long> mp;
    for (i = 0; i < n; i++) {
      scanf("%lld", &v[i]);
      mp[v[i]]++;
    }
    sort(v.rbegin(), v.rend());
    for (i = 1; i < n; i++) {
      if (v[i] == v[1] || v[i] == v[0]) cnt++;
    }
    if (v[0] - v[1] > 1) {
      printf("0\n");
      continue;
    }
    for (i = 0; i < n - 1; i++) {
      l = i;
      r = n - (i + 1);
      if (l >= cnt) {
        long long act = per[n - 1];
        long long ext = (((per[l]) % M) * (per[n - 1 - cnt] % M)) % M;
        long long baad = act - ext;
        if (baad < 0) baad += M;
        ans += baad;
      } else {
        ans += per[n - 1];
        ans %= M;
      }
    }
    ans = ((ans % M) * (mp[v[0]] % M)) % M;
    if (mp[v[0]] > 1) ans = per[n];
    printf("%lld\n", ans);
  }
}
