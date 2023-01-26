#include <bits/stdc++.h>
bool test = true;
long long mod1 = 1e9 + 7;
long long mod2 = 998244353;
long long inf = 1e15 + 5;
void testCase() {
  long long n;
  std::cin >> n;
  std::vector<long long> a(n);
  long long par = 0;
  for (int i = 0; i <= n - 1; i++) {
    std::cin >> a[i];
    par += (a[i] % 2);
  }
  if (!par || par == n || par == n - par) {
    std::cout << "0\n";
    return;
  }
  std::cout << "1\n";
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
