#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, sum;
    cin >> n >> sum;
    int medpos = n / 2 + 1;
    cout << sum / medpos << endl;
  }
}
