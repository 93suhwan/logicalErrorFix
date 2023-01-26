#include <bits/stdc++.h>
using namespace std;
int n, A[2100005];
int Tmp[2100005], Vis[2100005];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int Ans = 0, Now = 1, Sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &A[i]);
      Vis[i] = 0;
    }
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; i++) {
      if (A[i] <= n) {
        if (!Vis[A[i]])
          Vis[A[i]] = 1;
        else
          Tmp[++Ans] = A[i];
        continue;
      }
      Tmp[++Ans] = A[i];
    }
    for (int i = 1; i <= n; i++) {
      if (Vis[i]) continue;
      if ((Tmp[Now] - 1) / 2 >= i) {
        Sum++, Now++;
        continue;
      }
      break;
    }
    if (Now == Ans + 1)
      printf("%d\n", Sum);
    else
      puts("-1");
  }
}
