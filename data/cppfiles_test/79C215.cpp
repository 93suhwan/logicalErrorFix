#include <bits/stdc++.h>
using namespace std;
int a[10];
const int maxn = 1e5 + 5;
long long prime[maxn];
bool st[maxn];
int tot;
void get_prime(int n) {
  for (int i = 2; i <= n; i++) {
    if (!st[i]) prime[++tot] = i;
    for (int j = 1; prime[j] * i <= n; j++) {
      st[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
int k;
int ans = 0;
string str;
void dfs(int u, int num) {
  if (u == k) {
    if (st[num]) {
      ans = num;
    }
    return;
  }
  dfs(u + 1, num * 10 + (str[u] - '0'));
  dfs(u + 1, num);
}
void solve() {
  for (int i = 0; i < 10; i++) a[i] = 0;
  cin >> k >> str;
  ans = 0;
  for (int i = 0; i < k; i++) {
    int x = str[i] - '0';
    a[x]++;
  }
  for (int i = 1; i < 10; i++) {
    if (i == 2 || i == 3 || i == 5 || i == 7) {
      continue;
    } else {
      if (a[i] >= 1) {
        cout << "1" << endl;
        cout << i << endl;
        return;
      }
    }
  }
  for (int i = 1; i < 10; i++) {
    if (i == 2 || i == 3 || i == 5 || i == 7) {
      if (a[i] >= 2) {
        cout << "2" << endl;
        cout << i * 10 + i << endl;
        return;
      }
    }
  }
  dfs(0, 0);
  int cnt = 0;
  int x = ans;
  while (x) {
    x /= 10;
    cnt++;
  }
  cout << cnt << endl;
  cout << ans << endl;
}
int main() {
  get_prime(1e5);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
