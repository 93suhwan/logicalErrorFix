#include <bits/stdc++.h>
using namespace std;
inline void debug(vector<long long>& arr) {
  cout << "arr: [";
  for (auto it : arr) {
    cout << it << ",";
  }
  cout << "]";
  cout << '\n';
}
inline void debug(long long x) { cout << x << '\n'; }
inline void debug(long long arr[], long long n) {
  cout << "arr: [";
  for (long long i = 0; i < n; i++) {
    cout << arr[i] << ",";
  }
  cout << "]";
  cout << '\n';
}
const long long N = 1e5 + 5;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    long long n = str.length();
    if (str.length() % 2 == 1) {
      cout << "NO" << '\n';
    } else {
      string s, s1;
      long long i = 0;
      for (i; i < n / 2; i++) {
        s.push_back(str[i]);
      }
      for (i; i < n; i++) {
        s1.push_back(str[i]);
      }
      if (s == s1) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    }
  }
  return 0;
}
