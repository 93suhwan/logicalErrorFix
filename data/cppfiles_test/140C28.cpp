#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long num;
  for (int i = 1; i <= n; i++) {
    cin >> num;
    map<int, int> mp;
    long long coun = 1, sq, cub;
    for (int j = 2; j <= sqrt(num); j++) {
      sq = pow(j, 2);
      cub = pow(j, 3);
      if (sq <= num) mp[sq];
      if (cub <= num) mp[cub];
    }
    cout << mp.size() + 1 << endl;
  }
  return 0;
}
