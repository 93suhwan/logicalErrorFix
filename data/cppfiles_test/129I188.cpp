#include <bits/stdc++.h>
using namespace std;
int t, n;
int A[100005];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);
    int Now = 1, Ans = 0, f = 1;
    for (int i = 1; i <= n; i++) {
      if (A[i] == Now) {
        Now++;
        continue;
      }
      if (Now <= A[i] / 2)
        Ans++;
      else
        printf("%d %d\n", Now, A[i]), f = 0;
      Now++;
    }
    if (!f)
      puts("-1");
    else
      printf("%d\n", Ans);
  }
}
