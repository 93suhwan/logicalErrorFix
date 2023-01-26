#include <bits/stdc++.h>
using namespace std;
int a[1 << 20];
struct Node {
  Node* ch[2];
  int ans;
  int mi1, mi2;
} node[1 << 21];
int ans[1 << 20];
int tot = 0;
void pushUp(Node* rt, int level) {
  rt->mi1 = 1e9;
  rt->mi2 = 1e9;
  rt->ans = 1e9;
  if (rt->ch[0])
    rt->mi1 = rt->ch[0]->mi1;
  else
    rt->mi1 = (1 << level) + rt->ch[1]->mi1;
  if (rt->ch[1])
    rt->mi2 = rt->ch[1]->mi2;
  else
    rt->mi2 = rt->ch[0]->mi2 + (1 << level);
  if (rt->ch[0]) rt->ans = min(rt->ans, rt->ch[0]->ans);
  if (rt->ch[1]) rt->ans = min(rt->ans, rt->ch[1]->ans);
  if (rt->ch[0] && rt->ch[1])
    rt->ans = min(rt->ans, rt->ch[1]->mi1 + rt->ch[0]->mi2 + 1);
}
void flip(int cur, int level, Node* rt) {
  if (rt == NULL) return;
  if (cur == level) {
    swap(rt->ch[0], rt->ch[1]);
    pushUp(rt, level);
  } else {
    flip(cur - 1, level, rt->ch[0]);
    flip(cur - 1, level, rt->ch[1]);
    pushUp(rt, cur);
  }
}
void dfs(int cur, int v, int k, Node* rt) {
  if (cur == k) {
    ans[v] = rt->ans;
    return;
  }
  dfs(cur + 1, v, k, rt);
  flip(k - 1, cur, rt);
  dfs(cur + 1, v | (1 << cur), k, rt);
  flip(k - 1, cur, rt);
}
Node* newNode() {
  Node* rt = &node[tot++];
  rt->ch[0] = rt->ch[1] = NULL;
  rt->ans = 1e9;
  rt->mi1 = 1e9;
  rt->mi2 = 1e9;
  return rt;
}
void insert(int cur, int v, Node* rt) {
  if (cur < 0) {
    rt->mi1 = rt->mi2 = 0;
    rt->ans = 1e9;
    return;
  }
  if (v & (1 << cur)) {
    if (rt->ch[1] == NULL) rt->ch[1] = newNode();
    insert(cur - 1, v, rt->ch[1]);
  } else {
    if (rt->ch[0] == NULL) rt->ch[0] = newNode();
    insert(cur - 1, v, rt->ch[0]);
  }
  pushUp(rt, cur);
}
int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  Node* rt = newNode();
  for (int i = 0; i < n; i++) {
    insert(k - 1, a[i], rt);
  }
  dfs(0, 0, k, rt);
  for (int i = 0; i < (1 << k); i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
