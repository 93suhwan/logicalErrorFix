#include <bits/stdc++.h>
const int oo = 2e5 + 7;
int n, a[oo];
int left[oo], right[oo];
bool solve() {
  int x = 0, y = n - 1;
  bool alice = true;
  while (x < y) {
    bool levi = a[x] >= a[y];
    if (levi) {
      int kraj = left[x + 1];
      if ((kraj - x) % 2) return alice;
    } else {
      int kraj = right[y - 1];
      if ((y - kraj) % 2) return alice;
    }
    if (levi)
      x++;
    else
      y--;
    alice ^= 1;
  }
  if ((x == 0 || a[x] > a[x - 1]) && (x == n - 1 || a[x] > a[x + 1]))
    return alice;
  return !alice;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int last = -1;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] <= a[i + 1]) last = i;
    right[i] = last;
  }
  last = n;
  for (int i = n - 1; i > 0; i--) {
    if (a[i] <= a[i - 1]) last = i;
    left[i] = last;
  }
  printf("%s\n", (solve() ? "Alice" : "Bob"));
}
