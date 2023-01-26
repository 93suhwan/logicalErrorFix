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
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum = sum + a[i];
    }
    long long avg = sum / n;
    long long res = avg * n;
    if (res == sum)
      cout << "0\n";
    else
      cout << "1\n";
  }
  return 0;
}
