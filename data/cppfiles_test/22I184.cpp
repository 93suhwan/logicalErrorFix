#include <bits/stdc++.h>
using namespace std;
const int N = 2E5 + 10;
const int inf = 1 << 30;
long long read() {
  long long a = 0;
  char b = 1, c;
  do
    if ((c = getchar()) == 45) b = -1;
  while (c < 48 || c > 57);
  do a = (a << 3) + (a << 1) + (c & 15);
  while ((c = getchar()) > 47 && c < 58);
  return a * b;
}
void write(long long x, char c) {
  if (x < 0) putchar(45), x = -x;
  char a[20], s = 0;
  do a[++s] = x % 10 | 48;
  while (x /= 10);
  do putchar(a[s]);
  while (--s);
  putchar(c);
}
int main() {
  int n = read();
  vector<set<int>> q(read());
  for (set<int>& x : q) {
    for (int i = read(); i--;) {
      x.insert(read());
    }
  }
  for (int i = 1; i <= n; ++i) {
    int w = i;
    for (set<int> x : q) {
      if (x.count(w)) {
        w = *x.begin();
      }
    }
    if (w ^ 1) {
      puts("REJECTED");
      return 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    int w = i;
    for (set<int> x : q) {
      if (x.count(w)) {
        w = *x.rbegin();
      }
    }
    if (w ^ n) {
      puts("REJECTED");
      return 0;
    }
  }
  puts("ACCEPTED");
}
