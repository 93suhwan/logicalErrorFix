#include <bits/stdc++.h>
long long min(long long a, long long b) { return a < b ? a : b; }
unsigned int X;
void srand_() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  X = tv.tv_sec ^ tv.tv_usec | 1;
}
int rand_() { return (X *= 3) >> 1; }
void sort(int *aa, int l, int r) {
  while (l < r) {
    int i = l, j = l, k = r, a = aa[l + rand_() % (r - l)], tmp;
    while (j < k)
      if (aa[j] == a)
        j++;
      else if (aa[j] < a) {
        tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
        i++, j++;
      } else {
        k--;
        tmp = aa[j], aa[j] = aa[k], aa[k] = tmp;
      }
    sort(aa, l, i);
    l = k;
  }
}
int main() {
  int t;
  srand_();
  scanf("%d", &t);
  while (t--) {
    static int aa[200000];
    int n, i;
    long long sum, ans;
    scanf("%d %lld", &n, &sum);
    sum = -sum;
    for (i = 0; i < n; i++) {
      scanf("%d", &aa[i]);
      sum += aa[i];
    }
    if (sum <= 0) {
      printf("0\n");
      continue;
    }
    sort(aa, 0, n);
    ans = sum;
    for (i = n - 1; i >= 1; i--) {
      sum -= aa[i] - aa[0];
      ans = min(ans, n - i + (sum <= 0 ? 0 : (sum + n - i) / (n - i + 1)));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
