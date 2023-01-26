#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
void process() {
  lli num;
  cin >> num;
  string s;
  cin >> s;
  int nums[num];
  lli coun = 0;
  for (int i = 0; i < num; i++) {
    nums[i] = s[i] - '0';
  }
  for (int i = 0; i < num; i++) {
    if (nums[i] != 0) {
      coun += nums[i] + 1;
    }
  }
  if (nums[num - 1] == 0) {
    cout << coun << endl;
  } else {
    cout << coun - 1 << endl;
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) process();
  return 0;
}
