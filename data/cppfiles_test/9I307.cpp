#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int count1 = 0;
    int count2 = 0;
    int freq[256] = {0};
    sort(s.begin(), s.end());
    int uc = unique(s.begin(), s.end()) - s.begin();
    int c = s.size();
    for (int i = 0; s[i] != '\0'; i++) {
      freq[s[i]]++;
    }
    for (int i = 0; i < 60; i++) {
      if (freq[s[i]] == 1) {
        count1 += 1;
      }
    }
    int m = uc - count1;
    if (count1 % 2 != 0) count1 = (count1 - 1);
    cout << (m + (count1 / 2)) << "\n";
  }
  return 0;
}
