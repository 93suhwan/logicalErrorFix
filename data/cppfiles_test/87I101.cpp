#include <bits/stdc++.h>
bool test = true;
long long mod1 = 1e9 + 7;
long long mod2 = 998244353;
long long inf = 1e10 + 5;
void testCase() {
  long long n, m;
  std::cin >> n >> m;
  std::vector<std::pair<long long, long long>> a(m);
  std::vector<long long> b(m), c(m);
  for (int i = 0; i <= m - 1; i++) {
    std::cin >> a[i].first;
    a[i].second = i;
    b[i] = a[i].first;
  }
  std::sort(a.begin(), a.end());
  long long cnt = 0;
  for (int i = 0; i <= m - 1; i++) {
    long long pos = -1;
    for (int j = 0; j <= m - 1; j++) {
      if (a[j].first == b[i]) {
        pos = j;
        break;
      }
    }
    for (int j = 0; j <= m - 1; j++) {
      if (j == pos) {
        c[j] = 1;
        break;
      }
      cnt += c[j];
    }
  }
  std::cout << cnt << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.precision(15);
  long long t = 1;
  if (test) {
    std::cin >> t;
  }
  for (long long i = 0; i <= t - 1; i++) {
    testCase();
  }
}
