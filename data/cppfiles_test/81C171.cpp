#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, q;
    cin >> n >> q;
    long long arr[n];
    char x;
    for (long long i = 0; i < n; i++) {
      cin >> x;
      if (x == '+')
        arr[i] = 1;
      else
        arr[i] = -1;
      if (i & 1) arr[i] = -arr[i];
      if (i) arr[i] += arr[i - 1];
    }
    long long a, b;
    for (long long i = 0; i < q; i++) {
      cin >> a >> b;
      long long ans;
      a--;
      if (a)
        ans = abs(arr[b - 1] - arr[a - 1]);
      else
        ans = abs(arr[b - 1]);
      if (ans == 0) {
        cout << 0 << "\n";
        continue;
      }
      if (ans & 1) {
        cout << 1 << "\n";
        continue;
      }
      cout << 2 << "\n";
    }
  }
  return 0;
}
