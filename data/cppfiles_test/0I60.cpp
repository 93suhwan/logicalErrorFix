#include <bits/stdc++.h>
using namespace std;
struct node {
  string a;
  int b;
} s[10000006];
int cmp(node x, node y) { return x.a < y.a; }
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    cin >> s[i].a;
    s[i].b = i;
    int x = s[i].a.length();
    for (int j = 0; i < x; i++) {
      if (j % 2 != 0) {
        s[i].a[j] = s[i].a[j] - (s[i].a[j] - 'a');
      }
    }
  }
  sort(s + 1, s + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    printf("%d ", s[i].b);
  }
}
