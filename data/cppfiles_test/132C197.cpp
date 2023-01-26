#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int i, j, k, l, m, n, a, b, c, d, e, ans = 0, res, res1 = 0,
                                                   c1 = 0, c2 = 0, maxi;
    vector<long long int> v, v1, v2;
    set<long long int> st, st1;
    set<string> st2;
    map<long long int, long long int> mp, mp1;
    vector<pair<long long int, long long int>> vp1;
    string s, s1, s2, s3, s4, s5;
    long long int arr1[7];
    for (i = 0; i < 7; i++) cin >> arr1[i];
    sort(arr1, arr1 + 7);
    cout << arr1[0] << " " << arr1[1] << " " << arr1[6] - (arr1[0] + arr1[1])
         << endl;
  }
}
