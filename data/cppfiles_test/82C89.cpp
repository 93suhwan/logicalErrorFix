#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
char s[N];
int sum[N];
int to_sum(int l, int r) {
  if (l > r) return 0;
  return (l % 2 == 1 ? sum[r] - sum[l - 1] : sum[l - 1] - sum[r]);
}
int get_b(int l, int r, int m) {
  int ans = to_sum(l, m - 1);
  if ((m - l + 1) % 2)
    ans += to_sum(m + 1, r);
  else
    ans -= to_sum(m + 1, r);
  return ans;
}
int get_sign(int x) { return x > 0 ? 1 : -1; }
int find_ans(int l, int r) {
  if (l == r) return l;
  int la = l, ra = r;
  while (la < ra) {
    int mid = la + ra >> 1;
    int lb = get_b(l, r, la);
    int mb = get_b(l, r, mid);
    int rb = get_b(l, r, ra);
    if (lb == 0) return la;
    if (mb == 0) return mid;
    if (rb == 0) return ra;
    if (get_sign(lb) == get_sign(mb))
      la = mid;
    else
      ra = mid;
  }
  return -1;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d %d", &n, &q);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
      if (i % 2)
        sum[i] = sum[i - 1] + (s[i] == '+' ? 1 : -1);
      else
        sum[i] = sum[i - 1] - (s[i] == '+' ? 1 : -1);
    }
    while (q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      if (!to_sum(l, r))
        printf("0\n");
      else {
        bool is_even = false;
        if ((r - l + 1) % 2 == 0) is_even = true, l++;
        int pos = find_ans(l, r);
        if (is_even)
          printf("2\n%d %d\n", l - 1, pos);
        else
          printf("1\n%d\n", pos);
      }
    }
  }
  return 0;
}
