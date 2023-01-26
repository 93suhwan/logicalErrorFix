#include <bits/stdc++.h>
using namespace std;
void test_case() {
  int64_t c, d;
  cin >> c >> d;
  if (c == 0 and d == 0) {
    cout << 0 << "\n";
    return;
  }
  if (c == d) {
    cout << 1 << "\n";
    return;
  }
  if (abs(c - d) % 2 == 0) {
    cout << 2 << "\n";
    return;
  }
  cout << -1 << "\n";
  return;
}
int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t T;
  cin >> T;
  while (T--) {
    test_case();
  }
  return 0;
}
