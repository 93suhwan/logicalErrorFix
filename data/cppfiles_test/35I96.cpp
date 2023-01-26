#include <bits/stdc++.h>
using namespace std;
const int ma = 1e6, inf = 1e9;
int n, nn[1000069], a[1000069];
vector<pair<int, int>> fz[1000069], sk[1000069];
bitset<1000069> spc;
multiset<int> ms;
int main() {
  int i, j, k, w, sz, c, u, ww, z = 0;
  char ch;
  for (i = 2; i <= ma; i++) {
    sz = fz[i].size();
    if (!sz) {
      for (j = i; j <= ma; j += i) {
        for (c = 0, k = j; k % i == 0; k /= i, c++)
          ;
        fz[j].push_back({i, c});
      }
      sk[i].push_back({-1, -inf});
      sk[i].push_back({0, 0});
      nn[i] = 1;
      ms.insert(-1);
    }
  }
  scanf("%d", &n);
  for (i = n; i; i--) {
    scanf("%d", a + i);
  }
  for (i = n; i; i--) {
    scanf(" %c", &ch);
    spc[i] = ch == '/';
  }
  for (i = 1; i <= n; i++) {
    u = spc[i] * 2 - 1;
    sz = fz[a[i]].size();
    for (j = 0; j < sz; j++) {
      k = fz[a[i]][j].first;
      w = fz[a[i]][j].second;
      sk[k][nn[k]].first = i - 1;
      ms.erase(ms.find(sk[k][nn[k] - 1].first));
      ww = sk[k][nn[k]].second + w * u;
      for (; nn[k] && sk[k][nn[k]].second >= ww; sk[k].pop_back(), nn[k]--)
        ;
      ms.insert(sk[k][nn[k]].first);
      sk[k].push_back({i, ww});
      nn[k]++;
    }
    z += i - 1 - *prev(ms.end());
  }
  printf("%d\n", z);
}
