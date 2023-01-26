#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int freq[26] = {0};
    int n = s.length();
    for (int i = 0; i < n; i++) freq[s[i] - 'a']++;
    sort(freq, freq + 26);
    cout << freq[26 - 1] << endl << " ";
    if (n % 2 == 0) {
      if (freq[25] <= 2)
        cout << n / 2 << endl;
      else {
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
          if (freq[i] <= 2)
            cnt += freq[i];
          else
            cnt += 2;
        }
        if (cnt % 2 != 0)
          cout << (cnt - 1) / 2 << endl;
        else
          cout << cnt / 2 << endl;
      }
    } else {
      if (freq[25] <= 2)
        cout << (n - 1) / 2 << endl;
      else {
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
          if (freq[i] <= 2)
            cnt += freq[i];
          else
            cnt += 2;
        }
        if (cnt % 2 != 0)
          cout << (cnt - 1) / 2 << endl;
        else
          cout << cnt / 2 << endl;
      }
    }
  }
}
