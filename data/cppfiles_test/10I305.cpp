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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int occurance[n + 1];
    for (int i = 0; i < n + 1; i++) {
      occurance[i] = 0;
    }
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n; i++) {
      if (occurance[arr[i]] == 0) {
        vector<int> temp;
        temp.push_back(i);
        v[arr[i]] = temp;
        occurance[arr[i]] = 1;
      } else {
        v[arr[i]].push_back(i);
      }
    }
    int ans[n];
    int done[n];
    for (int i = 0; i < n; i++) {
      ans[i] = 0;
      done[i] = 0;
    }
    int l = 0;
    for (int i = 1; i < n + 1; i++) {
      int num = v[i].size();
      if (num > 0) {
        if (num > k) {
          int c = 1;
          for (int j = 0; j < num; j++) {
            if (c < k + 1) {
              ans[v[i][j]] = c;
              c++;
              l++;
            } else {
              ans[v[i][j]] = 0;
              l++;
            }
            done[v[i][j]] = 1;
          }
        }
        if (num == k) {
          int c = 1;
          for (int j = 0; j < num; j++) {
            ans[v[i][j]] = c;
            c++;
            l++;
            done[v[i][j]] = 1;
          }
        }
      }
    }
    int rem = n - l;
    int c1 = rem / k;
    while (c1 > 0) {
      int kc = 1;
      for (int i = 0; i < n; i++) {
        if (done[i] == 0 && kc <= k) {
          ans[i] = kc;
          done[i] = 1;
          kc++;
        }
      }
      c1--;
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
}
