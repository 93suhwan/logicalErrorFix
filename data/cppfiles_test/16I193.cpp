#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, cnt = 0;
    cin >> n;
    char str[n], str2[n];
    gets(str);
    strcpy(str2, str);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (str2[j] < str2[i]) {
          char temp;
          temp = str2[i];
          str2[i] = str2[j];
          str2[j] = temp;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (str[i] != str2[i]) cnt++;
    }
    cout << cnt << "\n";
  }
  return 0;
}
