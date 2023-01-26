#include <bits/stdc++.h>
using namespace std;
int r;
int l;
int bits[(int)2e5][18];
int calcBits() {
  for (int i = 0; i <= 18; i++) bits[0][i] = 0;
  for (int i = 1; i <= (int)2e5; i++) {
    for (int j = 0; j <= 18; j++) {
      bits[i][j] = bits[i - 1][j];
      if ((i & (1 << j)) != 0) bits[i][j]++;
    }
  }
}
int getMin() {
  int val;
  int maxBits = 0;
  val = log2(r);
  for (int i = 0; i <= val; i++) {
    printf("%d - [%d | %d]\n", i, bits[r][i], bits[l - 1][i]);
    maxBits = max(maxBits, bits[r][i] - bits[l - 1][i]);
  }
  printf("-> %d\n", maxBits);
  return (1 + (r - l)) - maxBits;
}
int main() {
  int t;
  scanf("%d", &t);
  calcBits();
  for (int i = 0; i < t; i++) {
    scanf("%d", &l);
    scanf("%d", &r);
    printf("%d\n", getMin());
  }
}
