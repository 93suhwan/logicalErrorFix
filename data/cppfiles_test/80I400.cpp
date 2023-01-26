#include <bits/stdc++.h>
using namespace std;
void solve(int z) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int least_length = (n / 2);
  int zero_found = -1;
  for (int i = 0; i < (least_length + 1); i++) {
    if (s[i] == '0') {
      zero_found = i;
      break;
    }
  }
  if (zero_found > -1) {
    printf("%d %d %d %d", zero_found + 1, zero_found + least_length + 1,
           zero_found + 2, zero_found + least_length + 1);
  } else {
    int first = 1;
    int second = least_length;
    printf("%d %d %d %d", first, second, first + 1, second + 1);
  }
  cout << endl;
}
int main() {
  int test_case;
  cin >> test_case;
  for (int k = 1; k <= test_case; k++) {
    solve(k);
  }
}
