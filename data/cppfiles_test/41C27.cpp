#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
int c = 1;
int n, k;
int col(int a, int b) {
  int ret = 0;
  while (a != b) {
    ret++;
    a /= k;
    b /= k;
  }
  return ret;
}
int main() {
  cin >> n >> k;
  int dk = k;
  while (dk < n) {
    dk *= k;
    c++;
  }
  printf("%d\n", c);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) printf("%d ", col(i, j));
}
