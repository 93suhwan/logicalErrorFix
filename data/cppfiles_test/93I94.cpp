#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long i = 1, cnt = 0;
    while (i < k && i < n) {
      cnt++;
      i = i * 2;
    }
    if (i < n) {
      cnt += (n - i) % k + (n - i) / k;
    }
    cout << cnt << endl;
  }
  return 0;
}
