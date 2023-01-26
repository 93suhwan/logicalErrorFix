#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++)
    {
        string ke,s;
        cin>>ke>>s;
        ll len=s.size();
        ll arr[len]={0};
        ll m=0;

        for(ll j=0;j<s.size();j++)
        {
            for(ll l=0;j<ke.size();l++)
            {
                if(s[j]==ke[l])
                {
                    arr[m]=l+1;
                    m++;
                    break;
                }

            }
        }
        ll sum=0;
        for(ll i=1;i<m;i++)
        {
            sum=sum+abs(arr[i]-arr[i-1]);
        }
        cout<<sum<<endl;
    }
    return 0;

}
