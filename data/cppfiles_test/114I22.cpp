#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353, maxn = 200030;
int aabs(int x) {
  if (x < 0) return -x;
  return x;
}
long long pow(long long x, long long a) {
  long long now = 1;
  while (a) {
    if (a % 2) now = now * x % mod;
    x = x * x % mod;
    a >>= 1;
  }
  return now;
}
int n, m;
vector<long long> a[11];
struct node {
  int val = 0;
  int tag[11] = {0};
  bool operator<(const node &rhs) const { return val > rhs.val; }
};
multiset<node> ss;
multiset<node> ttag;
void insert(node tmp) {
  node ntmp = tmp;
  for (int i = 1; i <= n; i++) {
    if (ntmp.tag[i] > 1) {
      ntmp.tag[i]--;
      ntmp.val = ntmp.val + a[i][ntmp.tag[i]] - a[i][ntmp.tag[i] + 1];
      if (ss.find(ntmp) == ss.end()) {
        if (ttag.find(ntmp) != ttag.end())
          insert(ntmp);
        else
          ss.insert(ntmp);
      }
      ntmp = tmp;
    }
  }
}
int main() {
  scanf("%d", &n);
  node tmp;
  memset(tmp.tag, 0, sizeof(tmp.tag));
  for (int i = 1; i <= n; i++) {
    int ci;
    scanf("%d", &ci);
    a[i].emplace_back(0);
    for (int j = 1; j <= ci; j++) {
      int now;
      scanf("%d", &now);
      a[i].emplace_back(now);
    }
    tmp.val += a[i][ci];
    tmp.tag[i] = ci;
  }
  ss.insert(tmp);
  int m;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    tmp.val = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &tmp.tag[i]);
      tmp.val += a[i][tmp.tag[i]];
    }
    ttag.insert(tmp);
    if (ss.find(tmp) != ss.end()) {
      ss.erase(tmp);
      insert(tmp);
    }
  }
  set<node>::iterator iter = ss.begin();
  for (int i = 1; i <= n; i++) printf("%d ", iter->tag[i]);
  return 0;
}
