#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long _;
  cin >> _;
  while (_--) {
    long long n;
    cin >> n;
    long long arr[n];
    long long total = 0, x = 0, y = 0;
    map<long long, long long> ar;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      total += arr[i];
    }
    total = total * 2;
    if (total % n != 0)
      cout << 0 << endl;
    else {
      total /= n;
      for (int i = 0; i < n; i++) {
        long long k = arr[i];
        y = total - k;
        x += ar[y];
        ar[k]++;
      }
      cout << x << endl;
    }
  }
  return 0;
}
