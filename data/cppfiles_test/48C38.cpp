#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], L[N], R[N], bel[N];
long long s[N];
pair<long long, long long> ans, f[2000], g[2000];
void brute_force(int l, int r) {
  for (int j = l; j <= r; j++) {
    if (a[j] < 0) {
      int t = -a[j];
      ans.second += t;
      ans.first = max(0ll, ans.first - t);
    } else {
      int t = a[j];
      ans.first += t;
      ans.second = max(0ll, ans.second - t);
    }
  }
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  const int SIZE = min(n, (int)sqrt(n) + 1);
  const int BLOCK = n / SIZE + (n % SIZE != 0);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    a[i] -= x;
    s[i] = s[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) bel[i] = (i - 1) / SIZE + 1;
  for (int i = 1; i <= n; i++) {
    if (!L[bel[i]]) L[bel[i]] = i;
    R[bel[i]] = i;
  }
  for (int i = 1; i <= BLOCK; i++) {
    pair<long long, long long> tmp = make_pair(0, 0), st = make_pair(0, 0);
    for (int j = L[i]; j <= R[i]; j++) {
      if (a[j] < 0) {
        int t = -a[j];
        tmp.second += t;
        st.first += max(0ll, t - tmp.first);
        tmp.first = max(0ll, tmp.first - t);
      } else {
        int t = a[j];
        tmp.first += t;
        st.second += max(0ll, t - tmp.second);
        tmp.second = max(0ll, tmp.second - t);
      }
    }
    f[i] = st, g[i] = tmp;
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (s[r] - s[l - 1] != 0) {
      puts("-1");
      continue;
    }
    ans = make_pair(0, 0);
    if (bel[l] == bel[r])
      brute_force(l, r);
    else {
      brute_force(l, R[bel[l]]);
      for (int i = bel[l] + 1; i <= bel[r] - 1; i++) {
        ans.first = max(ans.first, f[i].first);
        ans.second = max(ans.second, f[i].second);
        ans.first -= f[i].first, ans.second -= f[i].second;
        ans.first += g[i].first, ans.second += g[i].second;
      }
      brute_force(L[bel[r]], r);
    }
    printf("%lld\n", ans.first);
  }
  return 0;
}
