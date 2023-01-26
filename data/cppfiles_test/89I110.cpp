#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a);
      if (a % (i + 1) == 0) b++;
    }
    if (b % 2 == 0)
      cout << "Yes" << endl;
    else
      cout << "NO" << endl;
  }
}
