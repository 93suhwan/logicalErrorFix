#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int aa[N];
long long pp[10];
int main() {
  long long p = 1;
  for (int h = 0; h < 10; h++, p *= 10) pp[h] = p;
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k, k++;
    for (int i = 0; i < n; i++) cin >> aa[i];
    long long x = 0;
    for (int i = 1; i < n; i++) {
      int l = aa[i - 1], r = aa[i];
      if (k >= pp[r - l] - 1) {
        x += r - l;
        k -= pp[r - l] - 1;
      } else
        break;
    }
    if (k > 0) cout << k;
    while (x--) cout << 9;
    cout << '\n';
  }
  return 0;
}
