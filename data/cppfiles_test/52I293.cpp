#include <bits/stdc++.h>
void solve() {
  int n;
  scanf("%d", &n);
  int arr[n];
  int sumA = 0, sumB = 0;
  int sizeA = 0, sizeB = n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    sumB += arr[i];
  }
  double max = INT_MIN;
  for (int i = 0; i < n - 1; i++) {
    sumA += arr[i];
    sizeA++;
    sumB -= arr[i];
    sizeB--;
    double temp = (float)sumA / sizeA + (float)sumB / sizeB;
    if (max < temp) {
      max = temp;
    }
  }
  printf("%lf\n", max);
}
int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int tc = 1; tc <= ntc; tc++) {
    solve();
  }
  return 0;
}
