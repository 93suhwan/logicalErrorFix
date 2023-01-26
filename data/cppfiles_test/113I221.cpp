#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
template <class T>
void printArray(T* arr, int sizeOfArray) {
  for (int(i) = (0); (i) < (sizeOfArray); (i)++) cout << arr[i] << " ";
  cout << "\n";
}
template <class T>
void printVector(vector<T>& v) {
  int vSize = v.size();
  for (int(i) = (0); (i) < (vSize); (i)++) cout << v[i] << " ";
  cout << "\n";
}
int numOfDigits(int x) { return to_string(x).length(); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    ;
    if (x1 == x2) {
      if (p1 < p2)
        cout << "<\n";
      else if (p1 > p2)
        cout << ">\n";
      else
        cout << "=\n";
    } else {
      if (x1 < x2) {
        int diff = numOfDigits(x2) - numOfDigits(x1);
        x1 *= pow(10, diff);
        p1 -= diff;
      } else {
        int diff = numOfDigits(x1) - numOfDigits(x2);
        x2 *= pow(10, diff);
        p2 -= diff;
      }
      if (p1 <= 0 && p2 <= 0) {
        if (x1 < x2)
          cout << "<\n";
        else if (x1 > x2)
          cout << ">\n";
        else
          cout << "=\n";
      } else {
        if (p1 > p2)
          cout << ">\n";
        else if (p1 < p2)
          cout << "<\n";
        else
          cout << "=\n";
      }
    }
  }
  return 0;
}
