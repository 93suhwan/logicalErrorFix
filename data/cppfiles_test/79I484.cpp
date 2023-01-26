#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int book[101];
int pd(int n) {
  if (n == 1) return 1;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 1;
  }
  return 0;
}
int main(void) {
  int T;
  cin >> T;
  for (int i = 1; i <= 100; i++) book[i] = pd(i);
  while (T--) {
    int k, t = 0;
    cin >> k;
    char ch[N];
    cin >> ch;
    for (int i = 0; i < k; i++) {
      if (book[ch[i] - '0']) {
        cout << 1 << endl;
        cout << ch[i] << endl;
        t = 1;
        break;
      }
    }
    if (!t) {
      for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
          int ans = (ch[i] - '0') * 10 + (ch[j] - '0');
          if (book[ans]) {
            cout << 2 << endl;
            cout << ch[i] << ch[j] << endl;
            break;
          }
        }
      }
    }
  }
  return 0;
}
