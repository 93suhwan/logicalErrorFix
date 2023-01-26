#include <bits/stdc++.h>
using namespace std;
int main() {
  long myArray[7];
  int n;
  cin >> n;
  for (size_t i = 0; i < n; i++) {
    for (int i = 0; i < 7; i++) {
      cin >> myArray[i];
    }
    sort(begin(myArray), end(myArray));
    cout << myArray[0] << ' ' << myArray[1] << ' '
         << myArray[6] - myArray[1] - myArray[0] << endl;
  }
}
