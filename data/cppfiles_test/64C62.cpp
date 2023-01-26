#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using ll = long long int;
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
struct fhash {
  ll operator()(ll x) const { return 7; }
};
bool printSub(int a[], int sum) {
  if (sum == 0) return true;
  if (sum < 0) return false;
  for (int i = 0; i < 3; ++i) {
    int rem = sum - a[i];
    if (printSub(a, rem)) {
      cout << a[i] << " ";
      return true;
    }
  }
}
class tree {
  int data;

 public:
  tree *left, *right;
  tree(int n) {
    this->data = n;
    this->left = this->right = NULL;
  }
  tree *insert(int n, tree *root) {
    if (root == NULL) return new tree(n);
    if (n < root->data)
      root->left = insert(n, root->left);
    else
      root->right = insert(n, root->right);
    return root;
  }
  void inorder(tree *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
};
vector<int> par, par1;
int find_par(int n) {
  if (n == par[n]) return n;
  return par[n] = find_par(par[n]);
}
void mer(int a, int b) {
  int x = find_par(a);
  int y = find_par(b);
  par[x] = par[y];
}
int find_par1(int n) {
  if (n == par1[n]) return n;
  return par1[n] = find_par1(par1[n]);
}
void mer1(int a, int b) {
  int x = find_par1(a);
  int y = find_par1(b);
  par1[x] = par1[y];
}
void solve() {
  int n, e1, e2;
  cin >> n >> e1 >> e2;
  par.resize(n + 1), par1.resize(n + 1);
  for (int i = 1; i <= n; ++i) par[i] = par1[i] = i;
  while (e1--) {
    int a, b;
    cin >> a >> b;
    mer(a, b);
  }
  while (e2--) {
    int a, b;
    cin >> a >> b;
    mer1(a, b);
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; ++i) {
    if (find_par(i) != find_par(1) && find_par1(i) != find_par1(1)) {
      mer(1, i);
      mer1(1, i);
      ans.push_back({1, i});
    }
  }
  int l = 1, r = 1;
  while (l <= n && r <= n) {
    int f = l, s = r;
    while (f <= n && find_par(1) == find_par(f)) ++f;
    while (s <= n && find_par1(1) == find_par1(s)) ++s;
    l = f, r = s;
    if (l <= n && r <= n && find_par(l) != find_par(r) &&
        find_par1(l) != find_par1(r)) {
      ans.push_back({l, r});
      mer(l, r);
      mer1(l, r);
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i.first << " " << i.second << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
