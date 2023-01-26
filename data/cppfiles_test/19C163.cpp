#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int an[N], n;
bool dfs(int p, int sum, bool b) {
  if (p == n + 1) {
    if (!sum && b) return 1;
    return 0;
  }
  return dfs(p + 1, sum + an[p], true) || dfs(p + 1, sum, b) ||
         dfs(p + 1, sum - an[p], true);
}
void work() {
  memset(an, 0, sizeof(an));
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> an[i];
  int ans = dfs(1, 0, 0);
  if (ans == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    work();
  }
  return 0;
}
