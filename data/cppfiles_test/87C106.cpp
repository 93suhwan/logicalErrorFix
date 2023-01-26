#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int binpow(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long int res = binpow(a, b / 2);
  if (b % 2 == 0)
    return (res * res) % mod;
  else
    return ((res * res) % mod * a) % mod;
}
long long int inv(long long int a) {
  return (binpow(a, mod - 2) % mod + mod) % mod;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int l = m;
    vector<int> arr;
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      arr.push_back(x);
    }
    vector<int> temp(m);
    for (int i = 0; i < m; i++) temp[i] = arr[i];
    sort(temp.begin(), temp.end());
    map<int, int> mp;
    for (int i = 0; i < l; i++) {
      int c = -1, p;
      for (int j = 0; j < l; j++) {
        if (temp[j] == arr[i] && c < j) {
          if (c == -1) {
            c = j;
            mp[i] = c;
            p = temp[c];
            temp[c] = -1;
          } else {
            temp[c] = p;
            c = j;
            mp[i] = c;
            p = temp[c];
            temp[c] = -1;
          }
        }
      }
    }
    vector<int> temporary(m, -1);
    int result = 0;
    for (auto it : mp) {
      for (int i = 0; i < it.second; i++)
        if (temporary[i] != -1 && temporary[i] != arr[it.first]) result++;
      temporary[it.second] = arr[it.first];
    }
    cout << result << endl;
  }
}
