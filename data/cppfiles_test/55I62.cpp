#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int MAX = 1e9;
struct Node {
  int mx, lz, idx, lzIdx;
  Node *left, *right;
  Node() : mx(0), lz(0), right(nullptr), left(nullptr) {}
  Node(int mx) : mx(mx), lz(0), lzIdx(0), right(nullptr), left(nullptr) {}
};
typedef Node* pNode;
struct Seg {
  int l, r, idx;
};
int n, m;
vector<Seg> row[N];
Node* stTree;
int ans[N], nxt[N];
inline int Mid(int s, int e) { return s + (e - s) / 2; }
void merge(pNode& r, const pNode a, const pNode b) {
  if (a->mx >= b->mx) {
    r->mx = a->mx;
    r->idx = a->idx;
  } else {
    r->mx = b->mx;
    r->idx = b->idx;
  }
}
void addLazy(pNode& cur, int lz, int lzIdx) {
  if (cur == nullptr) {
    cur = new Node();
  }
  if (lz > cur->lz) {
    cur->lz = lz;
    cur->lzIdx = lzIdx;
  }
}
void push_down(pNode& cur, int s, int e) {
  if (cur != nullptr) {
    if (cur->lz > cur->mx) {
      cur->mx = cur->lz;
      cur->idx = cur->lzIdx;
    }
    if (s != e) {
      addLazy(cur->left, cur->lz, cur->lzIdx);
      addLazy(cur->right, cur->lz, cur->lzIdx);
    }
    cur->lz = 0;
  }
}
void increase(pNode& cur, int s, int e, int i, int j, int x, int idx) {
  if (cur == nullptr) {
    cur = new Node();
  }
  push_down(cur, s, e);
  if (s > j || e < i) return;
  if (s >= i && e <= j) {
    if (cur->lz < x) {
      cur->lz = x;
      cur->lzIdx = idx;
    }
    push_down(cur, s, e);
    return;
  }
  int mid = Mid(s, e);
  increase(cur->left, s, mid, i, j, x, idx);
  increase(cur->right, mid + 1, e, i, j, x, idx);
  merge(cur, cur->left, cur->right);
}
pNode query(pNode cur, int s, int e, int i, int j) {
  if (cur == nullptr) return new Node(0);
  push_down(cur, s, e);
  if (s > j || e < i) return new Node(0);
  if (s >= i && e <= j) return cur;
  int mid = Mid(s, e);
  pNode r = new Node(0);
  merge(r, query(cur->left, s, mid, i, j), query(cur->right, mid + 1, e, i, j));
  return r;
}
void print(pNode& cur, int s, int e) {
  if (cur == nullptr) {
    for (int i = s; i <= e; i++) {
      cout << "0 ";
    }
    return;
  }
  if (s == e) {
    cout << cur->mx << " ";
    return;
  }
  print(cur->left, s, Mid(s, e));
  print(cur->right, Mid(s, e) + 1, e);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int idx, l, r;
    cin >> idx >> l >> r;
    row[--idx].push_back({--l, --r, i});
  }
  stTree = new Node();
  for (int i = n - 1; i >= 0; i--) {
    ans[i] = 0;
    for (int j = 0; j < ((int)(row[i]).size()); j++) {
      auto q = query(stTree, 0, MAX, row[i][j].l, row[i][j].r);
      ans[i] = max(ans[i], 1 + q->mx);
      if (q->mx > 0) {
        nxt[i] = q->idx;
      } else {
        nxt[i] = n;
      }
    }
    for (int j = 0; j < ((int)(row[i]).size()); j++) {
      increase(stTree, 0, MAX, row[i][j].l, row[i][j].r, ans[i], i);
    }
  }
  int best = INT_MAX;
  for (int i = 0; i < n; i++) {
    best = min(best, n - ans[i]);
  }
  cout << best << '\n';
  set<int> r;
  for (int i = 0; i < n; i++) {
    if (best == n - ans[i]) {
      for (int j = i; j < n; j = nxt[j]) {
        r.insert(j);
      }
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (r.count(i) == 0) {
      cout << i + 1 << " ";
    }
  }
  cout << '\n';
  return 0;
}
