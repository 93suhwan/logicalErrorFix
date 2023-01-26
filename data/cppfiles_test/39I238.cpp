#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) f |= (c == '-'), c = getchar();
  while (isdigit(c)) sum = (sum << 1) + (sum << 3) + (c ^ 48), c = getchar();
  return f ? -sum : sum;
}
const int N = 1010;
int n, q[N];
int ask() {
  printf("? ");
  for (register int i = (1); i <= (n); i++) printf("%d ", q[i]);
  printf("\n");
  fflush(stdout);
  return read();
}
int a[N];
void report() {
  printf("! ");
  for (register int i = (1); i <= (n); i++) printf("%d ", a[i]);
  printf("\n");
  fflush(stdout);
}
int main() {
  n = read();
  for (register int i = (1); i <= (n - 1); i++) q[i] = 1;
  for (register int i = (1); i <= (n); i++) {
    q[n] = i;
    int res = ask();
    if (res) {
      a[n] = n - i + 1;
      break;
    }
  }
  if (!a[n]) a[n] = n;
  q[n] = n - a[n] + 1;
  for (register int i = (1); i <= (n); i++) {
    for (register int j = (1); j <= (n - 1); j++) q[j] = i;
    int res = ask();
    if (res) a[res] = n - i + 1;
  }
  report();
}
