/******Question*********/
/*
You are given an encryption algorithm in which the plain text is encrypted by XORing the plaintext N times
where N is the length of the string.The catch here is that every time we XOR the string, we shift it to the
right. The string is in hexadecimal.
Your task is given the encrypted text, find the original plain text.

Input:
First line containts the encrypted text.

Output:
You have to output the plaintext.

Constraints
Length of String <= 106

Sample Input:
a1d0a1d

Sample Output:
abcd
*/

/******Solution********/
/**** Author: SHIKHAR TAYAL (ID:2017A7PS1392H)****/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

string hexToBin(string A,int i)
{
        if(A[i] == '0')
            return ("0000");
        if(A[i] == '1')
            return ("0001");
        if(A[i] == '2')
            return ("0010");
        if(A[i] == '3')
            return ("0011");
        if(A[i] == '4')
            return ("0100");
        if(A[i] == '5')
            return ("0101");
        if(A[i] == '6')
            return ("0110");
        if(A[i] == '7')
            return ("0111");
        if(A[i] == '8')
            return ("1000");
        if(A[i] == '9')
            return ("1001");
        if(A[i] == 'a')
            return ("1010");
        if(A[i] == 'b')
            return ("1011");
        if(A[i] == 'c')
            return ("1100");
        if(A[i] == 'd')
            return ("1101");
        if(A[i] == 'e')
            return ("1110");
        if(A[i] == 'f')
            return ("1111");

}

const char binToHex(int temp)
{
    if(temp<=9)
        return (temp + '0');


    else
    {
        if(temp == 10)
            return 'a';
        if(temp == 11)
            return 'b';
        if(temp == 12)
            return 'c';
        if(temp == 13)
            return 'd';
        if(temp == 14)
            return 'e';
        if(temp == 15)
            return 'f';
    }
}

int main()
{
    string input;
    cin >> input;

    string temp;

    int i = 0;
    int l = input.length();

    int xorRes[4];
    for(int z=0;z<4;z++)
        xorRes[z] = 0;

    int tempRes[4];

    for(i=l-1;i>=l/2;i--)
    {
        string get1 = hexToBin(input,i);

        int arr1[4];
        for(int z=0;z<4;z++)
            arr1[z] = get1[z] - '0';

        for(int z=0;z<4;z++)
            tempRes[z] = xorRes[z] ^ arr1[z];

        for(int z=0;z<4;z++)
            xorRes[z] = xorRes[z] ^ tempRes[z];

        int decVal = tempRes[0]*8+ tempRes[1]*4 + tempRes[2]*2 + tempRes[3]*1;
        temp.push_back(binToHex(decVal));

    }


    string result;
    for(int z=temp.length()-1;z>=0;z--)
        result.push_back(temp[z]);

    cout << result;

    return 0;

}
