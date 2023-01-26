#include <bits/stdc++.h>
using namespace std;
const int Inf = 0x3f3f3f3f;
long long S, N, K;
void solve() {
  scanf("%lld%lld%lld", &S, &N, &K);
  long long gr = (S + 1) / (K << 1);
  long long ch = gr * K + min(K, (S + 1) % (K << 1));
  if (ch >= N + 1)
    puts("NO");
  else
    puts("YES");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
