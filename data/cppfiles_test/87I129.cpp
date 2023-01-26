#include <bits/stdc++.h>
using namespace std;
int x[5] = {0, 1, 0, -1};
int y[5] = {1, 0, -1, 0};
long long a[500010], b[500010];
map<long long, long long> mp, vis;
vector<long long> v;
vector<pair<long long, long long> > vp;
string s, q;
char c;
int main() {
  long long t, n, k, m, l, r, mn = 0, mx = 0, sum = 0, nm = 0, cnt = 0, x, y, z,
                              ans;
  int cs = 0;
  scanf("%lld", &t);
  while (t--) {
    v.clear();
    ans = 0;
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < m; i++) {
      scanf("%lld", &a[i]);
      v.push_back(a[i]);
      long long p = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
      ans += p;
    }
    printf("%lld", ans);
    printf("\n");
    ;
  }
}
