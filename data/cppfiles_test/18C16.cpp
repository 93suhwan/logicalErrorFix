#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        heap;
    int n, d, ans = 0;
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (!a[i]) heap.push({0, i});
    }
    while (heap.size()) {
      auto t = heap.top();
      heap.pop();
      if (a[(t.second + d) % n]) {
        a[(t.second + d) % n] = 0;
        heap.push({t.first + 1, (t.second + d) % n});
        ans = max(ans, t.first + 1);
      }
    }
    for (int i = 0; i < n; i++)
      if (a[i]) ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}
