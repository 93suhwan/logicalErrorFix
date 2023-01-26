#include <bits/stdc++.h>
using namespace std;
struct block {
  string str;
  int pos;
};
static bool compare(block b1, block b2) {
  int n = b1.str.length();
  for (int i = 0; i < n; i++) {
    if (b1.str[i] != b2.str[i]) {
      if ((i + 1) % 2) {
        return (b1.str[i] < b2.str[i]);
      } else {
        return (b1.str[i] > b2.str[i]);
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<block> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i].str;
    arr[i].pos = i + 1;
  }
  sort(arr.begin(), arr.end(), compare);
  for (int i = 0; i < n; i++) {
    cout << arr[i].pos << " ";
  }
}
