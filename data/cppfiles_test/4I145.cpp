#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <array>
#include <sstream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <chrono>
#include <ctime> 
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int p, a;
		cin >> p;
		a = sqrt(p);
		cout << a << " " << a * a << endl;
	}
}

