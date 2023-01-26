#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) { return (a < b) ? a : b; }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, sum = 0;
    scanf("%d %d", &n, &k);
    int arr[n + 3];
    for (int i = 1; i <= n; i++) {
      scanf("%d", &arr[i]);
    }
    sort(arr + 1, arr + 1 + n);
    for (int i = 1; i <= n - 2 * k; i++) {
      sum = sum + arr[i];
    }
    int p = n - k, q = n;
    while (p > n - 2 * k) {
      if (arr[p] == arr[q]) {
        sum++;
      }
      p--;
      q--;
    }
    printf("%d\n", sum);
  }
  return 0;
}
