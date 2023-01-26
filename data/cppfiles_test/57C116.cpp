#include <bits/stdc++.h>
using namespace std;
int t, n, a[2025];
int _find(int x) {
  for (int i = 0; i < n; i++)
    if (a[i] == x) return i;
  return -1;
}
int main() {
  for (scanf("%d", &t); t--;) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    if (n % 2 == 0 && a[n - 1] != n) {
      puts("-1");
      continue;
    }
    if (n % 2 == 0) n--;
    vector<int> v;
    for (int i = 0; i < n; i++)
      if (i % 2 == a[i] % 2) {
        puts("-1");
        goto next;
      }
    for (int i = n; i > 1; i -= 2) {
      int t = _find(i);
      v.push_back(t + 1);
      reverse(a, a + t + 1);
      t = _find(i - 1);
      v.push_back(t);
      reverse(a, a + t);
      v.push_back(i);
      reverse(a, a + i);
      t = _find(i);
      v.push_back(t + 1);
      reverse(a, a + t + 1);
      v.push_back(i);
      reverse(a, a + i);
    }
    printf("%d\n", (int)v.size());
    for (auto &i : v) printf("%d ", i);
    puts("");
  next:;
  }
}
