#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
long long g(long long a, long long b) {
  if (b == 0) return a;
  return g(b, a % b);
}
double min(double x, double y) {
  if (x < y) return x;
  return y;
}
int64_t max(int64_t x, int64_t y) {
  if (x > y) return x;
  return y;
}
void solveandrun(int testo) {
  long long k;
  cin >> k;
  if (k == 1) {
    cout << 1 << " " << 1;
    return;
  }
  long long i = 1, ans = 0;
  while (i * i < k) ans = i, i += 1;
  if (k == i * i - ans)
    cout << i << " " << i;
  else if (k > i * i - ans) {
    cout << i << " " << i * i - k + 1;
  } else if (k < i * i - ans)
    cout << k - ans * ans << " " << i;
}
int32_t main() {
  int i = 1;
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solveandrun(t);
    cout << "\n";
  }
}
