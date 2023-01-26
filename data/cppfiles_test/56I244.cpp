#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  while (t--) {
    bool flag = 1;
    for (; flag;)
      for (int i = 1; i <= 8 && flag; i++)
        for (int j = (i % 2 ? 1 : 8); j <= 8 && j >= 1 && flag;
             j += (i % 2 ? 1 : -1)) {
          cout << i << " " << j << endl;
          cout.flush();
          string str;
          cin >> str;
          if (str == "Done") flag = 0;
        }
  }
  return 0;
}
