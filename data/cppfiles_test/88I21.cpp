#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    for (long long i = 0; i < n - 1; i++)
      if (a[i + 1] < a[i]) {
        ans++;
        break;
      }
    if (n % 2 == 0)
      cout << "YES" << endl;
    else if (ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
