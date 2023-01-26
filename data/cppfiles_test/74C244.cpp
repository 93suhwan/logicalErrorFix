#include <bits/stdc++.h>
using namespace std;
int T, a, b, n;
set<int> s;
int main() {
  scanf("%d", &T);
  while (T--) {
    s.clear();
    scanf("%d%d", &a, &b), n = a + b;
    int ls = n / 2, ms = n / 2;
    if (n & 1) ms++;
    for (int i = max(ms - a, 0); i <= min(ms, b); i++)
      s.insert(i + i - (ms - a));
    for (int i = max(ls - a, 0); i <= min(ls, b); i++)
      s.insert(i + i - (ls - a));
    printf("%d\n", s.size());
    while (!s.empty()) printf("%d ", *s.begin()), s.erase(s.begin());
    puts("");
  }
  return 0;
}
