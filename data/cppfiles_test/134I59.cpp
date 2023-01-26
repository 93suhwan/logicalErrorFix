/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int mod=1000000009;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,i;
        cin>>n;
        long long int a,gcd1,gcd2;
        vector<long long int>even,odd;
        for(i=0;i<n;i++)
        {
            if(i%2==0)
            {   
                cin>>a;
                even.push_back(a);
            }
            else
            {
                cin>>a;
                odd.push_back(a);
            }      
        }
        if(n==2)
        {
            if(even[0]==odd[0])
                cout<<0;
            else
                cout<<max(even[0],odd[0]);
        }
        if(n==3)
        {
            gcd1=__gcd(even[0],even[1]);
            if(odd[0]%gcd1==0)
            {
                if(even[0]%odd[0]==0||even[1]%odd[0]==0)
                    cout<<0;
                else
                    cout<<odd[0];
            }
            else
            cout<<gcd1;
        }
        if(n>3)
        {
        gcd1=__gcd(even[0],even[1]);
        gcd2=__gcd(odd[0],odd[1]); 
        int o=0,e=0; int f=0;
        for(int i=0;i<n;i++) 
        {
            if(i%2==0)
            { 
                if(even[e]%gcd2==0)
                {
                    f=1;
                    e++;break;
                }
                else
                {
                    e++;
                    continue;
                }
            }
            else
            {
                if(odd[o]%gcd2==0)
                {
                    o++;
                    continue;
                
                }
                else
                {
                    o++;
                    f=1;break;
                }
                            
            }
        }
        if(f==0) 
            cout<<gcd2;
        else
        {
            o=0,e=0,f=0;
            for(i=0;i<n;i++) 
            {
            if(i%2!=0)
            { 
                if(odd[o]%gcd1==0)
                {
                    f=1;
                    o++;
                    break;
                    
                }
                else{
                     o++;
                     continue;
                    }
                    
                
            }
            else
            {
                if(even[e]%gcd1==0)
                {
                    e++;
                    continue;
                } 
                else
                {
                    e++;f=1;break;
                }
                            
            }
            }
            if(f==0)
                cout<<gcd1;
            else
                cout<<0;

        }
        
    }
    cout<<"\n";

}
}
