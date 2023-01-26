#include <bits/stdc++.h>
#include <algorithm>
#include <deque>
using namespace std;
typedef long long int ll;
const double pi = 3.14159265358979323846;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n][n];
        int z=0;
        int cnt=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin>>a[i][j];
                if (a[i][j]==1)
                {
                    cnt++;
                }
                
            }
            if (cnt==0)
            {
                z++;
            }
            z=0;
            
            
        }
        if (z>0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        
        int sum=0;
        vector<int>v;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum=sum+a[j][i];
            }
            v.push_back(sum);
            sum=0;
            
        }
        sort(v.begin(),v.end(),greater<>());
        if (v[0]>=n/2 && v[1]>=n/2)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
        
    }
    
    

    
}