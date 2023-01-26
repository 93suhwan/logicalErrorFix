#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
vector<T> make_unique(vector<T> a) {
  sort((a).begin(), (a).end());
  a.erase(unique((a).begin(), (a).end()), a.end());
  return a;
}
const int INF = 1e9;
struct node {
  node *left, *right;
  int len, ans, mn, mx;
  node(int len)
      : len(len), ans(INF), mn(INF), mx(-INF), left(nullptr), right(nullptr) {}
  void pull() {
    if (len == 1) return;
    ans = min(get_ans(left), get_ans(right));
    ans = min(ans, get_mn(right) + len / 2 - get_mx(left));
    mn = min(get_mn(left), len / 2 + get_mn(right));
    mx = max(get_mx(right) + len / 2, get_mx(left));
  }
  void build() {
    if (left) left->build();
    if (right) right->build();
    pull();
  }
  void flip_depth(int depth) {
    if (depth == 0) {
      swap(left, right);
      pull();
    } else {
      if (left) left->flip_depth(depth - 1);
      if (right) right->flip_depth(depth - 1);
      pull();
    }
  }
  void print(string tab = "") {
    cerr << tab << "len: " << len << " ans: " << ans << " mn: " << mn
         << " mx: " << mx << endl;
    if (left) left->print(tab + "  ");
    if (right) right->print(tab + "  ");
  }

 private:
  int get_ans(node *u) { return u ? u->ans : INF; }
  int get_mn(node *u) { return u ? u->mn : INF; }
  int get_mx(node *u) { return u ? u->mx : -INF; }
};
int rev(int mask, int k) {
  int ans = 0;
  for (int i = 0; i < (int)(k); i++) {
    ans = 2 * ans + (mask >> i) % 2;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < (int)(n); i++) cin >> a[i];
  auto root = new node(1 << k);
  for (auto x : a) {
    auto cur = root;
    for (int bit = k - 1; bit >= 0; bit--) {
      auto &go = (((x >> bit) & 1) ? cur->right : cur->left);
      if (go == nullptr) go = new node(cur->len / 2);
      cur = go;
    }
    cur->len = 1;
    cur->mn = cur->mx = 0;
  }
  root->build();
  vector<int> ans(1 << k);
  int last = 0;
  for (int mask = 0; mask < (int)(1 << k); mask++) {
    auto change = mask ^ last;
    for (int i = 0; i < (int)(k); i++)
      if ((change >> i) & 1) root->flip_depth(i);
    ans[rev(mask, k)] = root->ans;
    last = mask;
  }
  for (auto x : ans) cout << x << ' ';
  return 0;
}
