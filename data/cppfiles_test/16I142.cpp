#include <bits/stdc++.h>
using namespace std;
long long t, n;
char s[45];
char d[100];
int count(string s) {
  int i, j, k;
  i = j = 0;
  while (s[i] != '\0') {
    j++;
    k = s[i];
    while (s[i] == k) i++;
  }
  return j;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> s;
    cout << count(s) << endl;
  }
}
