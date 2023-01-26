#include <bits/stdc++.h>
using namespace std;
int num[300005];
int snum[300005];
long long x[300005];
long long sum[300005];
long long mod[550];
vector<int> v;
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (v.size() == 550) {
      for (auto b : v) {
        num[b]++;
        x[b] += b;
        for (int j = 2; j < 550; j++) mod[j] += b % j;
      }
      v.clear();
      for (int i = 1; i <= 300000; i++) {
        snum[i] = snum[i - 1] + num[i];
        sum[i] = sum[i - 1] + x[i];
      }
    }
    int a;
    scanf("%d", &a);
    ans += snum[300000] * (long long)a;
    for (int i = 1, last = a, next;; i++) {
      next = a / (i + 1);
      if (next < i) next = i;
      ans -= i * (sum[last] - sum[next]);
      ans -= a / i * x[i];
      if (i == next) break;
      last = next;
    }
    if (a < 550) {
      ans += mod[a];
    } else {
      long long d = 0;
      for (int i = a; i <= 300000; i += a) {
        d += snum[300000] - snum[i - 1];
      }
      ans += sum[300000] - d * a;
    }
    for (auto &b : v) {
      ans += b % a + a % b;
    }
    v.push_back(a);
    printf("%lld%c", ans, " \n"[i == n]);
  }
  return 0;
}
