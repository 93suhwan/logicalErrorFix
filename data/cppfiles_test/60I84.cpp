#include <bits/stdc++.h>
using namespace std;
void solver() {
  long long int n;
  cin >> n;
  vector<long long int> a(n, 0);
  for (auto &x : a) {
    cin >> x;
  }
  for (int i = 0; i < n - 1; i++) {
    a[i] = a[i] & a[i + 1];
  }
  cout << *min_element(a.begin(), a.begin()) << "\n";
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
