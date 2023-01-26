#include <bits/stdc++.h>
long long arr[200002];
const long long pi = 998244353;
int main() {
  long long n, b = 0;
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &arr[i]);
    if (arr[i] == 1) b++;
    if (arr[i] < arr[1]) {
      arr[1] = arr[1] ^ arr[i];
      arr[i] = arr[1] ^ arr[i];
      arr[1] = arr[1] ^ arr[i];
    }
  }
  long long he = arr[1];
  for (int i = 2; i <= n; i++) {
    he *= (arr[i] - 1);
    he %= pi;
  }
  printf("%lld", he);
}
