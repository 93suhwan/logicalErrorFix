#include <bits/stdc++.h>
bool test = true;
long long mod1 = 1e9 + 7;
long long mod2 = 998244353;
long long inf = 1e15 + 5;
void testCase() {
  long long n;
  std::cin >> n;
  std::set<long long> a;
  long long par = 0;
  for (int i = 0; i <= n - 1; i++) {
    long long x;
    std::cin >> x;
    a.insert(x);
  }
  for (long long val : a) {
    par += (val % 2);
  }
  std::cout << (par % 2) << "\n";
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
