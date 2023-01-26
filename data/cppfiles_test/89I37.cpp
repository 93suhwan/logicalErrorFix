#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> v[200005];
int calc(int r, int parent, int mx) {
  for (int i : v[r]) {
    if (i == parent) continue;
    mx = max(mx, calc(i, r, mx));
  }
  bool valid = 1;
  int mx2 = 0;
  for (int i : v[r]) {
    if (i == parent) continue;
    if (v[i].size() != 1)
      valid = 0;
    else
      mx2++;
  }
  if (valid && r != 1)
    mx = mx2;
  else
    x += mx2;
  return mx;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      v[a].push_back(b);
      v[b].push_back(a);
    }
    int temp = calc(1, -1, 0);
    if (x && temp) x--;
    cout << temp + x << endl;
    x = 0;
    for (int i = 1; i <= n; i++) v[i].clear();
  }
  return 0;
}
