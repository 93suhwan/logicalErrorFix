#include <bits/stdc++.h>
using namespace std;
void run_case() {
  int N;
  cin >> N;
  for (int i = 2; i <= N + 1; ++i) {
    cout << i << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tests;
  cin >> tests;
  while (tests-- > 0) run_case();
  return 0;
}
