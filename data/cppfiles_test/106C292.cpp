#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long num = 1;
    cin >> n;
    if (n == 1) {
      cout << 1 << '\n';
    } else {
      long long i = 3, count, c;
      if (n > 1) {
        printf("2 ");
      }
      for (count = 2; count <= n; i++) {
        for (c = 2; c < i; c++) {
          if (i % c == 0) break;
        }
        if (c == i) {
          printf("%d ", i);
          count++;
        }
      }
      cout << endl;
    }
  }
  return 0;
}
