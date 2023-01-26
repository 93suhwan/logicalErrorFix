#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int cn = 1;
  vector<long long int> v;
  while (v.size() != 1000) {
    if ((cn % 3 == 0) || ((cn % 10) == 3))
      cn++;
    else {
      v.push_back(cn);
      cn++;
    }
  }
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << v[n - 1] << "\n";
  }
  return 0;
}
