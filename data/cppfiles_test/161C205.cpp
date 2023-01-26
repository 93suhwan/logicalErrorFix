#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
bool Compare(const vector<long long int> arr, const vector<long long int> brr) {
  if (arr[0] == arr[0]) return arr[1] < brr[1];
  return arr[0] < brr[0];
}
int main() {
  init_code();
  long long int d, t, i, j, k, n, k1, k2, y, k3, w, h, A, B, a, b, x, c, z, p,
      e, f;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<vector<bool> > mark(n + 1, vector<bool>(n + 1));
    vector<long long int> l(n), r(n);
    for (i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
      mark[l[i]][r[i]] = true;
    }
    for (i = 0; i < n; i++) {
      for (d = l[i]; d <= r[i]; d++) {
        if ((d == l[i] || mark[l[i]][d - 1]) &&
            (d == r[i] || mark[d + 1][r[i]])) {
          cout << l[i] << " " << r[i] << " " << d << "\n";
          break;
        }
      }
    }
    cout << "\n";
  }
  return 0;
}
