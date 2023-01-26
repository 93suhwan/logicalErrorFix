#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    string num;
    cin >> num;
    bool prime[100];
    bool flag = false;
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int i = 2; i <= 10; i++) {
      if (!prime[i])
        continue;
      else {
        for (int j = i * i; j < 100; j += i) prime[j] = false;
      }
    }
    for (int i = 0; i < k; i++)
      if (num[i] == '1' || num[i] == '4' || num[i] == '6' || num[i] == '8' ||
          num[i] == '9') {
        cout << '1' << '\n' << num[i] << '\n';
        flag = true;
        break;
      }
    if (flag) continue;
    for (int i = 0; i < k; i++) {
      for (int j = i + 1; j < k; j++)
        if (!prime[(num[i] - '0') * 10 + num[j] - '0']) {
          cout << 2 << '\n' << num[i] << num[j] << '\n';
          flag = true;
          break;
        }
      if (flag) break;
    }
  }
}
