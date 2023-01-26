#include <bits/stdc++.h>
using namespace std;
int P[100005];
int find_(int x) {
  if (x == P[x])
    return x;
  else
    return P[x] = find_(P[x]);
}
void union_(int x, int y) { P[find_(x)] = find_(y); }
int t, n, m, a, b, c;
vector<pair<int, int> > v;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) P[i] = 0;
    for (int i = 1; i <= m; i++) {
      scanf("%d%d%d", &a, &b, &c);
      P[b] = 1;
    }
    for (int i = 1; i <= n; i++) {
      if (P[i] == 0) {
        for (int j = 1; j <= n; j++) {
          if (i != j) printf("%d %d\n", i, j);
        }
        break;
      }
    }
  }
}
