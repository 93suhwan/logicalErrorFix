#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  int index = 0;
  string QAQ;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'Q') {
      index = i;
      break;
    }
  }
  int j = 0;
  int i = index;
  while (s[i] != '\0') {
    if (s[i] == 'Q' || s[i] == 'A') {
      QAQ[j] = s[i];
      j++;
    }
    i++;
  }
  QAQ[j] = '\0';
  for (int i = 0; QAQ[i] != '\0'; ++i) {
    cout << QAQ[i] << endl;
  }
}
