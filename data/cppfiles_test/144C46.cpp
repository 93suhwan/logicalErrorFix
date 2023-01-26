#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, z;
pair<int, int> pr;
int main() {
  scanf("%d", &t);
  while (t--) {
    priority_queue<pair<int, int> > q, tmp;
    vector<int> pot;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) q.push({0, i});
    x = n / m, y = n, z = m;
    while (y) {
      y -= x, z--;
      pot.push_back(x);
      if (y % (x + 1) == 0 && y / (x + 1) == z) {
        while (y) {
          y -= (x + 1);
          pot.push_back(x + 1);
        }
      }
    }
    sort(pot.rbegin(), pot.rend());
    while (k--) {
      for (int tbl = 0; tbl < pot.size(); tbl++) {
        printf("%d ", pot[tbl]);
        for (int p = 0; p < pot[tbl]; p++) {
          pr = q.top();
          q.pop();
          if (pot[tbl] == x)
            tmp.push(pr);
          else
            tmp.push({--pr.first, pr.second});
          printf("%d%c", pr.second, " \n"[p == pot[tbl] - 1]);
        }
      }
      while (tmp.size()) {
        q.push(tmp.top());
        tmp.pop();
      }
    }
    puts("");
  }
  return 0;
}
