#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream in("cufar.in");
ofstream out("cufar.out");

bool sieve[1000005];

void genSieve()
{
    sieve[0]=false;
    sieve[1]=false;
    sieve[2]=true;
    for(int i=3;i<1000005;i=i+2)
        sieve[i]=true;
    for(int p=3;p*p<1000005;p=p+2)
    {
        if (sieve[p] == true)
        {
            for (int i=p*2; i<=1000005; i += p)
                sieve[i] = false;
        }
    }
}

int main()
{int program,n,sum=0,nr,k;
    in>>program>>n;
    genSieve();
    for(int i=0;i<n;i++)
    {
        in>>nr>>k;
        int nrDiv=1,div;
        for(int j=2;j<nr/2;j++)
        {
            if(sieve[j]==false)
                continue;
            if(nr%j==0)
                nrDiv++;
            if(nrDiv==k)
                div = j;
        }
        for(int j=div+2;j<1000005;j=j+2)
            if(sieve[j]==true && nr%j == 0)
            {
                div=j;
                break;
            }
        if(k==1 && nr%2==0)
            div=2;
        if(program==1)
            out<<div<<"\n";
        else
            sum = sum+ div;
    }
    if(program == 2)
        out<<sum;
    return 0;
}
