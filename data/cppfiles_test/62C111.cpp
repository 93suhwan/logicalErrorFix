#include <bits/stdc++.h>
using namespace std;
int t;
vector<int> vec;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vec.clear();
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      vec.push_back(k);
    }
    bool check = false;
    for (int i = n - 1; 0 <= i; i -= 1) {
      if (vec[i] == 0) {
        i++;
        for (int j = 1; j <= i; j++) {
          cout << j << " ";
        }
        cout << n + 1 << " ";
        for (int j = i + 1; j <= n; j++) cout << j << " ";
        cout << '\n';
        check = true;
        break;
      }
    }
    if (!check) {
      cout << n + 1 << " ";
      for (int i = 1; i <= n; i++) cout << i << " ";
      cout << '\n';
    }
  }
  return 0;
}
