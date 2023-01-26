#include <bits/stdc++.h>
const long long inf = 1e9 + 7;
const int mod = 1e9 + 7;
const int MAX_N = 5e5 + 7;
using namespace std;
int q[MAX_N], x[MAX_N], y[MAX_N];
int ans[MAX_N];
int nex[MAX_N];
int main() {
  int Q;
  cin >> Q;
  for (int i = 1; i <= Q; i++) {
    scanf("%d", &q[i]);
    if (q[i] == 1)
      scanf("%d", &x[i]);
    else
      scanf("%d%d", &x[i], &y[i]);
  }
  int N = 0;
  for (int i = 0; i < MAX_N; i++) {
    nex[i] = i;
  }
  for (int i = Q; i >= 1; i--) {
    if (q[i] == 1) {
      ans[++N] = nex[x[i]];
    } else {
      nex[x[i]] = nex[y[i]];
    }
  }
  for (int i = N; i >= 1; i--) {
    printf("%d ", ans[i]);
  }
}
