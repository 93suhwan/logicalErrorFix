#include <bits/stdc++.h>
int main() {
  long long count, number;
  long long Totalnumber = 200001;
  std::vector<long long> Calresult(Totalnumber);
  Calresult[2] = 1;
  for (long long i = 3; i <= Totalnumber; i++) {
    Calresult[i] = Calresult[i - 1] % 1000000007 * i % 1000000007;
  }
  std::cin >> count;
  while (count--) {
    std::cin >> number;
    std::cout << Calresult[number * 2] << std::endl;
  }
  return 0;
}
