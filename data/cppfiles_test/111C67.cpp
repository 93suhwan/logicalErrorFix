#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int n;
    cin >> n;
    vector<char> v;
    for (int j = 0; j < 2 * n; ++j) {
      if (j <= n - 1) {
        v.push_back('(');
      } else {
        v.push_back(')');
      }
    }
    for (auto it = v.begin(); it != v.end(); it++) cout << *it;
    cout << "\n";
    int s = n - 1;
    for (int j = 0; j < n - 1; ++j) {
      char temp = v[s];
      v[s] = v[s + 1];
      v[s + 1] = temp;
      for (auto it = v.begin(); it != v.end(); it++) cout << *it;
      cout << "\n";
      s--;
    }
  }
}
