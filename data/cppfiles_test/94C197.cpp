#include <bits/stdc++.h>
using namespace std;
long long t;
long long a;
vector<long long> vec;
long long ans;
long long ol[20];
long long siz;
void f(long long here) {
  if (here >= siz) {
    long long gap = 1;
    long long ff = 0;
    vector<long long> tmp = vec;
    for (long long i = siz - 1; i >= 0; i--) {
      if (!ol[i]) {
        if (tmp[i] < 0) {
          gap = 0;
          break;
        }
        gap = gap * (tmp[i] + 1);
      } else {
        ff = 1;
        long long L = tmp[i] + 1;
        long long R = 9;
        if (L <= R) {
          gap = gap * (R - L + 1);
          if (i >= 2) tmp[i - 2]--;
        } else {
          gap = 0;
          break;
        }
      }
    }
    if (!ff) gap -= 2;
    ans += gap;
    return;
  }
  ol[here] = 0;
  f(here + 1);
  ol[here] = 1;
  f(here + 1);
}
int main(void) {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &a);
    vec.clear();
    ans = 0;
    while (a) {
      vec.push_back(a % 10);
      a /= 10;
    }
    reverse(vec.begin(), vec.end());
    siz = (long long)vec.size();
    f(2);
    printf("%lld\n", ans);
  }
  return 0;
}
