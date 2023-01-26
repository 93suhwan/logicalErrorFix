#include <bits/stdc++.h>
using namespace std;
map<char, int> seq1;
map<char, int> qwerty;
int main() {
  string x1 = "abcdefghijklmnopqrstuvwxyz";
  string x2 = "qwertyuiopasdfghjklzxcvbnm";
  for (int i = 0; x1[i] != '\0'; ++i) {
    seq1[x1[i]] = i + 1;
  }
  for (int i = 0; x2[i] != '\0'; ++i) {
    qwerty[x2[i]] = i + 1;
  }
  int t;
  cin >> t;
  string s, a;
  int prev;
  int Count;
  Count = 0;
  for (int i = 0; i < t; ++i) {
    cin >> a;
    cin >> s;
    Count = 0;
    if (a[0] == 'a') {
      prev = seq1[s[i]];
      for (int i = 1; s[i] != '\0'; ++i) {
        Count += abs(seq1[s[i]] - prev);
        prev = seq1[s[i]];
      }
    }
    if (a[0] == 'q') {
      prev = qwerty[s[i]];
      for (int i = 1; s[i] != '\0'; ++i) {
        Count += abs(qwerty[s[i]] - prev);
        prev = qwerty[s[i]];
      }
    }
    cout << Count << "\n";
  }
}
