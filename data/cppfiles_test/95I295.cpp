#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int x = n - k + 1;
    for (int i = 1; i < k; i++) cout << "1 ";
    cout << x << endl;
  }
}
