#include <bits/stdc++.h>
using namespace std;
void file_IO() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  file_IO();
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    long long ct = 0;
    if (n == 1) {
      if (s1[0] == '0' && s2[0] == '1')
        cout << "1"
             << "\n";
      else
        cout << "0"
             << "\n";
      continue;
    }
    for (long long i = 0; 0 < n ? i < n : i > n; 0 < n ? i += 1 : i -= 1) {
      if (s1[i] == '0' && s2[i] == '1') {
        ct++;
        s2[i] = '0';
        s1[i] = '2';
      }
    }
    if (s1[0] == '1' and s2[1] == '1') {
      ct++;
      s1[0] = '2';
      s2[1] = '0';
    }
    for (long long i = 1; 1 < n - 1 ? i < n - 1 : i > n - 1;
         1 < n - 1 ? i += 1 : i -= 1) {
      if (s1[i] != '0') {
        if (s2[i - 1] == '1') {
          ct++;
          s2[i - 1] = '0';
          s1[i] = '2';
        } else if (s2[i + 1] == '1') {
          ct++;
          s2[i + 1] = '0';
          s1[i] = '2';
        }
      }
    }
    if (s1[n - 1] == '1' and s2[n - 2] == '1') {
      ct++;
      s1[n - 1] = '2';
      s2[n - 2] = '0';
    }
    cout << ct << "\n";
  }
  return 0;
}
