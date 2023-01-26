#include <bits/stdc++.h>
using namespace std;
int solve(int a, int b, int c) {
  int circSize = 2 * (abs(a - b));
  if (c >= max(1, min(a, b) - (circSize / 2 - 1)) &&
      c <= max(a, b) - min(a, b) + circSize / 2 - 1) {
    int ans = (max(a, b) - min(a, b) + c) % circSize;
    if (ans == 0) {
      return circSize;
    } else {
      return ans;
    }
  }
  return -1;
}
int main() {
  int cases;
  cin >> cases;
  int num;
  for (int i = 0; i < cases; i++) {
    int personA;
    int personB;
    int personC;
    int totalPeople;
    cin >> personA >> personB >> personC;
    cout << solve(personA, personB, personC) << endl;
  }
}
