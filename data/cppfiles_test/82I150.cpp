#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 3e5 + 10;
const int md = 1e9 + 7;
char s[maxn];
int pre[maxn];
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
      int now = len / 2;
      auto ans = lower_bound(v[now + maxn].begin(), v[now + maxn].end(), l);
      cout << "1\n";
      cout << (*ans) + 1 << "\n";
    } else {
      len = pre[r - 1] - pre[l - 1];
      int now = len / 2 + pre[l];
      ;
      auto ans = lower_bound(v[now + maxn].begin(), v[now + maxn].end(), l);
      cout << "2\n";
      cout << (*ans) + 1 << " " << r << "\n";
      continue;
    }
  }
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
