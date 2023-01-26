#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int arr[MAX];
int n;
int query(int x, int y, int z) {
  cout << "? " << x << " " << y << " " << z << endl;
  int a;
  cin >> a;
  return a;
}
array<int, 3> col[2];
int ans[MAX];
vector<int> v;
int main() {
  int t;
  cin >> t;
  while (t--) {
    v.clear();
    col[0] = col[1] = {-1, -1, -1};
    cin >> n;
    for (int i = 1; i <= n; i += 3) {
      arr[i] = query(i, i + 1, i + 2);
      col[arr[i]] = {i, i + 1, i + 2};
    }
    int x = -1, y = -1;
    for (int i = 0; i < 3; ++i) {
      if (query(col[0][0], col[0][1], col[1][i])) {
        y = col[1][i];
        break;
      }
    }
    if (y == -1) {
      x = col[0][0];
      if (query(col[1][0], col[1][1], x))
        y = col[1][0];
      else if (query(col[1][0], col[1][2], x))
        y = col[1][0];
      else
        y = col[1][1];
    } else
      x = col[0][2];
    ans[x] = 0, ans[y] = 1;
    for (int i = 1; i <= n; i += 3) {
      if (i == col[arr[i]][0]) {
        for (int j = i; j <= i + 2; ++j) {
          if (j == x || j == y) continue;
          ans[j] = query(x, y, j);
        }
        continue;
      }
      int c = x;
      if (!arr[i]) c = y;
      int a = query(i, i + 1, c);
      int b = query(i, i + 2, c);
      int idx = -1;
      if (a != arr[i] && b != arr[i])
        idx = i;
      else if (a != arr[i])
        idx = i + 1;
      else if (b != arr[i])
        idx = i + 2;
      for (int j = i; j <= i + 2; ++j) {
        if (idx == j)
          ans[j] = !arr[i];
        else
          ans[j] = arr[i];
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (!ans[i]) v.push_back(i);
    }
    cout << "! " << v.size() << " ";
    for (auto &i : v) cout << i << " ";
    cout << endl;
  }
  return 0;
}
