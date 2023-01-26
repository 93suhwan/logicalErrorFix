#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> vec1(n);
    int ct0 = 0, ct1 = 0;
    for (int i = 0; i < n; i++) {
      cin >> vec1[i];
      if (vec1[i] == 0) ct0++;
      if (vec1[i] == 1) ct1++;
    }
    long long ans = 1 << ct0;
    cout << ans * ct1 << endl;
  }
  return 0;
}
