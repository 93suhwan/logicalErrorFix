#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    priority_queue<pair<int, int> > q;
    queue<pair<int, int> > ans;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      q.push({x, i});
    }
    while (1) {
      pair<int, int> a, b;
      a = q.top();
      q.pop();
      b = q.top();
      q.pop();
      int na = a.first, nb = b.first;
      if (na == 0 || nb == 0) break;
      ans.push({a.second, b.second});
      a.first--;
      b.first--;
      q.push(a);
      q.push(b);
    }
    printf("%d\n", ans.size());
    while (!ans.empty()) {
      pair<int, int> k = ans.front();
      ans.pop();
      printf("%d %d\n", k.first, k.second);
    }
  }
}
