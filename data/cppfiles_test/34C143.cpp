#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
const long long INF = 1000000000000000;
int a[N];
int main() {
  int t;
  cin >> t;
  for (int q = 0; q < t; q++) {
    int n, k;
    cin >> n >> k;
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    long long answer = -INF;
    for (long long j = 1; j < n; j++) {
      long long i = j - 1;
      while (i >= 0 and (i + 1) * (j + 1) - k * a[j] > answer) {
        long long result = (i + 1) * (j + 1) - k * (a[i] | a[j]);
        answer = max(answer, result);
        i--;
      }
    }
    cout << answer << endl;
  }
  return 0;
}
