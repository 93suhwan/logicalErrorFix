#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string sa;
    cin >> sa;
    int n = sa.length();
    vector<int> s(n);
    for (int i = 0; i < n; i++) s[i] = (int)sa[i];
    sort(s.begin(), s.end());
    vector<int> freq;
    int j;
    for (int i = 0; i < n; i = i + j) {
      j = upper_bound(s.begin(), s.end(), s[i]) -
          lower_bound(s.begin(), s.end(), s[i]);
      freq.push_back(j);
    }
    int sum = 0;
    int q = 0;
    for (int i = 0; i < freq.size(); i++) {
      if (freq[i] >= 2)
        sum += 1;
      else {
        q++;
      }
    }
    cout << sum + (q / 2) << '\n';
  }
  return 0;
}
