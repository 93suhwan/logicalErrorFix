#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  int x = 0;
  bool f = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) f |= (c == '-');
  for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
  return f ? -x : x;
}
bitset<512> sta[512];
int main() {
  int n = rd();
  for (int i = 0; i < 512; ++i) sta[i][0] = 1;
  for (int i = 1; i <= n; ++i) {
    int x = rd();
    for (int i = 0; i < 512; ++i)
      if (sta[x][i]) sta[x][i ^ x] = 1;
    for (int i = x + 1; i < 512; ++i) sta[i] |= sta[x];
  }
  printf("%d\n", sta[511].count());
  for (int i = 0; i < 512; ++i)
    if (sta[511][i]) printf("%d ", i);
  return 0;
}
