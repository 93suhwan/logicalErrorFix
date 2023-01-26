#include <bits/stdc++.h>
using namespace std;
void work() {
  int a, b, c;
  int ans = 5;
  scanf("%d %d %d", &a, &b, &c);
  if ((a % 2 + b % 2 + c % 2) & 1) {
    printf("0\n");
  } else {
    printf("1\n");
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) work();
}
