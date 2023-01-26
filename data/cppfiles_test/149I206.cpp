#include <bits/stdc++.h>
using namespace std;
long long t, n, k, x, num[2005], j, total, tot;
string s;
int find_more_stars() {
  int returns = 0, yes = 0;
  for (int i = n; i >= 0;) {
    while (s[i--] == '*') {
      yes = 1;
    }
    returns += yes;
    yes = 0;
  }
  return returns - tot - 1;
}
void find_num_and_print() {
  int more = find_more_stars(), i = 0, yes = 0;
  while (more > 0) {
    while (s[i++] == '*') {
      yes = 1;
    }
    if (s[i - 1] == 'a') cout << 'a' << "";
    more -= yes;
    yes = 0;
  }
  while (i < n) {
    if (s[i] == 'a')
      cout << 'a';
    else {
      if (yes)
        total /= num[--tot] * k + 1;
      else
        yes = 1;
      for (int j = 1; j <= (x - 1) / total; j++) cout << 'b';
      x -= ((x - 1) / total) * total;
      while (s[i + 1] == '*' && i < n) i++;
    }
    i++;
  }
}
int main() {
  cin >> t;
  while (t--) {
    s = "";
    j = 0, total = 1, tot = 0;
    cin >> n >> k >> x >> s;
    for (int i = n - 1; i >= 0;) {
      while (s[i--] == '*') {
        j++;
      }
      if (x / total <= j * k + 1) {
        find_num_and_print();
        break;
      }
      if (j != 0) num[tot++] = j;
      total *= j * k + 1;
      j = 0;
    }
    cout << endl;
  }
  return 0;
}
