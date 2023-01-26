#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3E5 + 5;
const int MOD = 1E9 + 7;
int n, m;
int sum[MAXN];
set<int> s[MAXN * 4];
int find(int l, int r) {
  auto it = s[sum[l - 1] + sum[r] + 2 * n].lower_bound(l);
  return *it;
}
void solve(int caseNum) {
  cin >> n >> m;
  for (int i = 0; i <= 4 * n; i++) s[i].clear();
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    if (c == '+')
      sum[i] = sum[i - 1] + (i & 1 ? 1 : -1);
    else
      sum[i] = sum[i - 1] - (i & 1 ? 1 : -1);
    s[sum[i] + sum[i - 1] + 2 * n].insert(i);
  }
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    if (sum[r] - sum[l - 1] == 0)
      cout << 0 << endl;
    else if ((r - l + 1) & 1) {
      cout << 1 << endl;
      cout << find(l, r) << endl;
    } else {
      cout << 2 << endl;
      cout << r << " ";
      r--;
      cout << find(l, r) << endl;
    }
  }
}
signed main() {
  int testCase = 1;
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> testCase;
  for (int i = 1; i <= testCase; i++) solve(i);
  return 0;
}
