#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int result = 0, length, i, j, n;
  string str_old, str_new;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> length;
    cin >> str_new;
    str_old = str_new;
    sort(str_new.begin(), str_new.end());
    for (j = 0; j < length; j++) {
      if (str_old[j] != str_new[j]) {
        result++;
      }
    }
    cout << result << endl;
    result = 0;
  }
  return 0;
}
