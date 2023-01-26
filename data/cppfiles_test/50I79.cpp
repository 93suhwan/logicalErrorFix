#include <bits/stdc++.h>
using namespace std;
const int N = 200007;
const long long mod = 998244353;
struct node {
  long long a;
  int pos;
} id[N];
bool cmp(node x, node y) { return x.a < y.a; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &id[i].a);
    id[i].a %= mod;
    id[i].pos = i;
  }
  sort(id + 1, id + 1 + n, cmp);
  long long ans = id[1].a;
  for (int i = 2; i <= n; i++) {
    if (id[i].pos - id[i - 1].pos == 1 || id[i].pos - id[i - 1].pos == -1) {
      ans = ans * (id[i].a - 1) % mod;
    } else {
      ans = ans * id[i].a % mod;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
