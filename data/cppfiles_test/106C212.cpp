#include <bits/stdc++.h>
using namespace std;
long long int Mod = 1e9 + 7;
long long int mult(long long int a, long long int b) {
  long long int ret = 1;
  ret = (a * b) % Mod;
  return ret;
}
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int ret = 1;
  while (b) {
    if (b & 1) {
      ret = mult(ret, a);
    }
    a = mult(a, a);
    b >>= 1;
  }
  return ret;
}
void test_case() {
  int n;
  cin >> n;
  for (int i = 2; i < n + 2; i++) cout << i << ' ';
  cout << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    test_case();
  }
}
