#include <bits/stdc++.h>
using namespace std;
const long long N = 1e11;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  set<long long> two[11];
  for (long long tt = 1; tt < N; tt *= 2) {
    long long num = tt, cnt = 0;
    while (num) {
      two[cnt].insert(num);
      num /= 10;
      cnt++;
    }
  }
  map<long long, long long> ans;
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    if (ans.count(n)) {
      cout << ans[n] << '\n';
      continue;
    }
    long long num = n, len = 0;
    vector<long long> a;
    while (num) {
      len++;
      a.push_back(num % 10);
      num /= 10;
    }
    reverse(a.begin(), a.end());
    long long val = len + 1;
    for (long long mask = 0; mask < (1ll << len); ++mask) {
      long long cur = 0, del = 0, flg = 0;
      for (long long i = 0; i < (len); ++i)
        if (mask & (1ll << i)) {
          if (!a[i] and !cur) flg = 1;
          cur = cur * 10 + a[i];
        } else
          del++;
      if (flg) continue;
      for (long long i = 0; i < (11); ++i) {
        if (two[i].count(cur)) {
          val = min(val, del + i);
          break;
        }
      }
    }
    ans[n] = val;
    cout << val << '\n';
  }
  return 0;
}
