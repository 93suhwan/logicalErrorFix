#include <bits/stdc++.h>
using namespace std;
int tc, n;
int a[200001];
int nums[200001];
int main() {
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) nums[i] = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      nums[a[i]]++;
    }
    int adds = 0;
    bool ok = 1;
    for (int i = 0; i <= n; i++) {
      if (!ok) {
        printf(" -1");
        continue;
      }
      if (i == 0) {
        printf("%d", nums[0]);
        for (int j = 1; j < nums[0]; j++) pq.push(0);
      } else {
        int cnt = nums[i] + adds;
        if (nums[i - 1] == 0) {
          if (pq.empty()) {
            cnt = -1;
            ok = 0;
          } else {
            cnt += i - 1 - pq.top();
            adds += i - 1 - pq.top();
            pq.pop();
          }
        }
        for (int j = 1; j < nums[i]; j++) pq.push(i);
        printf(" %d", cnt);
      }
    }
    printf("\n");
  }
  return 0;
}
