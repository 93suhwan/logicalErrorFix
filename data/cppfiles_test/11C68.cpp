#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, tr[N];
int lowbit(int x) { return x & (-x); }
void update(int x, int t) {
  for (int i = x; i <= n; i += lowbit(i)) tr[i] = max(tr[i], t);
}
int ask(int x) {
  int ans = 0;
  for (int i = x; i > 0; i -= lowbit(i)) ans = max(ans, tr[i]);
  return ans;
}
set<int> e[N];
int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    int j = i - x;
    if (j >= 0 && j <= i - 1) e[j].insert(x);
  }
  for (int i = 0; i <= n; i++) {
    for (auto x : e[i]) {
      int j = ask(x - 1);
      update(x, j + 1);
    }
  }
  printf("%d", ask(n));
  return 0;
}
