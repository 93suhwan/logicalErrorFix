#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 50;
struct treenode {
  int l, r;
  int sum;
  int cnt1, cnt0;
} t[N];
int n, q;
char ch;
void pu(int p) {
  int ls = p << 1, rs = p << 1 | 1;
  t[p].sum = t[ls].sum + t[rs].sum;
  t[p].cnt0 = t[ls].cnt0 + t[rs].cnt0;
  t[p].cnt1 = t[ls].cnt1 + t[rs].cnt1;
}
void bd(int l, int r, int p) {
  t[p] = {l, r, 0, 0, 0};
  if (l == r) {
    cin >> ch;
    if (ch == '+') {
      t[p].sum = 1;
      t[p].cnt1 = 1;
    } else {
      t[p].sum--;
      t[p].cnt0 = 1;
    }
    return;
  }
  int mid = l + r >> 1;
  bd(l, mid, p << 1);
  bd(mid + 1, r, p << 1 | 1);
  pu(p);
}
int query(int l, int r, int p) {
  if (t[p].sum == 0) {
    return t[p].r - t[p].l + 1;
  }
  int ls = p << 1, rs = p << 1 | 1;
}
long long sum[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> n >> q;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> ch;
      if (ch == '+')
        sum[i] = 1;
      else
        sum[i] = -1;
      if (i % 2 == 0) sum[i] *= -1;
    }
    for (int i = 1; i <= n; i++) {
      sum[i] += sum[i - 1];
    }
    while (q--) {
      cin >> l >> r;
      if (sum[r] - sum[l - 1] == 0)
        cout << 0 << "\n";
      else {
        int tmp = (r - l + 1);
        if (tmp % 2) {
          cout << 1 << "\n";
        } else
          cout << 2 << "\n";
      }
    }
  }
  return 0;
}
