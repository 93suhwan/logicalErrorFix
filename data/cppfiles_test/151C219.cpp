#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q, siz = 500001;
  cin >> q;
  int arr[q], brr[q], crr[q];
  for (int i = 0; i < q; i++) {
    cin >> arr[i] >> brr[i];
    if (arr[i] == 2) {
      cin >> crr[i];
    }
  }
  int prr[siz];
  iota(prr, prr + siz, 0);
  vector<int> ans;
  for (int i = q - 1; i >= 0; i--) {
    if (arr[i] == 1) {
      ans.push_back(prr[brr[i]]);
    } else {
      prr[brr[i]] = prr[crr[i]];
    }
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
