#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr;
  while (n--) {
    int ele;
    cin >> ele;
    arr.push_back(ele);
  }
  int i = 0;
  int j = arr.size() - 1;
  int currMove = 0;
  int selected = 0;
  while (i <= j && j >= 0) {
    if (arr[i] <= arr[j] && selected < arr[i]) {
      selected = arr[i];
      i++;
      currMove++;
    } else if (selected > arr[i] && selected < arr[j]) {
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
