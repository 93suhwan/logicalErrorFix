#include <bits/stdc++.h>
using namespace std;
int ans[502];
const int N = 1e5 + 10;
int a[N];
int cnt;
int main() {
  int n;
  cin >> n;
  ans[0] = 1;
  ++cnt;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (ans[a[i]] == 0) ++cnt;
    ans[a[i]] = 1;
    for (int j = 1; j <= a[i]; ++j) {
      if (ans[j] == 1) {
        if (ans[j ^ a[i]] == 0) cnt++;
        ans[j ^ a[i]] = 1;
      }
    }
  }
  printf("%d\n", cnt);
  for (int i = 0; i <= 500; ++i) {
    if (ans[i]) {
      printf("%d ", i);
    }
  }
}
