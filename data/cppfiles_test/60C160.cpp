#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int arr[n];
  long long summ = 0;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    summ += arr[i];
  }
  summ *= 2;
  if (summ % n != 0) {
    cout << 0 << endl;
    return;
  }
  summ /= n;
  long long ct = 0;
  for (int i = 0; i < n; i++) {
    int x = summ - arr[i];
    ct += m[x];
    m[arr[i]]++;
  }
  cout << ct << endl;
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
