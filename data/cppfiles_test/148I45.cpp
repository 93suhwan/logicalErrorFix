#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    vector<int> v1, v2, v3, v4;
    int k1, k2, k3, k4;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
      int c;
      cin >> c;
      v1.push_back(c);
    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
      int c;
      cin >> c;
      v2.push_back(c);
    }
    cin >> k3;
    for (int i = 0; i < k3; i++) {
      int c;
      cin >> c;
      v3.push_back(c);
    }
    cin >> k4;
    for (int i = 0; i < k4; i++) {
      int c;
      cin >> c;
      v4.push_back(c);
    }
    int d1, d2, d3, d4;
    d1 = v1[k1 - 1] - v1[0];
    d2 = v2[k2 - 1] - v2[0];
    d3 = v3[k3 - 1] - v3[0];
    d4 = v4[k4 - 1] - v4[0];
    long long m = max(d1, d2) * h;
    long long n = max(d3, d4) * w;
    cout << max(n, m) << "\n";
  }
  return 0;
}
