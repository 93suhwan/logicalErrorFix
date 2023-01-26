#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long mm = 1;
    long long ans = 0;
    while (mm < k) {
      mm = mm << 1;
      ans++;
    }
    if (n > mm) {
      long long num = (n - mm + k - 1) / k;
      ans += num;
    }
    cout << ans << endl;
  }
  return 0;
}
