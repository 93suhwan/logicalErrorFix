#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t, n, s;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &s);
    if (n > s)
      puts("0");
    else if (n == 1)
      printf("%d\n", s);
    else
      printf("%d\n", s / ((n / 2) + 1));
  }
  return 0;
}
