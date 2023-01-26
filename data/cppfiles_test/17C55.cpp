#include <bits/stdc++.h>
using namespace std;
int tc;
int n;
int A[50005][6];
int win(int a, int b) {
  int bal = 0;
  for (int i = 0; i < 5; i++) {
    if (A[a][i] < A[b][i])
      bal++;
    else
      bal--;
  }
  return bal > 0;
}
int main() {
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &n);
    vector<int> V;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 5; j++) {
        scanf("%d", &A[i][j]);
      }
      V.push_back(i);
    }
    while (V.size() >= 2) {
      int a = V.back();
      V.pop_back();
      int b = V.back();
      V.pop_back();
      if (win(a, b))
        V.push_back(a);
      else
        V.push_back(b);
    }
    int v = V.back();
    bool valid = true;
    for (int i = 1; i <= n; i++) {
      if (!valid) break;
      if (i == v) continue;
      if (win(i, v)) valid = false;
    }
    if (valid)
      printf("%d\n", v);
    else
      printf("-1\n");
  }
  return 0;
}
