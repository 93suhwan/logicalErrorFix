#include <bits/stdc++.h>
using namespace std;
int T, n, m;
bool searche(int x) {
  long long sum = 1;
  bool p = 1;
  while (p && sum <= 1000000000) {
    if (x == sum) return 0;
    sum = sum * 10;
    p = 1;
  }
  return p;
}
pair<int, int> geted(long long a) {
  long long b = 1, ti = a;
  assert(searche(a));
  bool flag = 1;
  while (ti > 0 && flag) {
    if (ti % 10) {
      return {a - b, b};
    }
    b *= 10;
    ti /= 10;
    flag = 1;
  }
}
int main() {
  scanf("%d", &T);
  for (int oo = 1; oo <= T; ++oo) {
    scanf("%d%d", &n, &m);
    swap(n, m);
    multiset<int> seet{m};
    while (seet.size() < n) {
      bool p = 0;
      int pos = 0;
      for (auto i = seet.begin(); i != seet.end(); i++)
        if (searche(*i)) {
          pos = *i;
          p = 1;
          break;
        }
      if (p) {
        p = 1;
        seet.erase(seet.find(pos));
        auto [q1, q2] = geted(pos);
        seet.insert(q2);
        seet.insert(q1);
      } else if (p == 0) {
        p = 0;
        pos = *seet.upper_bound(1);
        seet.erase(seet.find(pos));
        seet.insert(pos / 10);
        seet.insert(pos / 10 * 9);
      }
    }
    for (auto i : seet) printf("%d ", i);
    printf("\n");
  }
  return 0;
}
