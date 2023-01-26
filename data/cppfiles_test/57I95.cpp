#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
const int N = 3000, MOD = 998244353;
int t, n, a[N], f[N], iv[N], iiv[N];
void upd(int i, int d) {
  for (; i <= n; f[i] += d, i += i & -i)
    ;
}
int get(int i) {
  int ans = 0;
  for (; i > 0; ans += f[i], i -= i & -i)
    ;
  return ans;
}
int get(int l, int r) {
  if (l > r) return 0;
  return get(r) - get(l - 1);
}
vector<int> ans;
void doOp(int i) {
  ans.push_back(i);
  reverse(a + 1, a + 1 + i);
}
char oky() {
  char ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans &= i == a[i];
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    int ok = 1;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      ok &= a[i] % 2 == i % 2;
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    ans.clear();
    int lim = 5 * n / 2, c = 0;
    for (int i = n; i > 1; i -= 2) {
      if (a[i] == i) {
        if (a[i - 1] != i - 1) break;
      } else {
        int j = 1;
        while (a[j] != i) ++j;
        if (a[j - 1] == i - 1) {
          doOp(j), doOp(i);
        } else if (a[j + 1] == i - 1) {
          doOp(j + 2), doOp(3), doOp(i);
        } else {
          break;
        }
      }
    }
    if (!oky() || ans.size() > lim) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
  }
  return 0;
}
