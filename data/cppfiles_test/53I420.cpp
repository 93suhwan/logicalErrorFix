#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int i, n, k, count1 = 0;
    map<int, int> mp;
    cin >> n >> k;
    vector<int> ara(n + 1), sorted(n);
    for (int i = 0; i < n; i++) {
      cin >> ara[i];
      sorted[i] = ara[i];
    }
    ara.push_back(100000007);
    sorted.push_back(100000007);
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n + 1; i++) {
      mp[sorted[i]] = sorted[i + 1];
    }
    for (int i = 0; i < n; i++) {
      if (mp[ara[i]] != ara[i + 1]) count1++;
    }
    if (count1 <= k)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
