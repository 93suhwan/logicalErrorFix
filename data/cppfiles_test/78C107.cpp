#include <bits/stdc++.h>
using namespace std;
template <class T>
T sgn(T x) {
  if (x < 0)
    return -1;
  else if (x > 0)
    return 1;
  else
    return 0;
}
template <class T>
int cmp(const void* a, const void* b) {
  return sgn<T>(*(T*)a - *(T*)b);
}
template <class T>
int rcmp(const void* a, const void* b) {
  return sgn<T>(*(T*)b - *(T*)a);
}
int gcd(int x, int y) {
  unsigned int tmp;
  while (y != 0) {
    tmp = x;
    x = y;
    y = tmp % y;
  }
  return x;
}
int main() {
  int t = 1;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    int* a = new int[n];
    int* bits = new int[30]{};
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      int j = 0;
      while (x > 0) {
        if (x % 2 == 1) bits[j]++;
        j++;
        x /= 2;
      }
    }
    int gcd_ = 0;
    for (int i = 0; i < 30; i++) gcd_ = gcd(gcd_, bits[i]);
    for (int i = 1; i <= n; i++)
      if (gcd_ % i == 0) printf("%d ", i);
    putchar('\n');
    delete[] a;
  }
  return 0;
}
