#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long TC = 1;
  while (TC--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    vector<long long> linc(n, 1), rinc(n, 1);
    for (long long i = 1; i < n; i++) {
      if (a[i] < a[i - 1]) rinc[i] += rinc[i - 1];
    }
    for (long long i = n - 1 - 1; i >= 0; i--) {
      if (a[i] < a[i + 1]) linc[i] += linc[i + 1];
    }
    long long l = 0, r = n - 1;
    string ans[] = {"Alice", "Bob"};
    long long player = 0, prev = 0;
    while (l <= r) {
      if (prev >= max(a[l], a[r])) {
        player--;
        break;
      }
      if (a[l] >= a[r] && linc[l] % 2 || a[r] >= a[l] && rinc[r] % 2) break;
      if (a[l] < a[r] && a[l] > prev) {
        prev = a[l];
        l++;
      } else if (a[r] > prev) {
        prev = a[r];
        r--;
      } else {
        player++;
        break;
      }
      player++;
    }
    player %= 2;
    cout << ans[player] << "\n";
  }
  return 0;
}
