#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long int temp, extra = 0;
    vector<pair<long long int, int>> arr;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      arr.push_back({temp, i});
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++) {
      if (arr[i].second + 1 == arr[i + 1].second) extra++;
    }
    if (k + extra >= n)
      cout << "YES";
    else
      cout << "NO";
    cout << "\n";
  }
  return 0;
}
