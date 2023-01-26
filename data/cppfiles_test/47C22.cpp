#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e4;
int n, k;
long long a[mxn];
long long x[3][3], y[3][3];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < 2; i++) {
    for (int j = i + 1; j < 3; j++) {
      cout << "and " << i + 1 << " " << j + 1 << "\n";
      cout << flush;
      cin >> x[i][j];
      cout << "or " << i + 1 << " " << j + 1 << "\n";
      cout << flush;
      cin >> y[i][j];
    }
  }
  a[0] =
      ((x[0][1] + y[0][1]) + (x[0][2] + y[0][2]) - (x[1][2] + y[1][2])) / 2ll;
  a[1] = (x[0][1] + y[0][1]) - a[0];
  a[2] = (x[0][2] + y[0][2]) - a[0];
  for (int i = 3; i < n; i++) {
    long long p, q;
    cout << "and 1 " << i + 1 << "\n";
    cout << flush;
    cin >> p;
    cout << "or 1 " << i + 1 << "\n";
    cout << flush;
    cin >> q;
    a[i] = p + q - a[0];
  }
  sort(a, a + n);
  cout << "finish " << a[k - 1] << "\n";
  cout << flush;
  return 0;
}
