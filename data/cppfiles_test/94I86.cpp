#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int aa[N];
long long pp[19];
int length(int n) { return n == 0 ? 0 : length(n / 10) + 1; }
long long reverse(long long a, long long b) {
  return a == 0 ? b : reverse(a / 10, b * 10 + a % 10);
}
long long reverse(long long n) { return reverse(n, 0); }
int main() {
  long long p = 1;
  for (int h = 0; h <= 18; h++, p *= 10) pp[h] = p;
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k, k++;
    for (int i = 0; i < n; i++) cin >> aa[i];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int l = aa[i], r = i + 1 < n ? aa[i + 1] : l + 18;
      if (k <= pp[r - l] - 1) {
        ans = ans * pp[length(k)] + reverse(k);
        break;
      } else {
        ans = ans * pp[r - l] + pp[r - l] - 1;
        k -= pp[r - l] - 1;
      }
    }
    cout << reverse(ans) << '\n';
  }
  return 0;
}
