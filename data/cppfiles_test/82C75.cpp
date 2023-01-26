#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 3e5 + 10;
const int md = 1e9 + 7;
char s[maxn];
int pre[maxn];
void check(int l1, int r1) {
  int f1 = -1;
  int sum = 0;
  for (int i = 1; i <= 14; i++) {
    if (i == l1 || i == r1) continue;
    f1 = f1 * (-1);
    if (s[i] == '+') {
      sum += f1;
    } else {
      sum -= f1;
    }
  };
}
vector<int> v[maxn << 1];
void work() {
  int n, q;
  cin >> n >> q;
  cin >> (s + 1);
  int f1 = -1;
  for (int i = 1; i <= n; i++) {
    f1 = f1 * (-1);
    if (s[i] == '+') {
      pre[i] = pre[i - 1] + f1;
    } else {
      pre[i] = pre[i - 1] - f1;
    }
  }
  for (int i = 1; i <= n; i++) v[pre[i] + maxn].emplace_back(i);
  while (q--) {
    int l, r;
    cin >> l >> r;
    int len = (r - l + 1);
    if (pre[r] - pre[l - 1] == 0) {
      cout << "0\n";
      continue;
    } else if (len & 1) {
      len = pre[r] - pre[l - 1];
      if (len >= 0)
        len++;
      else
        len--;
      int now = pre[l - 1] + (len) / 2;
      auto ans = lower_bound(v[now + maxn].begin(), v[now + maxn].end(), l);
      cout << "1\n";
      cout << (*ans) << "\n";
      continue;
    } else {
      r--;
      len = pre[r] - pre[l - 1];
      if (len >= 0)
        len++;
      else
        len--;
      int now = pre[l - 1] + (len) / 2;
      auto ans = lower_bound(v[now + maxn].begin(), v[now + maxn].end(), l);
      cout << "2\n";
      cout << (*ans) << " " << r + 1 << "\n";
      continue;
    }
  }
  for (int i = 1; i <= n; i++) v[pre[i] + maxn].clear();
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    work();
  }
}
