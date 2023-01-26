#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int a[maxn];
int num[maxn] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int ans;
void dfs(string s, int v, int cnt) {
  int n = s.length();
  if (v == n) {
    ans += cnt;
    return;
  }
  if (v < n - 2 && (s[v] - '0' + a[v]) >= 1) {
    a[v + 2] += 1;
    dfs(s, v + 1, cnt * num[s[v] - '0' + a[v] * 10 - 1]);
    a[v + 2] -= 1;
  }
  dfs(s, v + 1, cnt * num[s[v] - '0' + a[v] * 10]);
}
int main() {
  int kase;
  cin >> kase;
  while (kase--) {
    ans = 0;
    string s;
    cin >> s;
    dfs(s, 0, 1);
    cout << ans - 2 << endl;
  }
}
