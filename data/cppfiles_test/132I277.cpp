#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define int long long
#define endl '\n'

using namespace std;

main()
{

    int t;
    cin >> t;

    for(int _ = 0; _ < t; _++)
    {
        vector <int> b(7);
        for(int i = 0;i < 7; i++)
            cin >> b[i];

        for(int i1 = 0;i1 < 6; i1++)
            for(int i2 = i1 + 1; i2 < 6; i2++)
                for(int i3 = i2 + 1; i3 < 6; i3++)
                    if(b[i1] + b[i2] + b[i3] == b[6])
                        return cout << b[i1] << ' ' << b[i2] << ' ' << b[i3], 0;
    }


    return 0;
}
