#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, s;
    cin >> n >> s;
    int mid = (n + 1) / 2;
    int ele = n - mid + 1;
    cout << s / ele << "\n";
  }
  return 0;
}
