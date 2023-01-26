#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 11;
struct node {
  map<int, node*> child;
};
int ans;
vector<int> cand, best;
vector<int> a[N];
int can[N];
void init() {}
void gen(int pos, int sum, int prod, node* cur, int n, int m) {
  if (sum + can[pos] <= ans) {
    return;
  }
  if (pos >= n) {
    if (!cur) {
      ans = sum;
      best = cand;
    }
    return;
  }
  for (int i = ((int)(a[pos]).size()) - 1; i >= 0; --i) {
    if (((int)(a[pos]).size()) - i >= 2 * max(m, 10) / prod) {
      break;
    }
    node* new_cur = nullptr;
    if (cur) {
      auto it = cur->child.find(i);
      if (it != cur->child.end()) {
        new_cur = it->second;
      }
    }
    cand.push_back(i);
    gen(pos + 1, sum + a[pos][i], prod * (((int)(a[pos]).size()) - i), new_cur,
        n, m);
    cand.pop_back();
  }
}
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int sz;
    scanf("%d", &sz);
    a[i].resize(sz);
    for (int j = 0; j < sz; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  int m;
  scanf("%d", &m);
  node* root = new node();
  for (int i = 0; i < m; ++i) {
    node* cur = root;
    for (int j = 0; j < n; ++j) {
      int num;
      scanf("%d", &num);
      --num;
      if (cur->child.count(num)) {
        cur = cur->child[num];
      } else {
        cur->child[num] = new node();
        cur = cur->child[num];
      }
    }
  }
  can[n] = 0;
  for (int i = n - 1; i >= 0; --i) {
    can[i] = can[i + 1] + a[i].back();
  }
  ans = -1;
  gen(0, 0, 1, root, n, m);
  for (int y : best) {
    printf("%d ", y + 1);
  }
  puts("");
}
int main() {
  init();
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
