#include <bits/stdc++.h>
using namespace std;
void fun() {
  long long n;
  cin >> n;
  string second;
  cin >> second;
  long long i = 0;
  while (i < n && second[i] == '?') i++;
  if (i == n) {
    for (long long j = 0; j < n; j++) {
      if (j % 2 == 0)
        second[j] = 'B';
      else
        second[j] = 'R';
    }
  } else {
    i--;
    while (i >= 0) {
      if (second[i + 1] == 'B')
        second[i] = 'R';
      else
        second[i] = 'B';
      i--;
    }
    for (long long i = 1; i < n; i++) {
      if (second[i] == '?') {
        if (second[i - 1] == 'B')
          second[i] = 'R';
        else
          second[i] = 'B';
      }
    }
  }
  cout << second << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    fun();
  }
}
