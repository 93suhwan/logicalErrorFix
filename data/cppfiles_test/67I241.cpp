#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int a[N];
int n;
int main() {
  int t;
  int a, b, c;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &a, &b, &c);
    int sum, d, ans, ans1;
    sum = abs(a - b) * 2;
    if (a > sum || b > sum || c > sum) printf("-1\n");
    printf("%d", (c - 1 + (sum / 2)) % sum + 1);
  }
  return 0;
}
