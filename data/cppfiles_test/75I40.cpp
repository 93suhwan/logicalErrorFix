#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  cin >> n;
  vector<long> arr;
  while (n--) {
    long ele;
    cin >> ele;
    arr.push_back(ele);
  }
  long i = 0;
  long j = arr.size() - 1;
  long currMove = 0;
  long selected = 0;
  while (i <= j && j >= 0) {
    if (arr[i] <= arr[j] && selected < arr[i]) {
      selected = arr[i];
      i++;
      currMove++;
    } else if (selected < arr[j]) {
      selected = arr[j];
      j--;
      currMove++;
    } else {
      break;
    }
  }
  if (currMove % 2 == 0) {
    cout << "Bob" << endl;
  } else
    cout << "Alice" << endl;
}
