#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    n -= 1;
    int t = n / 2;
    if (t * 2 == n) {
      if (t & 1)
        cout << t - 2 << " " << t + 2 << " " << 1 << endl;
      else
        cout << t - 1 << " " << t + 1 << " " << 1 << endl;
    } else {
      cout << t << " " << t + 1 << " " << 1 << endl;
    }
  }
  return 0;
}
