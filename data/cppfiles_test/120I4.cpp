#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    vector<int> bits(64, 0);
    int from = l == 1 ? 0 : log2(l);
    int to = r == 1 ? 0 : log2(r);
    if (from == to)
      cout << 0 << "\n";
    else if (r - l < 100) {
      for (int i = l; i <= r; i++) {
        int temp = i, counter = 0;
        while (temp > 0) {
          bits[counter] += temp % 2;
          temp /= 2;
          counter++;
        }
      }
      int answer = 0;
      for (int i = 0; i < 64; i++) {
        answer = max(answer, bits[i]);
      }
      cout << r - l + 1 - answer << "\n";
    } else {
      int answer = r - pow(2, to) + 1;
      if (to == from + 1)
        answer = max(answer, int(pow(2, to) - l + 1));
      else
        answer = max(answer, int(pow(2, to) - pow(2, to - 1)));
      cout << r - l + 1 - answer << "\n";
    }
  }
  return 0;
}
