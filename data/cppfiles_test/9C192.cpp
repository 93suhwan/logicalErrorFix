#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, long long int> freq;
    long long int n = s.size();
    for (long long int i = 0; i < n; i++) {
      freq[s[i]]++;
    }
    long long int count = 0;
    long long int flag = 0;
    long long int sum = 0;
    long long int x;
    for (auto x : freq) {
      if (x.second > 1 && x.second < n) {
        count++;
        sum += x.second;
        flag = -1;
      } else if (x.second == n && n != 1)
        flag = 1;
    }
    long long int rem = n - sum;
    if (flag == 0)
      cout << n / 2 << endl;
    else if (flag == -1)
      cout << count + rem / 2 << endl;
    else if (flag == 1)
      cout << 1 << endl;
    else if (n == 1) {
      cout << 0 << endl;
    }
  }
  return 0;
}
