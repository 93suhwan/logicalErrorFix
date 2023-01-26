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
    long long int w, h;
    scanf("%lld %lld", &w, &h);
    long long int h1, h2, v1, v2;
    scanf("%lld", &h1);
    long long int arr[h1 + 1];
    for (int i = 0; i < h1; i++) {
      scanf("%lld", &arr[i]);
    }
    scanf("%lld", &h2);
    long long int brr[h2 + 1];
    for (int i = 0; i < h2; i++) {
      scanf("%lld", &brr[i]);
    }
    scanf("%lld", &v1);
    long long int crr[v1 + 1];
    for (int i = 0; i < v1; i++) {
      scanf("%lld", &crr[i]);
    }
    scanf("%lld", &v2);
    long long int drr[v2 + 1];
    for (int i = 0; i < v2; i++) {
      scanf("%lld", &drr[i]);
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
