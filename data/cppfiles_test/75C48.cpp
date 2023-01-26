#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, a[N];
vector<int> q1, q2;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  q1.push_back(a[0]);
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      q1.push_back(a[i]);
    } else {
      break;
    }
  }
  q2.push_back(a[n - 1]);
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > a[i + 1]) {
      q2.push_back(a[i]);
    } else {
      break;
    }
  }
  int i = 0, j = 0, s1 = q1.size(), s2 = q2.size(), winner = 1;
  while (i < s1 && j < s2) {
    if (a[i] == a[j]) {
      if (((s1 - i) & 1) || ((s2 - j) & 1)) winner = 1 - winner;
      i = s1;
      j = s2;
    } else {
      if (a[i] > a[j]) {
        if ((s1 - i) & 1) {
          i = s1;
          j = s2;
        } else {
          j++;
        }
      } else {
        if ((s2 - j) & 1) {
          i = s1;
          j = s2;
        } else {
          i++;
        }
      }
      winner = 1 - winner;
    }
  }
  winner = winner ^ ((s1 - i + s2 - j) & 1);
  printf(winner ? "Bob" : "Alice");
}
