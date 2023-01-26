#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  while (k--) {
    int w, h, ans[300000];
    cin >> w >> h;
    long long int num1, max1;
    cin >> num1;
    for (int i = 1; i <= num1; i++) {
      cin >> ans[i];
    }
    max1 = -ans[1] + ans[num1];
    long long int num2, max2;
    cin >> num2;
    for (int i = 1; i <= num2; i++) {
      cin >> ans[i];
    }
    max2 = -ans[1] + ans[num2];
    long long int num3, max3;
    cin >> num3;
    for (int i = 1; i <= num3; i++) {
      cin >> ans[i];
    }
    max3 = -ans[1] + ans[num3];
    long long int num4, max4;
    cin >> num4;
    for (int i = 1; i <= num4; i++) {
      cin >> ans[i];
    }
    max4 = -ans[1] + ans[num4];
    max1 = max1 > max2 ? max1 : max2;
    max3 = max3 > max4 ? max3 : max4;
    long long int max =
        abs(max1 * h) > abs(max3 * w) ? abs(max1 * h) : abs(max3 * w);
    cout << max << endl;
  }
}
