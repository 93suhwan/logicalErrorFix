#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, a[N];
long long res;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i += 2) {
    long long sum = a[i - 1] - a[i];
    res += min(a[i - 1], a[i]);
    if (sum < 0) continue;
    for (int j = i + 2; j < n; j += 2) {
      if (a[j - 1] <= a[j]) res++;
      long long k = min(a[j - 1], a[j]);
      sum += a[j - 1] - k;
      if (sum < a[j] - k) {
        res += sum;
        break;
      }
      res += a[j] - k;
      sum -= a[j] - k;
    }
  }
  cout << res << endl;
  return 0;
}
