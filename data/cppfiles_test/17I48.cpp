#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e, i, j;
  cin >> a;
  while (a--) {
    cin >> b;
    long long arr[b + 10][6];
    long long mx = 1e9;
    for (i = 1; i <= b; i++) {
      vector<long long> vec;
      for (j = 0; j < 5; j++) {
        cin >> arr[i][j];
        vec.push_back(arr[i][j]);
      }
      sort(vec.begin(), vec.end());
      if (mx > vec[2]) {
        mx = vec[2];
      }
    }
    map<long long, long long> mp;
    long long index = -1;
    long long oc = 0;
    for (i = 1; i <= b; i++) {
      long long cnt = 0;
      for (j = 1; j < 5; j++) {
        if (arr[i][j] > mx) {
          cnt++;
        }
      }
      mp[cnt]++;
      if (cnt <= 1) {
        oc = cnt;
        index = i;
      }
    }
    if (mp[oc] == 1)
      cout << index << endl;
    else
      cout << -1 << endl;
  }
}
