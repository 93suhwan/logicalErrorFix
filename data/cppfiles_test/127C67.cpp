#include <bits/stdc++.h>
using namespace std;
int T, aa[105];
string a, b;
int main() {
  cin >> T;
  while (T--) {
    int cnt[28], s = 1;
    cin >> a >> b;
    for (int i = 1; i <= 26; i++) cnt[i] = 0;
    for (int i = 0; i < a.length(); i++) aa[i] = a[i] - 'a' + 1, cnt[aa[i]]++;
    sort(aa, aa + a.length());
    if (b[0] == 'a' && b[1] == 'b' && b[2] == 'c' && cnt[1] != 0 &&
        cnt[2] != 0 && cnt[3] != 0) {
      for (s = 1; s <= cnt[1] + cnt[2] + cnt[3]; s++) {
        if (s <= cnt[1])
          cout << "a";
        else if (s >= cnt[1] + 1 && s <= cnt[1] + cnt[3])
          cout << "c";
        else
          cout << "b";
      }
    }
    for (int i = s - 1; i < a.length(); i++) cout << (char)('a' + aa[i] - 1);
    cout << '\n';
  }
  return 0;
}
