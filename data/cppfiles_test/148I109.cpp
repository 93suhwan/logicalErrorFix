#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int MAX_SIZE = 1000005;
const long long int MAXN = 100000;
int main() {
  long int t;
  cin >> t;
  while (t--) {
    long int w, h, k1, k2, k3, k4;
    cin >> w >> h;
    vector<long int> vx1;
    vector<long int> vx2;
    vector<long int> vy1;
    vector<long int> vy2;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
      long int temp;
      cin >> temp;
      vx1.push_back(temp);
    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
      long int temp;
      cin >> temp;
      vx2.push_back(temp);
    }
    cin >> k3;
    for (int i = 0; i < k3; i++) {
      long int temp;
      cin >> temp;
      vy1.push_back(temp);
    }
    cin >> k4;
    for (int i = 0; i < k4; i++) {
      long int temp;
      cin >> temp;
      vy2.push_back(temp);
    }
    long int basex =
        max((vx1[vx1.size() - 1] - vx1[0]), (vx2[vx2.size() - 1] - vx2[0]));
    unsigned long long int ans1 = basex * h;
    long int basey =
        max((vy1[vy1.size() - 1] - vy1[0]), (vy2[vy2.size() - 1] - vy2[0]));
    unsigned long long int ans2 = basey * w;
    unsigned long long int final_ans = max(ans1, ans2);
    cout << final_ans << endl;
  }
  return 0;
}
