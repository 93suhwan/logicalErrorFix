#include <bits/stdc++.h>
bool test = false;
long long mod1 = 1e9 + 7;
long long mod2 = 998244353;
long long inf = 1e10 + 5;
void testCase() {
  long long n, m;
  std::cin >> n >> m;
  std::vector<std::pair<std::string, long long>> s(n);
  for (int i = 0; i <= n - 1; i++) {
    std::cin >> s[i].first;
    s[i].second = i;
  }
  for (int i = 0; i <= n - 1; i++) {
    for (int j = 1; j <= m - 1; j += 2) {
      s[i].first[j] = 'Z' - s[i].first[j] + 'A';
    }
  }
  std::sort(s.begin(), s.end());
  for (int i = 0; i <= n - 1; i++) {
    std::cout << s[i].second + 1 << " ";
  }
  std::cout << "\n";
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
