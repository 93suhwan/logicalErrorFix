#include <bits/stdc++.h>
using namespace std;
int t, n, a[200005];
int main() {
  cin >> t;
  memset(a, 0, sizeof(a));
  int cnt = 0, temp, max = 0;
  while (t > 0) {
    t--;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (max < a[i]) max = a[i];
    }
    if (a[n] == max) {
      cout << "0" << endl;
      continue;
    }
    temp = a[n];
    for (int i = n; i >= 1; i--) {
      if (a[i] > temp) {
        cnt++;
        temp = a[i];
      }
    }
    cout << cnt << endl;
    cnt = 0;
    max = 0;
  }
  return 0;
}
