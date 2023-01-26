#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    long long sum = c * 3 + b * 2 + a;
    if (sum % 2) {
      printf("1\n");
    } else {
      printf("0\n");
    }
  }
}
