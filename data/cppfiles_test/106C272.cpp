#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (int i = 2; i <= n + 1; i++) {
      printf("%d ", i);
    }
    printf("\n");
  }
  return 0;
}
