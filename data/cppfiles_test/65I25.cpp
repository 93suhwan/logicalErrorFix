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
  r = n;
  for (i = n - 1; i >= 0; i--) {
    if (you[i] != you[i + 1]) {
      tkr[i] = r;
      r--;
    } else {
      tkr[i] = l;
      l++;
    }
  }
  if (r != n) {
    cout << a[r];
    if ((n - r) & 1) {
      cout << " L" << endl;
    } else {
      cout << " R" << endl;
    }
  }
  for (i = 0; i < n; i++) {
    if (tkr[i] != n) {
      cout << a[tkr[i]];
      if ((n - tkr[i]) & 1) {
        cout << " R" << endl;
      } else {
        cout << " L" << endl;
      }
    }
  }
  return 0;
}
