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
      vector<int> ans;
      long long int mn = min(a, b);
      long long int hga = big - mn;
      ans.push_back(hga);
      long long int left = big - hga;
      for (int i = 0; i < left; i++) ans.push_back(ans.back() + 2);
      hga = small - mn;
      ans.push_back(hga);
      left = small - hga;
      for (int i = 0; i < left; i++) {
        hga += 2;
        ans.push_back(hga);
      }
      sort(ans.begin(), ans.end());
      cout << ans.size() << endl;
      for (auto i : ans) cout << i << " ";
      cout << endl;
    }
  }
}
