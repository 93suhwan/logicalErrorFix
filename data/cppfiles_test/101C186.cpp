#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
char b[N];
struct node {
  int l, r;
} p[N];
bool cmp(node x, node y) { return x.l < y.l; }
priority_queue<int, vector<int>, greater<int> > q;
void work() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%s", b + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] <= 0) {
      if (b[i] == 'R')
        p[i].l = 1, p[i].r = n;
      else {
        puts("NO");
        return;
      }
    } else if (a[i] > n) {
      if (b[i] == 'B')
        p[i].l = 1, p[i].r = n;
      else {
        puts("NO");
        return;
      }
    } else if (b[i] == 'R')
      p[i].l = a[i], p[i].r = n;
    else
      p[i].l = 1, p[i].r = a[i];
  }
  while (!q.empty()) q.pop();
  sort(p + 1, p + n + 1, cmp);
  for (int i = 1, j = 1; i <= n; i++) {
    while (j <= n && p[j].l <= i) q.push(p[j].r), j++;
    if (q.empty()) {
      puts("NO");
      return;
    }
    int x = q.top();
    q.pop();
    if (x < i) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}
int main() {
  int T;
  cin >> T;
  while (T--) work();
  return 0;
}
