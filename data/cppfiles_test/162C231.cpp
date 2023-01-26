#include <bits/stdc++.h>
using namespace std;
int N, ar[200005];
int nxt[200004];
int check(int val) {
  nxt[N - 2] = 0;
  nxt[N - 1] = 0;
  for (int i = N - 1; i >= 2; --i) {
    int x = ar[i] + nxt[i] - val;
    if (x >= 0) {
      x = min(x, ar[i]);
      x /= 3;
      nxt[i - 2] = x + x;
      nxt[i - 1] += x;
    } else
      return 0;
  }
  if ((ar[0] + nxt[0] >= val) && (ar[1] + nxt[1] >= val)) return 1;
  return 0;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int low = 1, high = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &ar[i]);
      high = max(high, ar[i]);
    }
    int ans = 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (check(mid) == 1) {
        ans = max(ans, mid);
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
