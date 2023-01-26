#include <bits/stdc++.h>
using namespace std;
vector<long long> p[1000005];
multiset<long long> s1, s2, s3, s4;
struct xt {
  long long val;
  long long id;
} x[1000005];
bool cmp(xt a, xt b) { return a.val < b.val; }
long long color[1000005];
int main() {
  long long t, n, m, i, j, k;
  cin >> t;
NXT:
  while (t--) {
    cin >> n >> m;
    s1.clear(), s2.clear(), s3.clear(), s4.clear();
    for (i = 0; i <= n + 2; i++) {
      p[i].clear();
      p[i].push_back(0);
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        scanf("%lld", &k);
        p[i].push_back(k);
      }
    }
    long long mn = 1e17, mnpos = 0, mx = -1e17, mxpos = 0;
    for (i = 1; i <= n; i++) {
      if (mn > p[i][1]) {
        mn = p[i][1];
        mnpos = i;
      }
      if (mx < p[i][1]) {
        mx = p[i][1];
        mxpos = i;
      }
    }
    long long fd = -1;
    for (i = 2; i <= m; i++) {
      if (p[mnpos][i] > p[mxpos][i]) {
        fd = i - 1;
        break;
      }
    }
    if (fd == -1) {
      printf("NO\n");
      continue;
    }
    for (i = 1; i <= n; i++) {
      x[i].val = p[i][1];
      x[i].id = i;
    }
    sort(x + 1, x + 1 + n, cmp);
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        if (j <= fd) s1.insert(p[x[i].id][j]);
        if (j > fd) s3.insert(p[x[i].id][j]);
      }
    }
    for (i = 1; i <= n - 1; i++) {
      for (j = 1; j <= m; j++) {
        if (j <= fd) {
          s1.erase(s1.find(p[x[i].id][j]));
          s2.insert(p[x[i].id][j]);
        } else {
          s3.erase(s3.find(p[x[i].id][j]));
          s4.insert(p[x[i].id][j]);
        }
      }
      if ((*s1.begin() > *s2.rbegin()) && (*s4.begin() > *s3.rbegin())) {
        long long rb = i;
        printf("YES\n");
        for (i = 1; i <= n; i++) {
          color[x[i].id] = (i <= rb ? 1 : 0);
        }
        for (i = 1; i <= n; i++) {
          printf("%c", color[i] ? 'B' : 'R');
        }
        printf(" %lld\n", fd);
        goto NXT;
      }
    }
    printf("NO\n");
  }
  return 0;
}
