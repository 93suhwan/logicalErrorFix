#include <bits/stdc++.h>
using namespace std;
void usain_bolt() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
const int N = 2e5 + 5;
int tree[N * 4];
deque<int> dq;
struct solve {
  int val, ind;
} a[N];
bool cmp(solve a, solve b) { return a.val < b.val; }
bool cmp2(solve a, solve b) { return a.ind < b.ind; }
void update(int left, int right, int node, int pos) {
  if (left > right) {
    return;
  }
  if (left == right) {
    ++tree[node];
    return;
  }
  int mid = (left + right) >> 1;
  if (mid >= pos) {
    update(left, mid, node * 2, pos);
  } else {
    update(mid + 1, right, node * 2 + 1, pos);
  }
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(int left, int right, int node, int x, int y) {
  if (left > right) {
    return 0;
  }
  if (left >= x && right <= y) {
    return tree[node];
  }
  int mid = (left + right) >> 1;
  int ans1 = 0, ans2 = 0;
  if (mid >= x) {
    ans1 = query(left, mid, node * 2, x, y);
  }
  if (mid + 1 <= y) {
    ans2 = query(mid + 1, right, node * 2 + 1, x, y);
  }
  return ans1 + ans2;
}
int main() {
  usain_bolt();
  int tt;
  cin >> tt;
  for (; tt; --tt) {
    int n;
    memset(tree, 0, sizeof(tree));
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i].val;
      a[i].ind = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      ++cnt;
      while (a[i].val == a[i + 1].val && i < n) {
        a[i].val = cnt;
        ++i;
      }
      a[i].val = cnt;
    }
    sort(a + 1, a + 1 + n, cmp2);
    update(1, n, 1, a[1].val);
    long long sol = 0;
    for (int i = 2; i <= n; ++i) {
      if (a[i].val == 1) {
        update(1, n, 1, 1);
      } else {
        sol += 1LL * min(query(1, n, 1, 1, a[i].val - 1),
                         query(1, n, 1, a[i].val + 1, 2e5 + 3));
        update(1, n, 1, a[i].val);
      }
    }
    cout << sol << "\n";
  }
  return 0;
}
