#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> a(n, 0);
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    map<long long int, long long int> mp;
    vector<long long int> ans(n, 0);
    for (auto ele : a) {
      mp[ele]++;
    }
    long long int unique = mp.size();
    long long int maxCount = 0;
    long long int eachColors = 0;
    long long int curIdx = 0;
    eachColors = n / k;
    unordered_map<long long int, long long int> freq;
    vector<long long int> colorFreq(k + 1, 0);
    for (long long int i = 0; i < n; i++) {
      if (freq[a[i]] == k) {
        continue;
      }
      long long int curColor = freq[a[i]] + 1;
      while (curColor <= k && colorFreq[curColor] == eachColors) {
        curColor++;
      }
      if (curColor == k + 1) {
        continue;
      }
      ans[i] = curColor;
      freq[a[i]] = curColor;
      colorFreq[curColor]++;
    }
    for (auto ele : ans) {
      cout << ele << " ";
    }
    cout << "\n";
  }
}
