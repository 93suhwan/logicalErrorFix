#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> ROW = {2, 4};
  vector<int> COL = {3, 5};
  auto Ask = [&](int r, int c) {
    cout << "? " << r << " " << c << endl;
    int answer;
    cin >> answer;
    return answer;
  };
  constexpr int n = 1e9;
  int A = Ask(1, 1);
  int B = Ask(1, n);
  int C = Ask(n, 1);
  int D = Ask(n, n);
  int c1 = 1;
  for (int step = 1 << 30; step; step >>= 1) {
    if (c1 + step < n) {
      int curr = Ask(1, c1 + step);
      if (curr == A - c1 - step + 1) {
        c1 += step;
      }
    }
  }
  int r1 = A + 2 - c1;
  int c2 = r1 - B + n - 1;
  int r2 = 2 * n - D - c2;
  cout << "! " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
  return 0;
}
