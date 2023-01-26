#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
void solution() {
  string second;
  cin >> second;
  int li = 0;
  int BA = 0, AB = 0;
  for (int i = 1; i < second.length(); i++) {
    if (second[i] == 'a') {
      if (second[i - 1] == 'b') {
        BA++;
        li = i;
      }
    }
    if (second[i] == 'b') {
      if (second[i - 1] == 'a') {
        AB++;
        li = i;
      }
    }
  }
  if (AB > BA) {
    if (second.length() >= 2) {
      if (second[0] == 'a' && second[1] == 'b') {
        second[0] = 'b';
      }
      if (second[0] == 'a' && second[1] == 'a') {
        second[0] = 'b';
      }
    }
  }
  if (BA > AB) {
    if (second.length() >= 2) {
      if (second[0] == 'b' && second[1] == 'b') {
        second[0] = 'a';
      }
      if (second[0] == 'b' && second[1] == 'a') {
        second[0] = 'a';
      }
    }
  }
  cout << second << endl;
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solution();
  }
  return 0;
}
