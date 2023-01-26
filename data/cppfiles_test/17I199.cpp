#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n][5];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) cin >> arr[i][j];
    }
    vector<long long int> count(n);
    vector<vector<int>> brr(5, vector<int>(n));
    for (int j = 0; j < 5; j++) {
      vector<vector<int>> temp(n, vector<int>(2));
      for (int i = 0; i < n; i++) {
        temp[i][0] = arr[i][j];
        temp[i][1] = i;
      }
      sort(temp.begin(), temp.end());
      for (int i = 0; i < n; i++) brr[j][i] = temp[i][1];
    }
    bool temp = true;
    int ans = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        count[brr[j][i]]++;
        if (count[brr[j][i]] == 5) {
          if (ans == -1)
            ans = brr[j][i];
          else {
            temp = false;
            break;
          }
        }
      }
      if (ans != -1) break;
    }
    if (temp)
      cout << ans + 1 << "\n";
    else
      cout << -1 << "\n";
  }
  return 0;
}
