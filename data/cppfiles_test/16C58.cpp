#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
int a[N];
struct node {
  int l, r;
};
vector<node> ve;
void solve() {
  ve.clear();
  scanf("%d", &n);
  priority_queue<pair<int, int> > q;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] > 0) q.push({a[i], i});
  }
  while (q.size() > 1) {
    auto it1 = q.top();
    q.pop();
    auto it2 = q.top();
    q.pop();
    ve.push_back({it1.second, it2.second});
    it1.first--;
    it2.first--;
    if (it1.first > 0) q.push({it1.first, it1.second});
    if (it2.first > 0) q.push({it2.first, it2.second});
  }
  printf("%d\n", ve.size());
  for (int i = 0; i < ve.size(); i++) {
    printf("%d %d\n", ve[i].l, ve[i].r);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
