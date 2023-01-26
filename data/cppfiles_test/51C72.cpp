#include <bits/stdc++.h>
using namespace std;
inline void run_case() {
  int64_t N;
  cin >> N;
  if (N == 1) {
    cout << 0 << ' ' << 1 << endl;
    return;
  }
  cout << -(N - 1) << ' ' << N << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t T{1};
  cin >> T;
  while (T--) run_case();
}
