#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const long long int INFq = 1e18 + 7;
struct Pair {
  int val, index, num;
  Pair(int a = 0, int b = 0, int c = 0) {
    val = a;
    index = b;
    num = c;
  }
};
Pair a[200010];
int cnt[200010];
int col[200010];
bool comp(const Pair& pa, const Pair& pb) {
  if (pa.num != pb.num)
    return pa.num > pb.num;
  else
    return pa.val < pb.val;
}
int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].val);
      a[i].index = i;
      cnt[a[i].val]++;
    }
    for (int i = 1; i <= n; i++) a[i].num = cnt[a[i].val];
    sort(a + 1, a + n + 1, comp);
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    int color = 0;
    for (int i = 1; i <= n; i++) {
      if (cnt[a[i].val] < k) {
        col[a[i].index] = color + 1;
        color++;
        color %= k;
        cnt[a[i].val]++;
      } else {
        col[a[i].index] = 0;
      }
    }
    for (int i = 1; i <= n; i++) printf("%d ", col[i]);
    printf("\n");
  }
}
