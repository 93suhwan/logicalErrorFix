#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
bool vis[maxn];
int a[maxn], b[maxn], pre[maxn], n;
queue<int> q;
stack<int> s;
void print() {
  s.push(0);
  int pos = pre[0];
  while (pos != n) {
    s.push(pos);
    pos = pre[pos];
  }
  cout << s.size() << endl;
  while (!s.empty()) cout << s.top() << " ", s.pop();
  exit(0);
}
int minj;
void bfs(int now) {
  if (now == 0) print();
  if (vis[now]) return;
  vis[now] = true;
  int nowpos = now + b[now];
  for (int i = minj; i >= nowpos - a[nowpos]; i--) {
    if (!pre[i]) pre[i] = now, q.push(i);
    minj--;
  }
}
int main() {
  scanf("%d", &n);
  minj = n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  pre[n] = -1;
  bfs(n);
  while (!q.empty()) bfs(q.front()), q.pop();
  cout << "-1" << endl;
  return 0;
}
