#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    string second = to_string(n);
    int sz = second.size();
    long long num = 0;
    for (int i = 0; i < sz; i++) num = num * 10 + 1;
    long long tmp = num, ans;
    for (int i = 1; i < 10; i++) {
      if (num >= n) {
        ans = num;
        break;
      }
      num += tmp;
    }
    if (k == 1) {
      cout << ans << endl;
      continue;
    }
    char ch1 = ' ', ch2 = ' ';
    long long num1 = 0, first = 1;
    int idx;
    for (int i = 0; i < sz; i++) {
      if (ch1 == ' ' || second[i] == ch1) {
        ch1 = second[i];
        num1 = num1 * 10 + (second[i] - '0');
      } else if (second[i] == ch2 || ch2 == ' ') {
        ch2 = second[i];
        num1 = num1 * 10 + (second[i] - '0');
      } else {
        if (second[i] < min(ch1, ch2)) {
          for (int j = i; j < sz; j++) {
            num1 = num1 * 10 + min(ch1, ch2) - '0';
          }
        } else if (second[i] < max(ch1, ch2)) {
          num1 = num1 * 10 + max(ch1, ch2) - '0';
          for (int j = i + 1; j < sz; j++) {
            num1 = num1 * 10 + min(ch1, ch2) - '0';
          }
        } else {
          idx = i;
          first = 0;
        }
        break;
      }
    }
    if (num1 >= n) ans = min(ans, num1);
    if (first == 0) {
      long long num2 = 0;
      int cnt = 0;
      for (int i = 0; i < idx; i++) {
        num2 = num2 * 10 + second[i] - '0';
        long long num3 = num2;
        if (cnt && ch2 < ch1 && second[i] == ch2) {
          num3 += ch1 - ch2;
          for (int j = i + 1; j < sz; j++) {
            num3 = num3 * 10 + ch2 - '0';
          }
        } else if (ch2 < ch1 && second[i] == ch2) {
          num3++;
          if (ch1 == ch2 + 1) {
            for (int j = i + 1; j < sz; j++) num3 *= 10;
          } else {
            for (int j = i + 1; j < sz; j++) num3 = num3 * 10 + (ch2 + 1) - '0';
          }
        } else if (cnt == 0 && ch2 > ch1 && second[i] == ch2) {
          num3++;
          for (int j = i + 1; j < sz; j++) num3 = num3 * 10 + ch1 - '0';
        } else if (cnt && ch1 < ch2 && second[i] == ch1) {
          num3 += ch2 - ch1;
          for (int j = i + 1; j < sz; j++) {
            num3 = num3 * 10 + ch1 - '0';
          }
        }
        if (second[i] == ch2) cnt++;
        if (num3 >= n) ans = min(ans, num3);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
