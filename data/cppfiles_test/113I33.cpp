#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, a, b, c;
  long long int sum = 0, k, j;
  scanf("%d", &n);
  long long int array[n];
  for (i = 0; i < n; i++) {
    scanf("%lld", &array[i]);
    sum = sum + array[i];
  }
  sort(array, array + n);
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    k = 0;
    j = 0;
    long long int x, y;
    scanf("%lld%lld", &x, &y);
    a = 0;
    c = n - 1;
    for (; c > a;) {
      b = (a + c) / 2;
      if (array[b] >= x)
        c = b;
      else if (array[b] < x)
        a = b + 1;
    }
    if (x > array[a]) k = x - array[a];
    if (y > sum - array[a]) k = k + y - sum + array[a];
    a--;
    for (; array[a] == x;) a--;
    if (x > array[a]) j = x - array[a];
    if (y > sum - array[a]) j = j + y - sum + array[a];
    if (j > k)
      printf("%lld\n", k);
    else
      printf("%lld\n", j);
  }
  return 0;
}
