#include <bits/stdc++.h>
using namespace std;
using INT = long long;
using pii = pair<int, int>;
const int NN = 330300;
int A[NN], B[NN];
int dis[NN], nt[NN];
vector<int> buf[NN];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", A + i);
  for (int i = 1; i <= n; i++) scanf("%d", B + i);
  for (int i = 1; i <= n; i++) {
    buf[i + B[i]].push_back(i);
    dis[i] = 1e9;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (A[i] >= i) {
      q.push(i);
      nt[i] = 0;
      dis[i] = 1;
    }
  set<pii> res;
  for (int i = 1; i <= n; i++) {
    if (A[i] < i) res.insert(pii(i - A[i], i));
  }
  while (q.size()) {
    int u = q.front();
    q.pop();
    if (u == n) break;
    for (int v : buf[u]) {
      while (!res.empty()) {
        auto it = res.begin();
        if (it->first > v) break;
        if (it->second < v) {
          res.erase(it);
          continue;
        }
        int vv = it->second;
        if (dis[vv] > dis[u] + 1) {
          q.push(vv);
          res.erase(it);
          nt[vv] = v;
          dis[vv] = dis[u] + 1;
          continue;
        }
      }
    }
  }
  if (dis[n] >= 1e9)
    puts("-1");
  else {
    cout << dis[n] << endl;
    int x = n;
    while (x) {
      printf("%d ", nt[x]);
      x = nt[x];
      x += B[x];
    }
  }
  return 0;
}
