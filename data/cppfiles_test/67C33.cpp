#include <bits/stdc++.h>
using namespace std;
int main() {
  int mapsCount;
  float goalProb;
  cin >> mapsCount >> goalProb;
  int ans = 0;
  for (int i = 0; i <= mapsCount; i++) {
    float n = mapsCount, k = i, u = mapsCount - i;
    float prob = (k * u * (u - 1) / 4 + u * k * (k - 1) / 2 +
                  k * (k - 1) * (k - 2) / 6) /
                 (n * (n - 1) * (n - 2) / 6);
    if (prob >= goalProb) {
      ans = i;
      break;
    }
  }
  cout << ans;
  return 0;
}
