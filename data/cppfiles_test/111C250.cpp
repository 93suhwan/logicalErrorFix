#include <bits/stdc++.h>
using namespace std;
vector<int> v[200010];
int can[200010];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; ++j) cout << '(';
      for (int j = i; j >= 0; --j) cout << "()";
      for (int j = i + 1; j < n; ++j) cout << ')';
      cout << "\n";
    }
  }
}
