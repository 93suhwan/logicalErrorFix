#include <bits/stdc++.h>
using namespace std;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int maxn = 5e5 + 7, inf = 0x3f3f3f3f, mod = 1e9 + 7;
struct node {
  int s, a;
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, d;
  cin >> n >> d;
  vector<node> v1, v2;
  for (int i = 0, s, a; i < n; ++i) {
    cin >> s >> a;
    if (s > a)
      v1.push_back({s, a});
    else
      v2.push_back({s, a});
  }
  sort(v1.begin(), v1.end(), [&](node x, node y) { return x.s < y.s; });
  sort(v2.begin(), v2.end(), [&](node x, node y) { return x.a < y.a; });
  int ans = 0;
  int sz1 = v1.size(), sz2 = v2.size(), j = 0;
  for (int i = 0; i < sz1; ++i) {
    while (j < sz2 && v2[j].a <= v1[i].s) {
      if (v2[j].s >= d) {
        ans++;
        d = max(v2[j].a, d);
      }
      j++;
    }
    if (v1[i].s >= d) {
      ans++;
      d = max(v1[i].a, d);
    }
  }
  while (j < sz2) {
    if (v2[j].s >= d) {
      ans++;
      d = max(v2[j].a, d);
    }
    j++;
  }
  cout << ans << '\n';
  return 0;
}
