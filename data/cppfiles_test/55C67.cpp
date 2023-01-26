#include <bits/stdc++.h>
using namespace std;
pair<int, int> tree[2000000], lazy[2000000];
int pot(int x) {
  int tmp = 1;
  while (x) {
    tmp *= 2;
    x /= 2;
  }
  return tmp;
}
int treeSize;
void update(int a, int b, pair<int, int> v, int q = 0, int r = treeSize - 1,
            int pt = 1) {
  if (a == q && b == r) {
    if (v > tree[pt]) {
      tree[pt] = v;
    }
    lazy[pt] = max(lazy[pt], v);
    return;
  }
  int mid = (q + r) / 2;
  if (lazy[pt] != make_pair(0, 0)) {
    lazy[pt * 2] = max(lazy[pt * 2], lazy[pt]);
    lazy[pt * 2 + 1] = max(lazy[pt * 2 + 1], lazy[pt]);
    tree[pt * 2] = max(tree[pt * 2], lazy[pt]);
    tree[pt * 2 + 1] = max(tree[pt * 2 + 1], lazy[pt]);
    lazy[pt] = {0, 0};
  }
  if (a <= mid) {
    update(a, min(b, mid), v, q, mid, pt * 2);
  }
  if (b > mid) {
    update(max(a, mid + 1), b, v, mid + 1, r, pt * 2 + 1);
  }
  tree[pt] = max(tree[pt * 2], tree[pt * 2 + 1]);
}
pair<int, int> qur(int a, int b, int q = 0, int r = treeSize - 1, int pt = 1) {
  if (a == q && b == r) {
    return tree[pt];
  }
  int mid = (q + r) / 2;
  if (lazy[pt] != make_pair(0, 0)) {
    lazy[pt * 2] = max(lazy[pt * 2], lazy[pt]);
    lazy[pt * 2 + 1] = max(lazy[pt * 2 + 1], lazy[pt]);
    tree[pt * 2] = max(tree[pt * 2], lazy[pt]);
    tree[pt * 2 + 1] = max(tree[pt * 2 + 1], lazy[pt]);
    lazy[pt] = {0, 0};
  }
  pair<int, int> out = {0, 0};
  if (a <= mid) {
    out = max(out, qur(a, min(b, mid), q, mid, pt * 2));
  }
  if (b > mid) {
    out = max(out, qur(max(a, mid + 1), b, mid + 1, r, pt * 2 + 1));
  }
  tree[pt] = max(tree[pt * 2], tree[pt * 2 + 1]);
  return out;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> conv;
  vector<pair<int, pair<int, int>>> inp;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    conv.push_back(b);
    conv.push_back(c);
    inp.push_back({a - 1, {b, c}});
  }
  sort(conv.begin(), conv.end());
  vector<vector<pair<int, int>>> tab(n);
  treeSize = pot(4 + conv.size());
  vector<int> dp(n), poprz(n, -1);
  for (int i = 0; i < inp.size(); i++) {
    int a = lower_bound(conv.begin(), conv.end(), inp[i].second.first) -
            conv.begin();
    int b = lower_bound(conv.begin(), conv.end(), inp[i].second.second) -
            conv.begin();
    tab[inp[i].first].push_back({a, b});
  }
  int wyn = -1;
  int idx = -1;
  for (int i = 0; i < n; i++) {
    pair<int, int> bst = {0, 0};
    for (int j = 0; j < tab[i].size(); j++) {
      bst = max(bst, qur(tab[i][j].first, tab[i][j].second));
    }
    for (int j = 0; j < tab[i].size(); j++) {
      update(tab[i][j].first, tab[i][j].second, {bst.first + 1, i});
    }
    if (bst.first > 0) poprz[i] = bst.second;
    if (bst.first + 1 > wyn) {
      wyn = bst.first + 1;
      idx = i;
    }
  }
  vector<bool> used(n);
  int pt = idx;
  while (pt >= 0) {
    if (used[pt]) break;
    used[pt] = true;
    pt = poprz[pt];
  }
  cout << n - wyn << '\n';
  if (n - wyn > 0) {
    for (int i = 0; i < n; i++) {
      if (!used[i]) cout << i + 1 << " ";
    }
    cout << '\n';
  }
  return 0;
}
