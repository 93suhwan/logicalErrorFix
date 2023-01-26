#include <bits/stdc++.h>
using namespace std;
long long int MOD = 998244353, n, k = 0;
void print(long long int arr[], long long int n) {
  for (int i = 0; i <= n - 1; i += 1) cout << arr[i] << " ";
  cout << endl;
}
int main() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    string s, temp1, temp2;
    cin >> s;
    long long int prev, one = 0, two = 0, cnt1 = 0;
    for (int i = 0; i <= n - 1; i += 1) {
      if (s[i] == '?') {
        temp1 = temp2 = s;
        cnt1 = one = two = 0;
        temp1[i] = 'R', temp2[i] = 'B';
        for (int j = i + 1; j <= n - 1; j += 1) {
          if (temp1[j] == '?') {
            if (temp1[j - 1] == 'R')
              temp1[j] = 'B';
            else
              temp1[j] = 'R';
            if (temp2[j - 1] == 'B')
              temp2[j] = 'R';
            else
              temp2[j] = 'B';
          }
          if (j > 0) {
            if (temp1[j] == temp1[j - 1]) one++;
            if (temp2[j] == temp2[j - 1]) two++;
          }
        }
        if (one < two)
          s[i] = 'R';
        else if (one == two) {
          if (i > 0) {
            if (s[i - 1] == 'R')
              s[i] = 'B';
            else
              s[i] = 'R';
          } else
            s[i] = 'R';
        } else
          s[i] = 'B';
      }
    }
    cout << s << endl;
  }
}
