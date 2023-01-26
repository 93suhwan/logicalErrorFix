#include <bits/stdc++.h>
using namespace std;
class Node {
 public:
  int val;
  Node *left;
  Node *right;
};
int **f;
int **d;
int **e;
int **w;
int dc[1000000];
Node *head;
void setVal(Node **head, int nl, int nr, int pos, int val) {
  if ((*head) == nullptr) {
    (*head) = new Node();
  }
  if (nl == nr) {
    (*head)->val = val;
    return;
  }
  int nc = (nl + nr) / 2;
  int cval = 0;
  if (pos <= nc) {
    setVal(&((*head)->left), nl, nc, pos, val);
    cval = max(cval, (*head)->left->val);
  } else {
    setVal(&((*head)->right), nc + 1, nr, pos, val);
    cval = max(cval, (*head)->right->val);
  }
  (*head)->val = cval;
}
int getTans(Node *head, int nl, int nr, int l, int r) {
  if (l > r) {
    return 0;
  }
  if (head == nullptr) {
    return 0;
  }
  if (nl == l && nr == r) {
    return head->val;
  }
  int nc = (nl + nr) / 2;
  int ans = max(getTans(head->left, nl, nc, l, min(nc, r)),
                getTans(head->right, nc + 1, nr, max(l, nc + 1), r));
  return ans;
}
void solve() {}
int getAns(int i, int j) {
  if (w[i][j]) {
    return e[i][j];
  }
  w[i][j] = 1;
  if (i == 0) {
    e[i][j] = 1 - f[i][j];
    d[i][j] = j;
    if (e[i][j]) {
      d[i][j] = 0;
    }
    return e[i][j];
  }
  if (j == 0) {
    e[i][j] = 1 - f[i][j];
    d[i][j] = 0;
    return e[i][j];
  }
  if (f[i][j]) {
    e[i][j] = 0;
    d[i][j] = j;
  } else {
    if (getAns(i - 1, j)) {
      e[i][j] = 1;
      d[i][j] = d[i - 1][j];
    } else if (getAns(i, j - 1)) {
      e[i][j] = 1;
      d[i][j] = d[i][j - 1];
    } else {
      e[i][j] = 0;
      d[i][j] = j;
      if (f[i][j - 1] == 0) {
        d[i][j] = min(d[i][j], d[i][j - 1]);
      }
      if (f[i - 1][j]) {
        d[i][j] = min(d[i][j], d[i - 1][j]);
      }
    }
  }
  if (e[i][j] == 0 && f[i][j] == 0) {
    dc[j] = max(d[i][j], dc[j]);
  }
  return e[i][j];
}
int main() {
  int n, m;
  scanf("%lu %lu", &n, &m);
  getchar();
  char ch;
  f = (int **)malloc(sizeof(int *) * n);
  d = (int **)malloc(sizeof(int *) * n);
  e = (int **)malloc(sizeof(int *) * n);
  w = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; ++i) {
    f[i] = (int *)malloc(sizeof(int) * m);
    d[i] = (int *)malloc(sizeof(int) * m);
    w[i] = (int *)malloc(sizeof(int) * m);
    e[i] = (int *)malloc(sizeof(int) * m);
    for (int j = 0; j < m; ++j) {
      ch = getchar();
      f[i][j] = (ch == 'X') ? 1 : 0;
      w[i][j] = 0;
      e[i][j] = 0;
    }
    getchar();
  }
  int q;
  scanf("%lu", &q);
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      getAns(i, j);
    }
  }
  for (int j = 0; j < m; ++j) {
    setVal(&head, 0, m - 1, j, dc[j]);
  }
  int ix1, ix2;
  for (int i = 0; i < q; ++i) {
    scanf("%lu %lu", &ix1, &ix2);
    ix1--;
    ix2--;
    if (ix1 == ix2) {
      cout << "YES\n";
      continue;
    }
    int ans = getTans(head, 0, m - 1, ix1 + 1, ix2);
    if (ans > ix1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
