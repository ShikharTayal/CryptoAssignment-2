/********* Question ***********/

/*
You have to perform mathematical calcuations in the given Galois Field.
The input given is f(x) and g(x), which are 2 polynomials, also m(x) which is an irreducible polynomial for that particular field. You have to calculate f(x)*g(x)mod(m(x)).

Input:
First line has f(x) in binary format.Alt text Second line has g(x) in binary format. Third line has m(x) in binary format.

Output:
Output f(x)*g(x)mod(m(x)) in binary format. Output 0 for zero polynomial.

Constraints
For Galois Fields, GF(2n), n<=8. Degree of polynomials <= 10.

Sample Input:
10111011
1011
100011101

Sample Output:
1100001

*/

/**********Solution**********/
/**** Author: SHIKHAR TAYAL (ID:2017A7PS1392H)****/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int highestPow(int A[])
{
    int i;
    for(i=0;i<25;i++)
    {
        if(A[i] == 1)
            break;

    }
    return i;
}

int main()
{
    string p1,p2,m;

    cin >> p1 >> p2 >> m;

    int l1 = p1.length();
    int l2 = p2.length();
    int l3 = m.length();

    int v1[25];
    int v2[25];
    int v[25];
    int mul[25];

    int i =0;
    for(i=0;i<25;i++)
    {
        v1[i] = v2[i] = v[i] = mul[i] = 0;
    }


   int k = 24;

    for(i=l1-1;i>=0;i--)
        {
            v1[k] = p1[i] - '0';
            k--;
        }

    k = 24;

    for(i=l2-1;i>=0;i--)
        {
            v2[k] = p2[i] - '0';
            k--;
        }

    k = 24;

    for(i=l3-1;i>=0;i--)
        {
            v[k] = m[i] - '0';
            k--;
        }


    int shift = 0;
    
/*--------- Multiplying polynomial 1 and polynomial 2 and storing result in mul------------ */

    for(k=24;k>=0;k--)
    {
        int temp[25];

        if(v2[k] == 1)
        {
            
            for(int z=0;z<25;z++)
                temp[z] = v1[z];

            int cnt = shift;

            while(cnt >0)
            {
                for(int z=0;z<24;z++)
                    temp[z] = temp[z+1];
                temp[24] = 0;
                cnt--;
            }

            for(int z=0;z<25;z++)
            mul[z] = mul[z] ^ temp[z];

        }

      shift++;

    }

/*-----------Calulating Modulo of above multiplication in m(x) -------------*/
    
    int mulpow = highestPow(mul);
    int modpow = highestPow(v); 

    while(mulpow <= modpow)   //If Mul power is more than equal to mod power, reduction has to occur
    {
        int temp[25];
        for(int z=0;z<25;z++)
        {
            temp[z] = v[z];

        }

        int diff = modpow - mulpow;

        while(diff > 0)
        {
            for(int z=0;z<24;z++)
                temp[z] = temp[z+1];
            temp[24] = 0;
            diff--;
        }

        for(int z = 0;z<25;z++)
            mul[z] = mul[z] ^ temp[z];

        mulpow = highestPow(mul);

    }
    
/*----------Result----------*/
    
    int res[25-mulpow];
    k=0;

    for(i = mulpow;i<25;i++)
    {
        res[k] = mul[i];
        k++;
    }

    for(int z=0;z<k;z++)
            cout << res[z];

    return 0;
}
