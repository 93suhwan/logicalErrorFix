#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test_case;
  cin >> test_case;
  while (test_case--) {
    int user_input;
    cin >> user_input;
    user_input -= 2;
    cout << "1 " << user_input << " 1\n";
  }
  return 0;
}
