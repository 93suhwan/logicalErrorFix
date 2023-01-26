#include <bits/stdc++.h>
using namespace std;
vector<int> rangesBegins;
int binarySearch(int value) {
  int start = 0;
  int end = 31623;
  int medium;
  while (start != end) {
    medium = (start + end + 1) / 2;
    if (rangesBegins[medium] <= value)
      start = medium;
    else
      end = medium - 1;
  }
  return start;
}
int main() {
  int rangeBgn = 1, diff = 1, t, k;
  rangesBegins.push_back(1);
  while (rangeBgn < 1e9) {
    rangeBgn += diff;
    diff += 2;
    rangesBegins.push_back(rangeBgn);
  }
  cin >> t;
  while (t--) {
    cin >> k;
    rangeBgn = binarySearch(k);
    if (k <= (rangesBegins[rangeBgn + 1] - rangesBegins[rangeBgn]) / 2 +
                 rangesBegins[rangeBgn]) {
      cout << k - rangesBegins[rangeBgn] + 1 << " " << rangeBgn + 1 << "\n";
    } else {
      cout << rangeBgn + 1 << " " << rangesBegins[rangeBgn + 1] - k << "\n";
    }
  }
  return 0;
}
