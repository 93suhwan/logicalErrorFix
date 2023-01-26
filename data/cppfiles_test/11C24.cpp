#include <bits/stdc++.h>
using namespace std;
const long long sz = 2e5;
long long a[sz + 5];
int merge(int left, int right) { return max(left, right); }
struct node1 {
  node1* left;
  node1* right;
  int val;
  node1() {
    val = 0;
    left = NULL;
    right = NULL;
  }
};
struct node2 {
  node1* root;
  node2* left;
  node2* right;
  node2() {
    root = new node1();
    left = NULL;
    right = NULL;
  }
  int get(node1*& v, int l, int r, int y1, int y2) {
    if (l == y1 && r == y2) {
      return v->val;
    }
    int m = (l + r) / 2;
    if (y2 <= m) {
      if (v->left == NULL) return 0;
      return get(v->left, l, m, y1, y2);
    } else if (y1 > m) {
      if (v->right == NULL) return 0;
      return get(v->right, m + 1, r, y1, y2);
    } else {
      return merge((v->left == NULL) ? 0 : get(v->left, l, m, y1, m),
                   (v->right == NULL) ? 0 : get(v->right, m + 1, r, m + 1, y2));
    }
  }
  void upd(node1*& v, int l, int r, int y, int val) {
    if (l == r && l == y) {
      v->val = max(v->val, val);
      return;
    }
    int m = (l + r) / 2;
    if (y <= m) {
      if (v->left == NULL) v->left = new node1();
      upd(v->left, l, m, y, val);
    } else {
      if (v->right == NULL) v->right = new node1();
      upd(v->right, m + 1, r, y, val);
    }
    v->val = merge((v->left == NULL) ? 0 : v->left->val,
                   (v->right == NULL) ? 0 : v->right->val);
  }
};
struct node3 {
  node2* root;
  node3() { root = new node2(); }
  int get(node2*& v, int l, int r, int x1, int x2, int y1, int y2) {
    if (l == x1 && r == x2) {
      return v->get(v->root, 0, sz, y1, y2);
    }
    int m = (l + r) / 2;
    if (x2 <= m) {
      if (v->left == NULL) v->left = new node2();
      return get(v->left, l, m, x1, x2, y1, y2);
    } else if (x1 > m) {
      if (v->right == NULL) v->right = new node2();
      return get(v->right, m + 1, r, x1, x2, y1, y2);
    } else {
      return merge(
          (v->left == NULL) ? 0 : get(v->left, l, m, x1, m, y1, y2),
          (v->right == NULL) ? 0 : get(v->right, m + 1, r, m + 1, x2, y1, y2));
    }
  }
  void upd(node2*& v, int l, int r, int x, int y, int val) {
    if (l == r && l == x) {
      v->upd(v->root, 0, sz, y, val);
      return;
    }
    int m = (l + r) / 2;
    if (x <= m) {
      if (v->left == NULL) v->left = new node2();
      upd(v->left, l, m, x, y, val);
    } else {
      if (v->right == NULL) v->right = new node2();
      upd(v->right, m + 1, r, x, y, val);
    }
    v->upd(v->root, 0, sz, y, val);
  }
};
node3* root;
long long n;
int main() {
  root = new node3();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  root->upd(root->root, 0, sz, 0, 0, 0);
  for (int i = 1; i <= n; i++) {
    if (a[i] - i > 0) continue;
    long long new_ans =
        1 + root->get(root->root, 0, sz, 0, a[i] - 1, 0, i - a[i]);
    root->upd(root->root, 0, sz, a[i], i - a[i], new_ans);
  }
  cout << root->get(root->root, 0, sz, 0, sz, 0, sz) << "\n";
}
