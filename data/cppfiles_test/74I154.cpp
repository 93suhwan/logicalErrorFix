#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    if ((a + b) % 2 == 0) {
      long long int sum = a + b;
      long long int each = sum / 2;
      long long int hage = abs(each - a);
      vector<int> ans;
      ans.push_back(hage);
      long long int left = each - hage;
      for (int i = 0; i < left; i++) ans.push_back(ans.back() + 2);
      cout << ans.size() << endl;
      for (auto i : ans) cout << i << " ";
      cout << endl;
    } else {
      long long int sum = a + b;
      long long int small = sum / 2;
      long long int big = small + 1;
      long long int hga = abs(big - a);
      vector<int> ans;
      ans.push_back(hga);
      long long int left = small - hga;
      for (int i = 0; i < left; i++) ans.push_back(ans.back() + 2);
      hga = abs(big - b);
      ans.push_back(hga);
      left = small - hga;
      for (int i = 0; i < left; i++) {
        hga += 2;
        ans.push_back(hga);
      }
      sort(ans.begin(), ans.end());
      if (big == a || big == b) ans.push_back(a + b);
      cout << ans.size() << endl;
      for (auto i : ans) cout << i << " ";
      cout << endl;
    }
  }
}
