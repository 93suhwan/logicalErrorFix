#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
struct node {
  int val;
  int id;
  bool operator<(const node &b) const { return val < b.val; }
};
bool vis[N + 5], visa[N + 5], visb[N + 5];
int main() {
  int t, n, x;
  scanf("%d", &t);
  while (t--) {
    priority_queue<node> a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      vis[i] = 0;
      visa[i] = visb[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x);
      a.push((node){x, i});
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x);
      b.push((node){x, i});
    }
    node tp = a.top();
    a.pop();
    vis[tp.id] = 1;
    visa[tp.id] = 0;
    int ta = 0, tb = 1;
    while (ta || tb) {
      while (ta) {
        node tp = a.top();
        a.pop();
        visa[tp.id] = 0;
        if (vis[tp.id]) {
          ta--;
          continue;
        } else {
          vis[tp.id] = 1;
          if (visb[tp.id]) tb++;
        }
      }
      while (tb) {
        node tp = b.top();
        b.pop();
        visb[tp.id] = 0;
        if (vis[tp.id]) {
          tb--;
          continue;
        } else {
          vis[tp.id] = 1;
          if (visa[tp.id]) ta++;
        }
      }
    }
    for (int i = 1; i <= n; i++)
      if (vis[i])
        printf("YES\n");
      else
        printf("NO\n");
  }
  return 0;
}
