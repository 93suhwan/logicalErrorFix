#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  long long int a[n], s = 0;
  double sum;
  map<long long int, long long int> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
    s += 2 * a[i];
  }
  sum = (s * 1.0) / n;
  if (floor(sum) - sum != 0) {
    cout << "0\n";
    return;
  }
  long long int count = 0;
  for (int i = 0; i < n; i++) {
    long long int data = sum - a[i];
    m[a[i]]--;
    count += m[data];
  }
  cout << count << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
