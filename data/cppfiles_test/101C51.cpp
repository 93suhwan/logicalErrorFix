#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int N = 2e5 + 10;
const int maxn = 205;
const double eps = 1e-8;
int icase = 0;
struct node {
  int a, b;
} tr[N];
bool cmp(node a, node b) {
  if (a.b == b.b) {
    return a.a < b.a;
  }
  return a.b < b.b;
}
bool vis[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> tr[i].a;
  string str;
  memset(vis, 0, sizeof(vis));
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'B')
      tr[i + 1].b = -1;
    else
      tr[i + 1].b = 1;
  }
  sort(tr + 1, tr + 1 + n, cmp);
  int flag = 1;
  int pos = n + 1;
  for (int i = 1; i <= n; i++) {
    if (tr[i].b == 1) {
      pos = i;
      break;
    }
    if (!vis[i] && tr[i].a >= i) {
      vis[i] = 1;
    } else {
      flag = 0;
    }
  }
  for (int i = pos; i <= n; i++) {
    if (!vis[i] && tr[i].a <= i) {
      vis[i] = 1;
    } else {
      flag = 0;
    }
  }
  if (flag) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
