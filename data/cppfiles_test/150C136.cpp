#include <bits/stdc++.h>
int n;
vector<int> v;
int ans;
void test(int one, int two) {
  int tans = 0;
  bitset<64> cover = 1;
  loop(i, 1, one) cover |= (cover << 1);
  loop(i, 1, two) cover |= (cover << 2);
  for (auto v : ::v) {
    roop(i, one + two + two, 0) if (cover[i] && i <= v && (v - i) % 3 == 0) {
      tans = max(tans, (v - i) / 3);
      goto ok;
    }
    return;
  ok:;
  }
  ans = min(ans, tans + one + two);
}
signed main() {
  int T;
  cin >> (T);
  loop(kase, 1, T) {
    cin >> n;
    v.resize(n);
    for (auto& vv : v) cin >> vv;
    ans = INT32_MAX;
    loop(i, 0, 2) loop(j, 0, 6) test(i, j);
    cout << ans << '\n';
  }
  return 0;
}
