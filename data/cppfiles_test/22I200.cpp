#include <bits/stdc++.h>
using namespace std;
mt19937_64 rand1(time(0));
const int lim = 2e5;
int n, m, b[15], a[15][45];
bool chk(unsigned long long stt) {
  for (int i = 1, cnt = 0; i <= m; ++i, cnt = 0) {
    for (int j = 1; j <= b[i]; ++j) cnt += stt >> a[i][j] - 1 & 1;
    for (int j = 1; j <= b[i] - cnt; ++j)
      stt &= (1ull << n) - (1ull << a[i][j] - 1) - 1;
    for (int j = b[i]; j > b[i] - cnt; --j) stt |= 1ull << a[i][j] - 1;
  }
  for (int i = 1; i < n; ++i)
    if (stt >> i - 1 & 1 && !(stt >> i & 1)) return 0;
  return 1;
}
int main() {
  srand(time(0));
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
    for (int j = 1; j <= b[i]; ++j) scanf("%d", &a[i][j]);
  }
  for (int i = 1; i <= lim; ++i)
    if (!chk(rand1())) {
      puts("REJECTED");
      return 0;
    }
  puts("ACCECPTED");
  return 0;
}
