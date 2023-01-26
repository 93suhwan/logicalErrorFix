#include <bits/stdc++.h>
using namespace std;
vector<int> pri;
int n, k, a[200010], b[200010], spe, tot;
struct point {
  int x, y, id;
} poi[200010];
bool cmp(point one, point ano) {
  if (one.x != ano.x)
    return one.x < ano.x;
  else
    return one.y < ano.y;
}
int flag;
const long double eps = 1e-8, INF = 1e18;
long double getso(int x, int y) { return (b[x] - b[y]) * 1.0 / (a[x] - a[y]); }
bool eq(long double one, long double ano) { return fabs(one - ano) < eps; }
long double tonxt[200010], ans = INF;
long double getdis(int one, int ano) {
  return sqrt((poi[one].x - poi[ano].x) * (poi[one].x - poi[ano].x) +
              (poi[one].y - poi[ano].y) * (poi[one].y - poi[ano].y));
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &a[i], &b[i]);
    pri.push_back(a[i]);
  }
  sort(pri.begin(), pri.end());
  pri.erase(unique(pri.begin(), pri.end()), pri.end());
  if (pri.size() == 2) {
    for (int i = 1; i <= n; ++i) {
      if (a[i] == pri[0]) ++flag;
    }
    if (flag == 1) {
      for (int i = 1; i <= n; ++i) {
        if (a[i] == pri[0]) {
          spe = i;
          break;
        }
      }
    } else {
      for (int i = 1; i <= n; ++i) {
        if (a[i] == pri[1]) {
          spe = i;
          break;
        }
      }
    }
  } else {
    if (n == 3)
      spe = 1;
    else {
      for (int i = 3; i <= n; ++i) {
        if (eq(getso(1, i), getso(2, i))) ++flag;
      }
      if (flag) {
        for (int i = 3; i <= n; ++i) {
          if (!eq(getso(1, i), getso(2, i))) {
            spe = i;
            break;
          }
        }
      } else {
        if (eq(getso(2, 3), getso(2, 4)))
          spe = 1;
        else
          spe = 2;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (i != spe) {
      poi[++tot].x = a[i];
      poi[tot].y = b[i];
      poi[tot].id = i;
    }
  }
  sort(poi + 1, poi + 1 + tot, cmp);
  poi[++tot].x = a[spe];
  poi[tot].y = b[spe];
  if (k == spe) {
    ans = min(ans, getdis(tot, 1) + getdis(1, tot - 1));
    ans = min(ans, getdis(tot, tot - 1) + getdis(1, tot - 1));
  } else {
    for (int i = 1; i < tot; ++i) {
      if (poi[i].id == k) {
        k = i;
        break;
      }
    }
    ans = min(ans, getdis(k, tot) + getdis(tot, 1) + getdis(1, tot - 1));
    ans = min(ans, getdis(k, tot) + getdis(tot, tot - 1) + getdis(1, tot - 1));
    if (k > 1)
      ans = min(ans, getdis(k, tot - 1) + getdis(tot - 1, tot) +
                         getdis(tot, k - 1) + getdis(1, k - 1));
    if (k < tot - 1)
      ans = min(ans, getdis(k, 1) + getdis(1, tot) + getdis(tot, k + 1) +
                         getdis(k + 1, tot - 1));
    for (int i = k; i < tot - 1; ++i) {
      ans = min(ans, getdis(k, i) + getdis(i, tot) + getdis(tot, i + 1) +
                         getdis(i + 1, tot - 1) + getdis(tot - 1, 1));
      ans = min(ans, getdis(k, i) + getdis(i, tot) + getdis(tot, i + 1) +
                         getdis(i + 1, 1) + getdis(tot - 1, 1));
      ans = min(ans, getdis(k, 1) + getdis(1, i) + getdis(i, tot) +
                         getdis(tot, i + 1) + getdis(i + 1, tot - 1));
    }
    for (int i = k; i > 1; --i) {
      ans = min(ans, getdis(k, i) + getdis(i, tot) + getdis(tot, i - 1) +
                         getdis(i - 1, 1) + getdis(1, tot - 1));
      ans = min(ans, getdis(k, i) + getdis(i, tot) + getdis(tot, i - 1) +
                         getdis(i - 1, tot - 1) + getdis(1, tot - 1));
      ans = min(ans, getdis(k, tot - 1) + getdis(tot - 1, i) + getdis(i, tot) +
                         getdis(tot, i - 1) + getdis(i - 1, 1));
    }
    ans = min(ans, getdis(k, 1) + getdis(1, tot - 1) + getdis(tot - 1, tot));
    ans = min(ans, getdis(k, tot - 1) + getdis(1, tot - 1) + getdis(1, tot));
  }
  printf("%.10Lf\n", ans);
  return 0;
}
