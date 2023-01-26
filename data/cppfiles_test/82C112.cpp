#include <bits/stdc++.h>
using namespace std;
int n, q;
string num;
int sum[1000001];
int get_sum(int l, int r) {
  if (l > r)
    return 0;
  else
    return (l % 2 == 1) ? sum[r] - sum[l - 1] : sum[l - 1] - sum[r];
}
int check_sign(int l, int r, int m) {
  return ((m - l + 1) % 2 == 1) ? get_sum(l, m - 1) + get_sum(m + 1, r)
                                : get_sum(l, m - 1) - get_sum(m + 1, r);
}
int find_odd(int l, int r) {
  if (l == r) return l;
  int ret = 0;
  int left = l;
  int right = r;
  while (left < right) {
    int mid = (int)(left + right) / 2;
    int lb = check_sign(l, r, left);
    int rb = check_sign(l, r, right);
    int mb = check_sign(l, r, mid);
    if (lb == 0) {
      ret = left;
      break;
    }
    if (mb == 0) {
      ret = mid;
      break;
    }
    if (rb == 0) {
      ret = right;
      break;
    }
    if ((lb > 0 && mb > 0) || (lb <= 0 && mb <= 0))
      left = mid;
    else
      right = mid;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    cin >> num;
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + ((i % 2) ? 1 : -1) * (num[i - 1] == '+' ? 1 : -1);
    for (int i = 1; i <= q; i++) {
      int l, r;
      cin >> l >> r;
      int res = get_sum(l, r);
      if (res == 0)
        cout << 0 << '\n';
      else if (res % 2)
        cout << 1 << '\n' << find_odd(l, r) << '\n';
      else
        cout << 2 << '\n' << l << ' ' << find_odd(l + 1, r) << '\n';
    }
  }
}
