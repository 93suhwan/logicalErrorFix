#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long w, h;
    cin >> w >> h;
    long long k;
    cin >> k;
    int h1min = INT_MAX, h1max = 0;
    while (k--) {
      int temp;
      cin >> temp;
      h1min = min(h1min, temp);
      h1max = max(h1max, temp);
    }
    cin >> k;
    int h2min = INT_MAX, h2max = 0;
    while (k--) {
      int temp;
      cin >> temp;
      h2min = min(h2min, temp);
      h2max = max(h2max, temp);
    }
    cin >> k;
    int v1min = INT_MAX, v1max = 0;
    while (k--) {
      int temp;
      cin >> temp;
      v1min = min(v1min, temp);
      v1max = max(v1max, temp);
    }
    cin >> k;
    int v2min = INT_MAX, v2max = 0;
    while (k--) {
      int temp;
      cin >> temp;
      v2min = min(v2min, temp);
      v2max = max(v2max, temp);
    }
    long long a = (h1max - h1min) * h;
    long long ans = a;
    long long b = (h2max - h2min) * h;
    if (b > ans) ans = b;
    long long c = (v1max - v1min) * w;
    if (c > ans) ans = c;
    long long d = (v2max - v2min) * w;
    if (d > ans) ans = d;
    cout << ans << endl;
  }
  return 0;
}
