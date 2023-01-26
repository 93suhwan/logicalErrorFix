#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b;
    c = a + b;
    if (c % 2 == 1)
      printf("-1\n");
    else {
      if (a == b)
        printf("0\n");
      else
        printf("2\n");
    }
  }
  return 0;
}
