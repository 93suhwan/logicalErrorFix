#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b, m, id;
};
node qi[200010];
pair<pair<int, int>, int> pi[200010];
int pos[200010];
bool cmp(node ai, node bi) { return ai.a + ai.b - ai.m < bi.a + bi.b - bi.m; }
bool cmp1(node ai, node bi) { return ai.a < bi.b; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int a, b, m;
      cin >> a >> b >> m;
      qi[i] = {a, b, m, i};
    }
    sort(qi + 1, qi + 1 + n, cmp);
    int j = 1;
    int res = 0;
    while (j <= n) {
      int tt = 0;
      pi[++tt] = {{max(qi[j].a - qi[j].m, 0), qi[j].a}, qi[j].id};
      j++;
      while (j <= n && (qi[j].a + qi[j].b - qi[j].m) ==
                           (qi[j - 1].a + qi[j - 1].b - qi[j].m)) {
        pi[++tt] = {{max(qi[j].a - qi[j].m, 0), qi[j].a}, qi[j].id};
        j++;
      }
      sort(pi + 1, pi + 1 + tt);
      int cur = 1e9;
      for (int i = tt; i >= 1; i--) {
        if (cur > pi[i].first.second) {
          cur = pi[i].first.first;
          res++;
        }
        pos[pi[i].second] = cur;
      }
    }
    cout << res << endl;
    for (int i = 1; i <= n; i++) {
      cout << qi[i].a - pos[i] << " " << qi[i].m - (qi[i].a - pos[i]) << endl;
    }
  }
  return 0;
}
