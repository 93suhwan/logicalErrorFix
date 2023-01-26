#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = (int)2e5 + 5;
int _ = 1;
int n, m, k;
void work() {
  scanf("%d%d%d", &n, &m, &k);
  int num = n / m + (n % m != 0);
  int sum = num * (n % m);
  priority_queue<pii, vector<pii>, greater<pii> > q;
  for (int i = 1; i <= n; i++) q.push({0, i});
  while (k--) {
    vector<pii> app;
    for (int i = 1; i <= sum; i++) {
      if (i % num == 1) printf("%d ", num);
      pii node = q.top();
      q.pop();
      printf("%d ", node.second);
      app.push_back({node.first + 1, node.second});
      if (i % num == 0) printf("\n");
    }
    for (int i = 1; !q.empty(); i++) {
      if (i % (n / m) == 1) printf("%d ", n / m);
      if (i % (n / m) == 0) printf("\n");
      pii node = q.top();
      q.pop();
      printf("%d ", node.second);
      app.push_back({node.first, node.second});
    }
    for (auto i : app) q.push(i);
  }
  printf("\n");
}
int main() {
  scanf("%d", &_);
  while (_--) {
    work();
  }
  return 0;
}
