#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  bool flag = true;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) {
      flag = false;
      break;
    }
  return flag;
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  int sum = 0;
  for (int &ele : v) {
    cin >> ele;
    sum += ele;
  }
  if (!isPrime(sum)) {
    cout << n << "\n";
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << "\n";
  } else {
    int ind;
    for (int i = 0; i < n; i++) {
      if (v[i] & 1) {
        ind = i;
        break;
      }
    }
    cout << n - 1 << "\n";
    for (int i = 0; i < n; i++) {
      if (i != ind) cout << i + 1 << " ";
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
