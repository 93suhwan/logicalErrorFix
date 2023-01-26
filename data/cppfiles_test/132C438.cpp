#include <bits/stdc++.h>
using namespace std;
int main() {
  int test{0};
  cin >> test;
  for (int a = 0; a < test; ++a) {
    vector<int> input(7, -1);
    for (int b = 0; b < 7; ++b) cin >> input[b];
    cout << input[6] - input[0] - input[1] << " " << input[0] << " " << input[1]
         << '\n';
  }
  return 0;
}
