#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    float n, s;
    int dis;
    cin >> n >> s;
    dis = s / (n - ceil(n / 2) + 1);
    cout << dis << endl;
  }
  return 0;
}
