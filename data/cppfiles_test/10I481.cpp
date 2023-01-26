#include <bits/stdc++.h>
const long long int mx = 1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    vector<int> v1, v2;
    int A[n + 2];
    for (int i = 0; i < n; i++) {
      cin >> A[i];
      mp[A[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
      if (mp[A[i]] == k) {
        cout << k << ' ';
        mp[A[i]] = 0;
      } else
        cout << mp[A[i]] << ' ';
      if (mp[A[i]] != 0) mp[A[i]]++;
    }
    cout << endl;
  }
  return 0;
}
