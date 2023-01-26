#include <bits/stdc++.h>
using namespace std;
int main() {
  int array[5] = {1, 2, 3, 4, 5};
  if (array[0] == array[1] || array[1] == array[2] || array[1] == array[3] ||
      array[1] == array[4] || array[2] == array[4] || array[2] == array[3] ||
      array[3] == array[4] || array[1] == array[5] || array[2] == array[5] ||
      array[3] == array[5] || array[4] == array[5])
    cout << "1";
  else
    cout << "0";
  return 0;
}
