#include <bits/stdc++.h>
using namespace std;
const int N = 64;
int n, a[N];
void print() {
  printf("[");
  for (int i = 0; i < n; i++) printf("%d%c", a[i], " ]"[i == n - 1]);
  puts("");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    printf("%d\n", n - 1);
    vector<tuple<int, int, int>> ans;
    for (int i = 0; i < n - 1; i++) {
      int *A = a + i;
      int d = min_element(A, a + n) - A;
      if (d == 0) continue;
      ans.emplace_back(i + 1, n, d);
      rotate(A, A + d, a + n);
    }
    printf("%d\n", int(ans.size()));
    for (auto &&a : ans) {
      printf("%d %d %d\n", get<0>(a), get<1>(a), get<2>(a));
    }
  }
}
