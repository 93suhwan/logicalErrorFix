#include <bits/stdc++.h>
using namespace std;
int main() {
  int mapsCount;
  float goalProb;
  cin >> mapsCount >> goalProb;
  mapsCount--;
  int ans = 0;
  for (int i = 0; i <= mapsCount; i++) {
    float n = mapsCount, k = i;
    float prob = (k / n) * (k - 1) / (n - 1) + (1.f - k / n) * k / (n - 1);
    if (prob >= goalProb) ans = i;
  }
  cout << ans;
  return 0;
}
