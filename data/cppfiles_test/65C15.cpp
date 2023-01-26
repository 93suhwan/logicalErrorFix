#include <bits/stdc++.h>
using namespace std;
int a[1000005], tkr[1000005];
bool you[1000005];
int main() {
  int n, i, l, r;
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  getchar();
  for (i = 0; i < n; i++) {
    you[i] = (getchar() == 'R');
  }
  l = 0;
  r = n - 1;
  for (i = n - 1; i; i--) {
    if (you[i] != you[i - 1]) {
      tkr[i] = r;
      r--;
    } else {
      tkr[i] = l;
      l++;
    }
  }
  tkr[0] = r;
  for (i = 0; i < n; i++) {
    if (tkr[i] != n) {
      cout << a[tkr[i]];
      if ((n - tkr[i] + 1) & 1 ^ you[n - 1]) {
        cout << " R" << endl;
      } else {
        cout << " L" << endl;
      }
    }
  }
  return 0;
}
