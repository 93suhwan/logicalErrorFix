#include <bits/stdc++.h>
using namespace std;
int t;
struct node {
  int x;
  int pos;
} s[200005];
struct cmp {
  bool operator()(node a, node b) { return a.x < b.x; }
};
int l[200005] = {0};
int r[200005] = {0};
priority_queue<node, vector<node>, cmp> q;
int main() {
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 0;
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    if (!q.empty()) {
      q.pop();
    }
    for (int i = 1; i <= n; i++) {
      cin >> s[i].x;
      s[i].pos = i;
      if (s[i].x >= 1) q.push(s[i]);
    }
    while (q.size() >= 2) {
      node a = q.top();
      q.pop();
      node b = q.top();
      q.pop();
      l[++ans] = min(a.pos, b.pos);
      r[ans] = max(a.pos, b.pos);
      a.x--;
      b.x--;
      if (a.x >= 1) q.push(a);
      if (b.x >= 1) q.push(b);
    }
    cout << ans << endl;
    for (int i = 1; i <= ans; i++) {
      cout << l[i] << " " << r[i] << endl;
    }
  }
  return 0;
}
