#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = ' ';
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch)) x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
int t, n, a[2100];
vector<int> ans;
void swp(int x) {
  ans.push_back(x);
  for (int i = 1; i <= x / 2; i++) swap(a[i], a[x - i + 1]);
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    ans.clear();
    int ok = 1;
    for (int i = 1; i <= n; i++) {
      a[i] = read();
      if (i % 2 != a[i] % 2) ok = 0;
    }
    if (!ok) {
      cout << -1 << endl;
      continue;
    }
    for (int i = 1; i <= n / 2; i++) {
      int now = n - (i - 1) * 2, id1, id2;
      for (int j = 1; j <= n; j++) {
        if (a[j] == now) id1 = j;
      }
      swp(id1);
      for (int j = 1; j <= n; j++) {
        if (a[j] == now - 1) id2 = j;
      }
      swp(id2 - 1);
      swp(n - (i - 1) * 2);
      for (int j = 1; j <= n; j++) {
        if (a[j] == now) id1 = j;
      }
      swp(id1);
      swp(n - (i - 1) * 2);
    }
    cout << ans.size() << endl;
    for (int v : ans) cout << v << " ";
    cout << endl;
  }
}
