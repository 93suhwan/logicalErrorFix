#include <bits/stdc++.h>
using namespace std;
int n;
int fa[500005];
int op[500005];
int x[500005];
int y[500005];
int ans[500005];
int top = 0;
int main() {
  int n;
  cin >> n;
  int i = 1;
  while (i <= 500000) {
    fa[i] = i;
    i++;
  }
  i = 1;
  while (i <= n) {
    scanf("%d", &op[i]);
    if (op[i] == 1) {
      scanf("%d", &x[i]);
    } else {
      scanf("%d%d", &x[i], &y[i]);
    }
    i++;
  }
  i = n;
  while (i >= 1) {
    if (op[i] == 1) {
      top++;
      ans[top] = fa[x[i]];
    } else {
      fa[x[i]] = fa[y[i]];
    }
    i--;
  }
  i = top;
  while (i >= 1) {
    cout << ans[i] << " ";
    i--;
  }
  cout << endl;
  return 0;
}
