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
    long long cntr = 0, a = 0, b = 0;
    map<long long, long long> ar;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      cntr += arr[i];
    }
    cntr = cntr * 2;
    cntr = cntr / n;
    for (int i = 0; i < n; i++) {
      long long c = arr[i];
      b = cntr - c;
      a = a + ar[b];
      ar[c] += 1;
    }
    cout << a << endl;
  }
  return 0;
}
