#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> s[300005], p[300005], zczc;
int main() {
  string sr;
  long long t, n, q, i, j, k, a, b, c, d;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld", &n, &q);
    cin >> sr;
    for (i = 1, a = b = 0; i <= n; i++) {
      if ((i % 2 == 1 and sr[i - 1] == '+') or
          (i % 2 == 0 and sr[i - 1] == '-'))
        a++;
      else
        b++;
      s[i] = {a, b};
    }
    while (q--) {
      scanf("%lld%lld", &c, &d);
      zczc.first = s[d].first - s[c - 1].first;
      zczc.second = s[d].second - s[c - 1].second;
      if ((d - c + 1) % 2 == 1)
        printf("1\n");
      else {
        if (zczc.first == zczc.second)
          printf("0\n");
        else
          printf("2\n");
      }
    }
  }
  return 0;
}
