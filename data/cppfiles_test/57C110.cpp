#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void printn(vector<int> nums) {
  for (int a : nums) {
    cout << a << " ";
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  for (int test = 0; test < t; test++) {
    cin >> n;
    vector<int> nums(n);
    bool Pos = true;
    for (int a = 0; a < n; a++) {
      cin >> nums[a];
      if ((nums[a] + 1 - a) % 2 != 0) {
        Pos = false;
      }
    }
    if (!Pos) {
      cout << -1 << '\n';
      continue;
    }
    int pindex;
    int oindex;
    int act = n;
    cout << 5 * (n - 1) / 2 << '\n';
    while (act > 1) {
      for (int a = 0; a < n; a++) {
        if (nums[a] == act) {
          oindex = a;
        }
        if (nums[a] == act - 1) {
          pindex = a;
        }
      }
      cout << oindex + 1 << " ";
      reverse(nums.begin(), nums.begin() + oindex + 1);
      if (oindex > pindex) {
        pindex = oindex - pindex;
      }
      oindex = 0;
      cout << pindex << " ";
      reverse(nums.begin(), nums.begin() + pindex);
      cout << pindex + 2 << " ";
      reverse(nums.begin(), nums.begin() + pindex + 2);
      cout << 3 << " ";
      reverse(nums.begin(), nums.begin() + 3);
      cout << act << " ";
      reverse(nums.begin(), nums.begin() + act);
      act -= 2;
    }
    cout << '\n';
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
