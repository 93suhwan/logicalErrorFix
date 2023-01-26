#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  long long int q, n, sum = 0;
  cin >> q;
  for (int k = 1; k <= q; k++) {
    long long minn = -1e18;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    int ok = 0;
    for (int i = 0; i < v.size(); i++) {
      minn = max(minn, v[i] + sum);
      sum += (v[i] + sum) * -1;
    }
    if (!ok) {
      cout << minn << "\n";
    }
    v.clear();
    sum = 0;
  }
  return 0;
}
