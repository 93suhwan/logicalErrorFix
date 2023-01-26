#include <bits/stdc++.h>
using namespace std;
int T, n;
char s[50];
int a[50], b[50];
int main() {
  scanf("%d", &T);
  while (T--) {
    int cnt = 0;
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) a[i] = s[i] - 'a', b[i] = a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
      if (a[i] != b[i]) cnt++;
    cout << cnt << endl;
  }
  return 0;
}
