#include <bits/stdc++.h>
using namespace std;
int r;
int l;
int bits[(int)2e5][18];
int calcBits() {
  for (int i = 0; i <= (int)2e5; i++) {
    for (int j = 0; j <= 18; j++) bits[i][j] = 0;
  }
  for (int i = 1; i <= (int)2e5; i++) {
    for (int j = 0; j <= log2(i); j++) {
      bits[i][j] = bits[i - 1][j];
      if ((i & (1 << j)) != 0) bits[i][j]++;
    }
  }
}
int getMin() {
  int maxBits = 0;
  for (int i = 0; i <= log2(r); i++)
    maxBits = max(maxBits, bits[r][i] - bits[l - 1][i]);
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
