#include <bits/stdc++.h>
using namespace std;
void solver() {
  long long int n;
  cin >> n;
  vector<long long int> a(n, 0);
  for (auto &x : a) {
    cin >> x;
  }
  long long int me1 = *min_element(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    a[i] = a[i] & me1;
  }
  long long int mn = *min_element(a.begin(), a.end());
  long long int val = me1 & mn;
  cout << val << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solver();
  }
  return 0;
}
