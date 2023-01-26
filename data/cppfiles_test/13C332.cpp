#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t = 0;
  int ac = 0;
  int b = 0;
  string input;
  string result[1005] = {""};
  if (cin >> t) {
    for (int i = 0; i < t; i++) {
      cin >> input;
      for (int j = 0; j < input.size(); j++) {
        if (input[j] == 'B')
          b++;
        else
          ac++;
      }
      if (ac == b && ac != 0)
        result[i] = "YES";
      else
        result[i] = "NO";
      ac = 0;
      b = 0;
    }
    for (int i = 0; i < t; i++) {
      cout << result[i];
      cout << endl;
    }
  }
  return 0;
}
