#include <bits/stdc++.h>
using namespace std;
int tt, n;
vector<int> a[200005];
priority_queue<int, vector<int>, greater<int> > pq;
queue<int> q;
int du[200005];
int main() {
  cin >> tt;
  while (tt--) {
    while (pq.size()) pq.pop();
    while (q.size()) q.pop();
    cin >> n;
    for (int i = 1; i <= n; i++) a[i].clear();
    for (int i = 1; i <= n; i++) {
      int k;
      scanf("%d", &k);
      du[i] = k;
      if (k == 0) pq.push(i);
      for (int j = 1; j <= k; j++) {
        int u;
        scanf("%d", &u);
        a[u].push_back(i);
      }
    }
    int cnt = 0;
    int ls = 1;
    while (pq.size()) {
      int t = pq.top();
      pq.pop();
      cnt++;
      for (int j = 0; j <= (int)a[t].size() - 1; j++) {
        du[a[t][j]]--;
        if (du[a[t][j]] <= 0) {
          if (a[t][j] > t)
            pq.push(a[t][j]);
          else
            q.push(a[t][j]);
        }
      }
      if (pq.size() == 0 && q.size()) {
        ls++;
        while (q.size()) {
          pq.push(q.front());
          q.pop();
        }
      }
    }
    if (cnt == n)
      cout << ls << endl;
    else
      cout << "-1" << endl;
  }
  return 0;
}
