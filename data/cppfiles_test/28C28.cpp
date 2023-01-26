#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
const int maxn = 300000;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
int a[maxn + 5];
int cnt[maxn + 5];
bool mark[maxn + 5];
bool test(int n, int m, int off) {
  auto cal = [&](int x) {
    int y = x + off;
    return y <= n ? y : y - n;
  };
  int ans = 0;
  for (auto i = (1); i <= (n); i++) mark[i] = 0;
  for (auto i = (1); i <= (n); i++)
    if (mark[a[i]] == 0) {
      int now = a[i], c = 0;
      while (mark[now] == 0) {
        mark[now] = 1;
        now = a[cal(now)];
        c++;
      }
      ans += c - 1;
    }
  return ans <= m;
}
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (auto i = (1); i <= (n); i++) scanf("%d", &a[i]);
    int fixed = n - m * 2;
    for (auto i = (0); i <= (n - 1); i++) cnt[i] = 0;
    for (auto i = (1); i <= (n); i++) cnt[(i - a[i] + n) % n]++;
    vector<int> ans;
    for (auto i = (0); i <= (n - 1); i++)
      if (cnt[i] >= fixed && test(n, m, i)) ans.push_back(i);
    int N = ans.size();
    printf("%d", N);
    for (auto x : ans) printf(" %d", x);
    puts("");
  }
  return 0;
}
