#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 50;
int n, m, ans, T, alt[maxn], b[maxn];
long long sum;
void merge(int a[], int l, int r) {
  for (int i = l; i <= r; i++) {
    alt[i] = a[i];
  }
  int mid = (l + r) >> 1;
  int i = l, j = mid + 1;
  for (int pos = l; pos <= r; pos++) {
    if (i == mid + 1) {
      a[pos] = alt[j];
      j++;
    } else if (j == r + 1) {
      a[pos] = alt[i];
      i++;
    } else if (alt[i] > alt[j]) {
      a[pos] = alt[j];
      j++;
      sum += mid - i + 1;
    } else {
      a[pos] = alt[i];
      i++;
    }
  }
}
void merge_sort(int a[], int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  merge_sort(a, l, mid);
  merge_sort(a, mid + 1, r);
  merge(a, l, r);
}
int main() {
  scanf("%d", &T);
  for (int oo = 1; oo <= T; ++oo) {
    sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", &b[i]);
    merge_sort(b, 1, n);
    if (sum % 2)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
