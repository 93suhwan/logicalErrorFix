#include <bits/stdc++.h>
using namespace std;
void printNum(int* nums, int numsSize) {
  bool f = true;
  for (int i = numsSize - 1; i >= 0; i--) {
    if (!nums[i] && f)
      continue;
    else {
      f = false;
      cout << nums[i];
    }
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, s;
    cin >> a >> s;
    int b[20], bSize = 0;
    int i = 0, j = 0;
    bool f = true;
    while (s) {
      int x = a % 10;
      int y = s % 10;
      a /= 10;
      s /= 10;
      if (x <= y)
        b[bSize++] = y - x;
      else {
        y += s % 10 * 10;
        s /= 10;
        if (x < y && y >= 10 && y <= 18) {
          b[bSize++] = y - x;
        } else {
          f = false;
          cout << -1 << endl;
          break;
        }
      }
    }
    if (!f) continue;
    if (a)
      cout << -1 << endl;
    else
      printNum(b, bSize);
  }
  return 0;
}
