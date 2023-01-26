#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const long long INF = 1e18;
int a, b, first[maxn], second[maxn];
void solve() {
  cin >> a >> b;
  if (a == 0 || b == 0) {
    a += b;
    if (a % 2 == 0)
      cout << 1 << endl << a / 2 << endl;
    else
      cout << 2 << endl << a / 2 << " " << a / 2 + 1 << endl;
    return;
  }
  set<int> ans;
  int x = (a + b) / 2;
  int y = (a + b) / 2 + ((a + b) % 2);
  if (a > b) swap(a, b);
  for (int i = 0; i <= a; i++) {
    int n = a - i;
    int m = y - i;
    int j = b - m;
    if (m >= 0 && n <= x && j >= 0) ans.insert(i + j);
  }
  for (int i = 0; i <= a; i++) {
    int n = a - i;
    int m = x - i;
    int j = b - m;
    if (m >= 0 && n <= y && j >= 0) ans.insert(i + j);
  }
  cout << ans.size() << endl;
  for (auto i : ans) cout << i << " ";
  cout << endl;
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
