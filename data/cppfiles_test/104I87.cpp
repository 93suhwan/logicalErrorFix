#include <bits/stdc++.h>
using namespace std;
const long long maxN = 100001;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<array<long long, 2> > v(n);
    long long mi = 0;
    long long ma = 0;
    long long toa = 0;
    long long tob = 0;
    vector<array<long long, 2> > rng(n);
    vector<long long> ans(n);
    for (long long i = 0; i < n; i++) {
      cin >> v[i][0] >> v[i][1];
      toa += v[i][0];
      tob += v[i][1];
      long long l = min((long long)m, max((long long)0, m - v[i][1]));
      long long r = min(m, v[i][0]);
      mi += l;
      ma += r;
      rng[i] = {l, r};
      ans[i] = l;
    }
    long long temp = toa - tob + m * n;
    mi *= 2;
    ma *= 2;
    long long tar;
    if (temp <= ma and temp >= mi) {
      if ((temp)&1) {
        if (temp - 1 >= mi and temp - 1 <= ma) {
          tar = temp - 1;
        } else {
          tar = temp + 1;
        }
        cout << 1;
      } else {
        tar = temp;
        cout << 0;
      }
    } else {
      if (abs(temp - ma) < abs(temp - mi))
        tar = ma;
      else
        tar = mi;
      cout << min(abs(temp - ma), abs(temp - mi));
    }
    long long til = mi;
    tar /= 2;
    for (long long i = 0; i < n; i++) {
      if (til + rng[i][1] - rng[i][0] < tar) {
        til += rng[i][1] - rng[i][0];
        ans[i] = rng[i][1];
      } else {
        til += tar - til;
        ans[i] += tar - til;
        break;
      }
    }
    cout << "\n";
    for (long long i = 0; i < n; i++) {
      cout << ans[i] << " " << m - ans[i] << "\n";
    }
    cout << "\n";
  }
}
