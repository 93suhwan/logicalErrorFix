#include <bits/stdc++.h>
using namespace std;
void test_case() {
  string str;
  getline(cin, str);
  int score1 = 0;
  int score2 = 0;
  int ans = 0;
  int c1 = 5;
  int c2 = 5;
  for (int i = 0; i < 10; i++) {
    if (i % 2)
      c2--;
    else
      c1--;
    ans++;
    if (str[i] == '?') {
      if (i % 2) {
        if (score2 >= score1) {
          score2++;
        }
      } else {
        if (score1 >= score2) {
          score1++;
        }
      }
    } else if (str[i] == '1') {
      if (i % 2)
        score2++;
      else
        score1++;
    }
    if (((score1 + c1) < score2) || ((score2 + c2) < score1)) break;
  }
  cout << ans << "\n";
}
int main() {
  int t;
  scanf("%d", &t);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  while (t--) {
    test_case();
  }
}
