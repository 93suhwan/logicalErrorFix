#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
queue<int> q;
priority_queue<int, vector<int>, greater<int> > q1;
int h[N], ne[N], e[N], idx = 0, d[N];
void add(int a, int b) {
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx++;
}
void solve() {
  int n, sum = 0, all = 0, i, j, b;
  idx = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    h[i] = -1;
    d[i] = 0;
  }
  for (i = 1; i <= n; ++i) {
    scanf("%d", &d[i]);
    for (j = 1; j <= d[i]; ++j) {
      scanf("%d", &b);
      add(b, i);
    }
    if (d[i] == 0) {
      q1.push(i);
      all++;
    }
  }
  while (q1.size()) {
    sum++;
    while (q1.size()) {
      int k = q1.top();
      q1.pop();
      for (i = h[k]; i != -1; i = ne[i]) {
        d[e[i]]--;
        if (d[e[i]] == 0) {
          all++;
          if (e[i] < k) {
            q.push(e[i]);
          } else {
            q1.push(e[i]);
          }
        }
      }
    }
    while (q.size()) {
      int k = q.front();
      q.pop();
      q1.push(k);
    }
  }
  if (all == n)
    printf("%d\n", sum);
  else
    printf("-1\n");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
