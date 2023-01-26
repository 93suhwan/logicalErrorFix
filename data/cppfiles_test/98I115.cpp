#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
char s1[maxn];
char s2[maxn];
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> s1 + 1;
    cin >> s2 + 1;
    int len1 = strlen(s1 + 1);
    int len2 = strlen(s2 + 1);
    int sum = 0;
    int pos1, pos2;
    for (int i = 1; i <= len2; i++) {
      for (int j = 1; j <= len1; j++) {
        if (s2[i] == s1[j]) {
          pos1 = j;
        }
        if (s2[i + 1] == s1[j]) {
          pos2 = j;
        }
      }
      sum += abs(pos2 - pos1);
    }
    cout << sum << endl;
  }
  return 0;
}
