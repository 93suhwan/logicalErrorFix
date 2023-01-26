#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  LL N;
  double p;
  cin >> N >> p;
  LL P = p * 10000 + .5;
  for (int i = 0; i <= N; i += 1)
    if ((i * (i - 1) / 2 * (N - i) + i * (i - 1) * (i - 2) / 6) >=
        N * (N - 1) * (N - 2) / 6 * p) {
      cout << i;
      break;
    }
  return 0;
}
