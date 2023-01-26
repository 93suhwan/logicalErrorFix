#include <bits/stdc++.h>
using namespace std;
int m = 1e9 + 7;
int p = 31;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    int k1, k2, k3, k4;
    cin >> k1;
    vector<int> points_h1;
    for (int i = 0; i < k1; i++) {
      int x;
      cin >> x;
      points_h1.push_back(x);
    }
    cin >> k2;
    vector<int> points_h2;
    for (int i = 0; i < k2; i++) {
      int x;
      cin >> x;
      points_h2.push_back(x);
    }
    cin >> k3;
    vector<int> points_v1;
    for (int i = 0; i < k3; i++) {
      int x;
      cin >> x;
      points_v1.push_back(x);
    }
    cin >> k4;
    vector<int> points_v2;
    for (int i = 0; i < k4; i++) {
      int x;
      cin >> x;
      points_v2.push_back(x);
    }
    long long ans = max({w * (points_v1[points_v1.size() - 1] - points_v1[0]),
                         w * (points_v2[points_v2.size() - 1] - points_v2[0]),
                         h * (points_h1[points_h1.size() - 1] - points_h1[0]),
                         h * (points_h2[points_h2.size() - 1] - points_h2[0])});
    cout << ans << endl;
  }
  return 0;
}
