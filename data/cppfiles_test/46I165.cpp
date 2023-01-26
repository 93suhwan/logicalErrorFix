#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long cnt = 0;
  for (int i = 0; i < n; i += 2) {
    long long curr = a[i];
    for (int j = i + 1; j < n; j++) {
      if (j % 2 == 0)
        curr += a[j];
      else {
        long long after = curr - a[j];
        if (after < a[i]) {
          if (after < 0)
            cnt += a[i];
          else
            cnt += abs(a[i] - after);
        }
        curr = after;
        if (curr < 0) break;
      }
    }
  }
  cout << cnt << "\n";
  return 0;
}
