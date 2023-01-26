#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int a[100];
    while (n) {
      a[++cnt] = n % 10;
      n /= 10;
    }
    int single = 0;
    int couple = 0;
    bool b = true;
    for (int i = cnt; i >= 1; i--) {
      if (i & 1) {
        single = single * 10 + a[i];
      } else {
        couple = couple * 10 + a[i];
      }
    }
    cout << (long long)(single + 1) * (couple + 1) - 2 << endl;
  }
  return 0;
}
