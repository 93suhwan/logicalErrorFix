#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    map<int, int> mp;
    map<int, int> mp2;
    for (int i = 0; i < n; ++i) {
      cin >> vec[i];
      mp[vec[i]]++;
    }
    for (int i = 0; i < n; ++i) {
      if (mp2[vec[i]] < k) {
        cout << mp2[vec[i]] + 1 << " ";
        mp2[vec[i]]++;
      } else {
        cout << 0 << " ";
      }
    }
    cout << endl;
  }
}
