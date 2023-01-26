#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n][5];
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < 5; j++) cin >> arr[i][j];
    }
    long long mx = -1;
    long long g = -1;
    set<long long> s;
    int f = 0;
    long long cc = 1;
    long long ccc = 1;
    long long idx = 0;
    for (long long i = 1; i < n; i++) {
      long long c = 0;
      for (long long j = 0; j < 5; j++)
        if (arr[idx][j] > arr[i][j]) c++;
      if (c >= 3) idx = i;
    }
    for (long long i = 0; i < n; i++) {
      long long c = 0;
      for (long long j = 0; j < 5; j++)
        if (arr[idx][j] > arr[i][j]) c++;
      if (c >= 3) {
        idx = -2;
        break;
      }
    }
    if (n == 1)
      cout << 1 << '\n';
    else
      cout << idx + 1 << '\n';
  }
  return 0;
}
