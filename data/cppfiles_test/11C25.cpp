#include <bits/stdc++.h>
using namespace std;
int tree[4 * 200005];
void update(int n, int st, int en, int index, int val) {
  if (st == en) {
    tree[n] = val;
    return;
  }
  int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
  if (index <= mid)
    update(lc, st, mid, index, val);
  else
    update(rc, mid + 1, en, index, val);
  tree[n] = max(tree[lc], tree[rc]);
}
int query(int n, int st, int en, int l, int r) {
  if (r < st || en < l) return 0;
  if (l <= st && en <= r) return tree[n];
  int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
  return max(query(lc, st, mid, l, r), query(rc, mid + 1, en, l, r));
}
vector<int> pos[200005 + 5];
int main() {
  int n, inp;
  scanf("%d", &n);
  int mx = 0;
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &inp);
    pos[inp].push_back(i);
  }
  for (int num = 1; num < 200005; num++) {
    reverse(pos[num].begin(), pos[num].end());
    for (auto position : pos[num]) {
      if (position < num) continue;
      int highestDeletePossible = position - num;
      int maxAns = query(1, 0, 200005, 0, highestDeletePossible) + 1;
      update(1, 0, 200005, highestDeletePossible, maxAns);
    }
  }
  cout << query(1, 0, 200005, 0, 200005) << '\n';
  return 0;
}
