#include <bits/stdc++.h>
const int N = 1e6 + 7;
using namespace std;
long long p[N], q[N], sum[N];
long long n, m, mm, Count, pos, ans;
int main() {
  int T;
  cin >> T;
  while (T--) {
    Count = 0;
    ans = -1;
    cin >> m >> n;
    for (int i = 0; i < m; i++) cin >> p[i];
    for (int i = 0; i < m; i++) {
      if (p[i] < ans || i == 0)
        Count++;
      else if (p[i] - ans == 1)
        ans = p[i];
      else if (p[i] - ans >= 1) {
        for (int j = 1; j <= m; j++) {
          if (p[j] > ans && p[j] < p[i]) {
            Count++;
            break;
          }
        }
      }
      ans = p[i];
    }
    if (Count > n)
      printf("No\n");
    else
      printf("Yes\n");
  }
  return 0;
}
