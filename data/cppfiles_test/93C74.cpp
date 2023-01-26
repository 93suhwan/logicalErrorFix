#include <bits/stdc++.h>
using namespace std;
long long check(long long n, long long k) {
  long long loaded = 1;
  long long count = 0;
  if (n == 1) {
    return 0;
  }
  while ((loaded < n) && (loaded < k)) {
    count++;
    loaded *= 2;
  }
  if (loaded < n) {
    if ((n - loaded) % k != 0) {
      count++;
    }
    count += (n - loaded) / k;
  }
  return count;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long n, k;
    cin >> n >> k;
    cout << check(n, k) << endl;
  }
}
