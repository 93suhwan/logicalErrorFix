#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    printf("1000000000 ");
    for (int i = 2; i <= n; i++) {
      printf("%d ", i);
    }
    printf("\n");
  }
  return 0;
}
