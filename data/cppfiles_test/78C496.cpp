#include <bits/stdc++.h>
using namespace std;
void solve(int test_case) {
  int a, b;
  cin >> a >> b;
  cout << b % max(b / 2 + 1, a) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int test_case = 1; test_case <= t; ++test_case) {
    solve(test_case);
  }
}
