#include <bits/stdc++.h>
using namespace std;
bool prime[7532];
void SieveOfEratosthenes(int n) {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
int findSubSequence(string s, int num, int &len) {
  int res = 0;
  int i = 0;
  while (num) {
    if (num & 1) res += s[i] - '0';
    i++;
    len++;
    num = num >> 1;
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a[10] = {0};
    int p = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] != '2' and s[i] != '3' and s[i] != '5' and s[i] != '7') {
        cout << "1\n" << s[i] << endl;
        p = 1;
        break;
      }
    }
    if (p == -1) {
      for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
          if (i != j) {
            int f = (s[i] - '0') * 10 + (s[j] - '0');
            if (f != 23 and f != 73 and f != 37 and f != 53 and f != 57) {
              cout << 2 << endl << f << endl;
              i = n;
              break;
            }
          }
        }
    }
  }
}
