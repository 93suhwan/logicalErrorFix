#include <bits/stdc++.h>
using namespace std;
int r;
int l;
int getMin() {
  int val1;
  int val2;
  int val3;
  int count1;
  int count2;
  int count3;
  val1 = log2(r);
  val2 = pow(2, val1);
  val3 = pow(2, val1 - 1);
  count1 = 1 + (r - ((l > val2) ? l : val2));
  count2 = (l <= val3) ? val3 : (val2 - l);
  count3 = ceil(r / 2.0) - ceil((l - 1) / 2.0);
  return (1 + (r - l)) - max({count1, count2, count3});
}
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &l);
    scanf("%d", &r);
    printf("%d\n", getMin());
  }
}
