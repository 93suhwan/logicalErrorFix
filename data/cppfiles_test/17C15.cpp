#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
vector<long long> fenw;
void upd(long long i) {
  for (; i < fenw.size(); i += i & -i) {
    ++fenw[i];
  }
}
long long get(long long i) {
  long long res = 0;
  for (; i > 0; i -= i & -i) {
    res += fenw[i];
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    fenw.clear();
    fenw.resize(n + 1);
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<long long> b = a;
    sort(b.begin(), b.end());
    map<long long, long long> MAP;
    long long cnt = 1;
    for (long long x : b) {
      if (MAP[x]) continue;
      MAP[x] = cnt++;
    }
    for (long long i = 0; i < n; ++i) {
      a[i] = MAP[a[i]];
    }
    long long ans = 0;
    for (long long i = 0; i < n; ++i) {
      long long kol_men = get(a[i] - 1), kol_men_ravn = get(a[i]);
      ans += min(kol_men, i - kol_men_ravn);
      upd(a[i]);
    }
    cout << ans << '\n';
    ;
  }
  return 0;
}
