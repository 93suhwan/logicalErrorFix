#include <bits/stdc++.h>
using namespace std;
const int_fast64_t M = 998244353;
int_fast64_t fac[103];
int_fast64_t inv[103];
int_fast64_t ANS[103];
int_fast64_t bb = LLONG_MAX / 200 + 77;
const int32_t maxm = 20007;
vector<int_fast64_t> pr;
int_fast64_t SOE[maxm];
struct node {
  int_fast64_t data;
  node* left_child;
  node* right_child;
  pair<int_fast64_t, int_fast64_t> lr;
};
int_fast64_t fun(int_fast64_t x, int_fast64_t y) {
  if (x == bb && y == bb) return -1;
  return max(x, y);
}
int_fast64_t seg(int_fast64_t l, int_fast64_t r, int_fast64_t x,
                 int_fast64_t y) {
  if (r < x || l > y) return -1;
  if (l <= x && y <= r) return 1;
  return 0;
}
node* build_tree(int_fast64_t arr[], int_fast64_t l, int_fast64_t r) {
  if (l > r) {
    return NULL;
  }
  node* temp = new node;
  if (l == r) {
    temp->data = arr[l];
    temp->left_child = NULL;
    temp->right_child = NULL;
    temp->lr = {l, l};
    return temp;
  }
  temp->left_child = build_tree(arr, l, (l + r) / 2);
  temp->right_child = build_tree(arr, (l + r) / 2 + 1, r);
  if (temp->left_child == NULL)
    temp->data = temp->right_child->data;
  else if (temp->right_child == NULL)
    temp->data = temp->left_child->data;
  else
    temp->data = fun(temp->left_child->data, temp->right_child->data);
  temp->lr = {l, r};
  return temp;
}
void edit_tree(node* root, int_fast64_t node, int_fast64_t x) {
  int_fast64_t l = root->lr.first;
  int_fast64_t r = root->lr.second;
  if (l == r) {
    root->data = x;
    return;
  }
  if (seg(l, (l + r) / 2, node, node) == 1)
    edit_tree(root->left_child, node, x);
  else
    edit_tree(root->right_child, node, x);
  if (root->left_child == NULL)
    root->data = root->right_child->data;
  else if (root->right_child == NULL)
    root->data = root->left_child->data;
  else
    root->data = fun(root->left_child->data, root->right_child->data);
  return;
}
int_fast64_t get_ans(node* root, int_fast64_t l, int_fast64_t r) {
  int_fast64_t x = root->lr.first;
  int_fast64_t y = root->lr.second;
  if (seg(l, r, x, y) == 1) {
    return root->data;
  }
  if (seg(l, r, x, y) == -1) {
    return fun(bb, bb);
  }
  int_fast64_t ans = 0;
  if (x == y) return root->data;
  if (root->left_child == NULL) return root->right_child->data;
  if (root->right_child == NULL) return root->left_child->data;
  int_fast64_t a = get_ans(root->left_child, l, r);
  int_fast64_t b = get_ans(root->right_child, l, r);
  ans = fun(a, b);
  return ans;
}
void preorder(node* root) {
  if (root == NULL) return;
  cout << root->data << " " << root->lr.first << " " << root->lr.second << "\n";
  preorder(root->left_child);
  preorder(root->right_child);
  return;
}
void swap(int_fast64_t* a, int_fast64_t* b) {
  int_fast64_t temp = *a;
  *a = *b;
  *b = temp;
}
int_fast64_t poww(int_fast64_t x, int_fast64_t y, int_fast64_t m) {
  int_fast64_t ans = 1;
  while (y) {
    if (y % 2) {
      ans = (ans * x) % m;
    }
    x = x * x % m;
    y = y / 2;
  }
  return ans;
}
int_fast64_t fact(int_fast64_t a, int_fast64_t m) {
  int_fast64_t ans = 1;
  while (a > 1) {
    ans *= a;
    ans %= m;
    a--;
  }
  return ans;
}
int_fast64_t nCr(int_fast64_t n, int_fast64_t r, int_fast64_t m) {
  if (n < r) return 0;
  int_fast64_t a = fact(n, M);
  int_fast64_t ans = a;
  int_fast64_t b = fact(n - r, M);
  int_fast64_t c = fact(r, M);
  b = poww(b, m - 2, m);
  c = poww(c, m - 2, m);
  ans = (ans * b) % m;
  ans = (ans * c) % m;
  return ans;
}
int_fast64_t product(int_fast64_t x, int_fast64_t y, int_fast64_t m) {
  int_fast64_t ans = 0;
  while (y) {
    if (y % 2) {
      ans = (ans + x) % m;
    }
    x = (x + x) % m;
    y = y / 2;
  }
  return ans;
}
int_fast64_t nCk(int_fast64_t n, int_fast64_t k, int_fast64_t m) {
  int_fast64_t ANS = fac[n];
  ANS *= ((inv[n - k]));
  ANS %= m;
  ANS *= ((inv[k]));
  return ANS % m;
}
vector<vector<int_fast64_t>> adj;
vector<bool> vis;
vector<int_fast64_t> color;
int_fast64_t colour = 0;
void un_visit(int_fast64_t n) {
  vis = vector<bool>(n);
  for (int_fast64_t i = 0; i < n; i++) {
    vis[i] = 0;
  }
}
void un_color(int_fast64_t n) {
  color = vector<int_fast64_t>(n);
  for (int_fast64_t i = 0; i < n; i++) {
    color[i] = -1;
  }
  colour = 1;
}
void do_color(vector<vector<int_fast64_t>> aj, int_fast64_t i, int_fast64_t n) {
  int_fast64_t t = 0;
  if (i == 0) t = 1;
  if (vis[i]) {
    return;
  }
  vis[i] = 1;
  color[i] = colour;
  for (int_fast64_t j = 0; j < aj[i].size(); j++) {
    if (!vis[aj[i][j]]) {
      do_color(aj, aj[i][j], n);
    }
  }
  if (t) {
    t = 0;
    for (int_fast64_t j = 0; j < n; j++) {
      if (!vis[j]) {
        colour++;
        do_color(aj, j, n);
      }
    }
  }
  return;
}
void dfs(vector<vector<int_fast64_t>>& aj, int_fast64_t i) {
  if (vis[i]) {
    return;
  }
  vis[i] = 1;
  for (int_fast64_t j = 0; j < aj[i].size(); j++) {
    if (!vis[aj[i][j]]) {
      dfs(aj, aj[i][j]);
    }
  }
  return;
}
void solve() {
  int_fast64_t n;
  cin >> n;
  bool arr[n][5];
  for (int_fast64_t i = 0; i < n; i++)
    for (int_fast64_t j = 0; j < 5; j++) cin >> arr[i][j];
  if (n % 2) {
    cout << "NO" << endl;
    return;
  }
  bool res = 0;
  for (int_fast64_t i = 0; i < 5; i++)
    for (int_fast64_t j = i + 1; j < 5; j++) {
      int_fast64_t p = n / 2;
      int_fast64_t x = 0, y = 0, z = 0;
      for (int_fast64_t k = 0; k < n; k++) {
        if (arr[k][i]) x++;
        if (arr[k][j]) y++;
        if (arr[k][i] & arr[k][j]) z++;
      }
      int_fast64_t a = x - z;
      int_fast64_t b = y - z;
      if (y >= p && x >= p) {
        if (((x + y - z) / 2) >= p) res = 1;
      }
    }
  if (res)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return;
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int_fast64_t i = 0; i < 1000; i++)
    if (SOE[i] == i) pr.push_back(SOE[i]);
  int_fast64_t t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
