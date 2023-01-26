#include <bits/stdc++.h>
const int N = 400005;
const int M = 21;
std::vector<int> val[M], cnt[M], mn[M], pos[M];
int cnt1[1 << (M - 1)], f[1 << (M - 1)][2];
bool valid[1 << (M - 1)];
inline int lb(int x) { return x & (-x); }
void init(int x) {
  static char s[N];
  static int pre[N << 1];
  scanf("%s", s + 1);
  int sz = strlen(s + 1), sum = 0;
  for (int i = 1; i <= sz; i++) {
    if (s[i] == '(')
      sum++;
    else
      sum--;
    val[x].push_back(sum);
    if (!mn[x].size())
      mn[x].push_back(sum);
    else
      mn[x].push_back(std::min(mn[x].back(), sum));
    if (mn[x].back() == val[x].back())
      pos[x].push_back(i - 1);
    else
      pos[x].push_back(pos[x].back());
  }
  for (int i = 0; i < val[x].size(); i++) {
    cnt[x].push_back(++pre[val[x][i] + N - 5]);
  }
  for (int i = 0; i < val[x].size(); i++) pre[val[x][i] + N - 5] = 0;
}
int calc(int x, int k) {
  int l = 0, r = mn[x].size() - 1, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (mn[x][mid] >= k)
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return mn[x][ans] == k ? cnt[x][pos[x][ans]] : 0;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) init(i);
  for (int i = 1; i <= n; i++) cnt1[1 << (i - 1)] = val[i].back();
  for (int i = 1; i < (1 << n); i++) cnt1[i] = cnt1[i ^ lb(i)] + cnt1[lb(i)];
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if (!((i >> j) & 1)) {
        f[i ^ (1 << j)][1] = std::max(f[i][1], f[i ^ (1 << j)][1]);
        if (valid[i] || i == 0) {
          if (cnt1[i] + mn[j + 1].back() >= 0)
            f[i ^ (1 << j)][0] =
                std::max(f[i ^ (1 << j)][0], f[i][0] + calc(j + 1, -cnt1[i])),
                        valid[i ^ (1 << j)] = 1;
          else
            f[i ^ (1 << j)][1] =
                std::max(f[i ^ (1 << j)][1], f[i][0] + calc(j + 1, -cnt1[i]));
        }
      }
    }
  }
  printf("%d\n", std::max(f[(1 << n) - 1][0], f[(1 << n) - 1][1]));
}
