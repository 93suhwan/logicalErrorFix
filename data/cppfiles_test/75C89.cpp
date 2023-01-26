#include <bits/stdc++.h>
using namespace std;
int a[200005];
int l[200005];
int r[200005];
bool alice(int u, int v) {
  if (u + 1 == v) return 1;
  if (a[u] == a[v])
    return (r[u] | l[v]) & 1;
  else if (a[u] > a[v])
    return (r[u] & 1) || (l[v] == 1) || !alice(u, v - 1);
  else
    return (l[v] & 1) || (r[u] == 1) || !alice(u + 1, v);
}
int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", a + i);
  for (i = 1; i <= n; i++) l[i] = (a[i] < a[i - 1]) * l[i - 1] + 1;
  for (i = n; i >= 1; i--) r[i] = (a[i] < a[i + 1]) * r[i + 1] + 1;
  printf(alice(1, n) ? "Alice\n" : "Bob\n");
  return 0;
}
