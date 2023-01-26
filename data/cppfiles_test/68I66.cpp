#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (long long f = 1; f <= t; f++) {
    long long k;
    cin >> k;
    long long root = sqrt(k);
    if (root * root == k) {
      cout << root << " "
           << "1" << endl;
      continue;
    }
    if (k == 2) {
      cout << "1"
           << " "
           << "2" << endl;
      continue;
    }
    long long row;
    long long column;
    long long pivot = ((root + 1) * (root + 1) + root * root + 1) / 2;
    if (k > pivot) {
      row = (root + 1);
      column = (2 * pivot - k) % (root * root);
    } else {
      column = root + 1;
      row = k % (root * root);
    }
    cout << row << " " << column << endl;
  }
}
