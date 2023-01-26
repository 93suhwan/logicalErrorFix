
#include<bits/stdc++.h>
#define ll long long
using namespace std;

fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fast();

    ll t;
    cin>>t;
    while(t--)
    {
        vector<ll>v;
        ll n;
        cin>>n;
        ll cnt=n/2;
        //cout<<"cnt_init:"<<cnt<<endl;
        while(n--)
        {
            ll a;
            cin>>a;

            v.push_back(a);

        }

        ll flag=0;

        for(int i=0; i<v.size()-1; i++)
        {
            for(int j=i+1; j<v.size(); j++)
            {
                if(v[i]==v[j])
                {
                    continue;
                }
                if(flag==1)
                {
                    break;
                }
                else
                {
                    ll m=v[i]%v[j];
                    // cout<<"M:"<<m<<endl;

                    if(binary_search(v.begin(),v.end(),m)==false)
                    {
                        // cout<<"left_first:"<<endl;
                        cout<<v[i]<<" "<<v[j]<<endl;
                        cnt--;
                        //cout<<" cnt:"<<cnt<<endl;

                    }
                    if(cnt==0)
                    {
                        flag=1;
                    }
                    else
                    {
                        ll n=v[j]%v[i];
                        //cout<<"N:"<<n<<endl;
                        if(binary_search(v.begin(),v.end(),n)==false)
                        {
                            // cout<<"right_first:"<<endl;
                            cout<<v[j]<<" "<<v[i]<<endl;
                            cnt--;
                            //cout<<" cnt:"<<cnt<<endl;

                        }

                            if(cnt==0)
                            {
                               flag=1;
                            }
                    }
                }
            }
        }
    }
}

