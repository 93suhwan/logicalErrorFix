#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++) cout << (i + 1) * 5 << " ";
    cout << endl;
  }
}
