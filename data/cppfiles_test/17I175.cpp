#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
const int M = 1e6 + 7;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
int n, tot, lsh[N], num[N];
long long tree[N << 2];
deque<int> q;
void pushup(int node) { tree[node] = tree[node << 1] + tree[node << 1 | 1]; }
void Updata(int node, int l, int r, int val, int pos) {
  if (l == r) {
    tree[node] += val;
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid)
    Updata(node << 1, l, mid, val, pos);
  else
    Updata(node << 1 | 1, mid + 1, r, val, pos);
  pushup(node);
}
long long quary(int node, int l, int r, int dl, int dr) {
  if (!dl || dl > dr) return 0;
  if (dl <= l && r <= dr) return tree[node];
  int ans = 0, mid = l + r >> 1;
  if (dl <= mid) ans += quary(node << 1, l, mid, dl, dr);
  if (dr > mid) ans += quary(node << 1 | 1, mid + 1, r, dl, dr);
  return ans;
}
int getid(int val) { return lower_bound(lsh + 1, lsh + n + 1, val) - lsh; }
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    tot = 0;
    for (int i = 1; i <= n << 2; ++i) tree[i] = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> num[i];
      lsh[++tot] = num[i];
    }
    sort(lsh + 1, lsh + tot + 1);
    tot = unique(lsh + 1, lsh + 1 + tot) - lsh - 1;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans += min(quary(1, 1, tot, getid(num[i]) + 1, tot),
                 quary(1, 1, tot, 1, getid(num[i]) - 1));
      Updata(1, 1, tot, 1, getid(num[i]));
    }
    cout << ans << '\n';
  }
  return 0;
}
