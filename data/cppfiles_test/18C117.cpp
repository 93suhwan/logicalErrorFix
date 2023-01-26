#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, d;
    scanf("%d%d", &n, &d);
    vector<int> a(n);
    for (int& i : a) scanf("%d", &i);
    vector<int> qu, dist(n, -1);
    for (int i = 0; i < n; i++)
      if (a[i] == 0) {
        qu.push_back(i);
        dist[i] = 0;
      }
    for (int i = 0; i < (int)qu.size(); i++) {
      int u = qu[i];
      int v = (u + d) % n;
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        qu.push_back(v);
      }
    }
    if (qu.size() != n)
      puts("-1");
    else
      printf("%d\n", *max_element(dist.begin(), dist.end()));
  }
}
