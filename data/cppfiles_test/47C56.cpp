#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> arr(n);
  long long x, y, z, sum;
  long long xa, xo, ya, yo, za, zo;
  cout << "and 1 2" << endl;
  cin >> xa;
  cout << "or 1 2" << endl;
  cin >> xo;
  x = xo + xa;
  cout << "and 2 3" << endl;
  cin >> ya;
  cout << "or 2 3" << endl;
  cin >> yo;
  y = yo + ya;
  cout << "and 1 3" << endl;
  cin >> za;
  cout << "or 1 3" << endl;
  cin >> zo;
  z = zo + za;
  arr[0] = (x + y + z) / 2 - y;
  arr[1] = (x + y + z) / 2 - z;
  arr[2] = (x + y + z) / 2 - x;
  for (int i = 3; i < n; ++i) {
    long long x, y;
    cout << "and " << i << " " << i + 1 << endl;
    cin >> x;
    cout << "or " << i << " " << i + 1 << endl;
    cin >> y;
    arr[i] = x + y - arr[i - 1];
  }
  sort(arr.begin(), arr.end());
  cout << "finish " << arr[k - 1] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
