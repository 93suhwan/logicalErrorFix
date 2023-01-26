#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int M = 2e2 + 7;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int a[N];
int cnt[N];
int num[N];
int b[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    memset(cnt, 0, sizeof cnt);
    memset(num, 0, sizeof num);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
      if (cnt[a[i]] >= k)
        cnt1++;
      else {
        cnt2++;
        b[a[i]] = 1;
      }
    }
    int j = 0;
    for (int i = 1; i <= n; i++) {
      if (!b[a[i]]) {
        if (num[a[i]] < k) {
          num[a[i]]++;
          a[i] = num[a[i]];
        } else
          a[i] = 0;
      } else {
        if (i + k > n + 1) {
          a[i] = 0;
          continue;
        }
        j++;
        a[i] = j;
        if (j == k) {
          j = 0;
        }
      }
    }
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
  }
  return 0;
}
