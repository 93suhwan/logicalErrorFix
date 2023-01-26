#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isPrime(int n)
{

    if (n <= 1)
        return false;
 
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}
 
void solve()
{
    int k;
    cin>>k;
    string n;
    cin>>n;
    for(int i=0;i<k;i++)
    {
        if(n[i]=='1' || n[i]=='4' || n[i]=='6' || n[i]=='8' || n[i]=='9')
        {
            cout<<1<<endl;
            cout<<n[i]<<endl;
            return;
        }
    }
    for(int i=0;i<k;i++)
        {
            for(int j=i+1;j<k;j++)
            {
                if(!isPrime(((n[i]-'0')*10)+(n[j]-'0')))
                {
                    cout<<2<<endl;
                    cout<<n[i]<<n[j]<<endl;
                }
            }
        }

}
int_fast32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}