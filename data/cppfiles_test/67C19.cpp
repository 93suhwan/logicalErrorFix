#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  float P;
  cin >> N >> P;
  int left = 0;
  int right = N;
  while (left < right) {
    int k = (left + right) >> 1;
    float c0 = (N - k) * (N - k - 1) * (N - k - 2) / 6.0;
    float c1 = k * ((N - k) * (N - k - 1)) / 2.0;
    float c2 = k * (k - 1) / 2 * (N - k) / 1.0;
    float c3 = k * (k - 1) * (k - 2) / 6.0;
    float p = (0 + 0.5 * c1 + c2 + c3) / (c0 + c1 + c2 + c3);
    if ((p - P) >= 0) {
      right = k;
    } else {
      left = k + 1;
    }
  }
  cout << left << endl;
  return 0;
}
