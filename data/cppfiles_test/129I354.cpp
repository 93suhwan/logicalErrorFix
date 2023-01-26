#include <bits/stdc++.h>
using namespace std;
int t, n;
int A[2000005];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);
    int Now = 0, Ans = 0, f = 1;
    for (int i = 1; i <= n; i++) {
      Now++;
      if (A[i] == Now) continue;
      if (Now <= A[i] / 2)
        Ans++;
      else
        f = 0;
    }
    if (!f)
      puts("-1");
    else
      printf("%d\n", Ans);
  }
}
