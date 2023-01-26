#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (a >= b) {
    return a;
  } else {
    return b;
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int w, h;
    scanf("%d %d", &w, &h);
    int h1, h2, v1, v2, min1 = 10000000, max1 = 0, min2 = 10000000, max2 = 0,
                        min3 = 10000000, max3 = 0, min4 = 10000000, max4 = 0;
    scanf("%d", &h1);
    int arr[h1 + 1];
    for (int i = 0; i < h1; i++) {
      scanf("%d", &arr[i]);
      if (arr[i] >= max1) {
        max1 = arr[i];
      }
      if (arr[i] <= min1) {
        min1 = arr[i];
      }
    }
    scanf("%d", &h2);
    int brr[h2 + 1];
    for (int i = 0; i < h2; i++) {
      scanf("%d", &brr[i]);
      if (brr[i] >= max2) {
        max2 = brr[i];
      }
      if (brr[i] <= min2) {
        min2 = brr[i];
      }
    }
    scanf("%d", &v1);
    int crr[v1 + 1];
    for (int i = 0; i < v1; i++) {
      scanf("%d", &crr[i]);
      if (crr[i] >= max3) {
        max3 = crr[i];
      }
      if (crr[i] <= min1) {
        min3 = crr[i];
      }
    }
    scanf("%d", &v2);
    int drr[v2 + 1];
    for (int i = 0; i < v2; i++) {
      scanf("%d", &drr[i]);
      if (drr[i] >= max4) {
        max4 = drr[i];
      }
      if (drr[i] <= min4) {
        min4 = drr[i];
      }
    }
    long long int ans1, ans2, ans3, ans4, final = 0;
    ans1 = (arr[h1 - 1] - arr[0]) * h;
    ans2 = (brr[h2 - 1] - brr[0]) * h;
    ans3 = (crr[v1 - 1] - crr[0]) * w;
    ans4 = (drr[v2 - 1] - drr[0]) * w;
    final = max(ans1, ans2);
    final = max(final, ans3);
    final = max(final, ans4);
    printf("%lld\n", final);
  }
  return 0;
}
