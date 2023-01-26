#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline", "no-stack-protector", "unroll-loops")
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    long long sum = a + b * 2ll + c * 3ll;
    if (sum & 1ll)
      puts("1");
    else
      puts("0");
  }
  return 0;
}
