#include <bits/stdc++.h>
using namespace std;
long long get(long long a, long long s) {
  vector<int> v1, v2, res;
  while (a) v1.push_back(a % 10), a /= 10;
  while (s) v2.push_back(s % 10), s /= 10;
  int i = 0, j = 0;
  for (i; i < v1.size(); i++) {
    if (j > v2.size()) return -1;
    if (v2[j] >= v1[i]) {
      res.push_back(v2[j] - v1[i]);
      j++;
    } else {
      j++;
      if (j > v2.size() || v2[j] != 1) return -1;
      res.push_back(10 + v2[j - 1] - v1[i]);
      j++;
    }
  }
  while (j < v2.size()) res.push_back(v2[j++]);
  long long c = 0;
  for (int i = res.size() - 1; i >= 0; i--) c = 10 * c + res[i];
  return c;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long a, s;
    scanf("%lld%lld", &a, &s);
    printf("%lld\n", get(a, s));
  }
  return 0;
}
