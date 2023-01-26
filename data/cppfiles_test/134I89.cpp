#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#define gcd __gcd
#define LL long long
#define PII pair<int,int>
#define MII map<int,int>
#define MIS map<int,string>
#define MSI map<string,int>
#define VI vector<int>
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()

using namespace std;
const int N = 1e6 + 10,M = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

LL arr[N];

int main()
{
    int tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        for(int i = 1;i <= n;i ++)
            cin >> arr[i];

        LL num1 = 1,num2 = 1;
        for(int i = 1;i <= n;i += 2)
        {
            if(i == 1)num1 = arr[i];
            else num1 = gcd(num1,arr[i]);
        }

        for(int i = 2;i <= n;i += 2)
        {
            if(i == 2)num2 = arr[i];
            else num2 = gcd(num2,arr[i]);
        }

        if(num1 == num2)cout << 0 << "\n";
        else {
            int f = 1;
            if(num1 > num2)
            {
                for(int i = 2;i <= n;i += 2)
                {
                    if(arr[i] % num1 == 0){
                        f = 0;
                        break;
                    }
                }
            }else {
                for(int i = 1;i <= n;i += 2)
                {
                    if(arr[i] % num2 == 0)
                    {
                        f = 0;
                        break;
                    }
                }
            }

            if(f)
            {
                if(num1 > num2)cout << num1 << "\n";
                else cout << num2 << "\n";
            }else cout << "0\n";
        }
    }

    return 0;
}
