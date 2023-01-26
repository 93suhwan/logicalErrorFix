#include <bits/stdc++.h>
using namespace std;
priority_queue<int> p;
int _, n, i, x, cnt[200001];
long long s;
int main() {
  scanf("%d", &_);
  while (_--) {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &x), cnt[x]++;
    s = 0;
    while (!p.empty()) p.pop();
    for (i = 0; i <= n; i++) {
      printf("%lld ", max(-1ll, s + cnt[i]));
      while (cnt[i]) cnt[i]--, p.push(i);
      if (!p.empty())
        s += i - p.top(), p.pop();
      else
        s = -1e18;
    }
    puts("");
  }
}
