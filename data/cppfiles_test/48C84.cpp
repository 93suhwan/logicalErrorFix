#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int T, n;
int a[N], b[N];
long long tree[N];
void add(int x, int k) {
  for (; x <= n; x += x & -x) tree[x] += k;
}
long long query(int x) {
  long long ans = 0;
  for (; x; x -= x & -x) ans += tree[x];
  return ans;
}
int main(int argc, char *argv[]) {
  cin >> T;
  while (T--) {
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) b[i] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      b[a[i]]++;
    }
    if (n < 3) {
      if (n == 1) puts("YES");
      if (n == 2 && a[1] <= a[2])
        puts("YES");
      else if (n == 2)
        puts("NO");
      continue;
    }
    bool f = 1;
    for (int i = 1; i <= n; i++) {
      if (b[i] >= 2) {
        f = 0;
        break;
      }
    }
    if (!f) {
      puts("YES");
      continue;
    }
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= n; i++) {
      ans += query(n) - query(a[i] - 1);
      add(a[i], 1);
    }
    if (ans % 2)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
