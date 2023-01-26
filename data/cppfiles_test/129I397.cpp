#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long count = 0;
    int fl = 0;
    for (long long i = 0; i < n; i++) {
      if (a[i] != (i + 1)) {
        long long half = a[i] / 2;
        long long next = half + 1;
        long long rem = max((a[i] % half), (a[i] % next));
        if (rem >= (i + 1))
          count++;
        else {
          fl = 1;
          break;
        }
      }
    }
    if (fl == 1)
      cout << "-1\n";
    else
      cout << count << "\n";
  }
  return 0;
}
