#include <bits/stdc++.h>
const int N = 1e6 + 7;
using namespace std;
long long p[N], q[N], sum[N];
long long n, m, mm, Count;
int main() {
  int T;
  cin >> T;
  while (T--) {
    Count = 0;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> p[i];
    for (int i = 2; i <= m; i++) {
      if (p[i] < p[i - 1]) Count++;
      if (p[i] > p[i - 1]) {
        for (int j = 1; j <= m; j++) {
          if (p[j] < p[i] && p[j] > p[i - 1]) {
            Count++;
            break;
          }
        }
      }
    }
    if (Count > n)
      printf("No\n");
    else
      printf("Yes\n");
  }
  return 0;
}
