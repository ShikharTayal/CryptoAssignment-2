#include <iostream>
#include<bits/stdc++.h>

using namespace std;

const char* mul2[16][16] =
{
	 "00", "02", "04", "06", "08", "0A", "0C", "0E", "10", "12", "14", "16", "18", "1A", "1C", "1E",
	 "20", "22", "24", "26", "28", "2A", "2C", "2E", "30", "32", "34", "36", "38", "3A", "3C", "3E",
	 "40", "42", "44", "46", "48", "4A", "4C", "4E", "50", "52", "54", "56", "58", "5A", "5C", "5E",
	 "60", "62", "64", "66", "68", "6A", "6C", "6E", "70", "72", "74", "76", "78", "7A", "7C", "7E",
	 "80", "82", "84", "86", "88", "8A", "8C", "8E", "90", "92", "94", "96", "98", "9A", "9C", "9E",
	 "A0", "A2", "A4", "A6", "A8", "AA", "AC", "AE", "B0", "B2", "B4", "B6", "B8", "BA", "BC", "BE",
	 "C0", "C2", "C4", "C6", "C8", "CA", "CC", "CE", "D0", "D2", "D4", "D6", "D8", "DA", "DC", "DE",
	 "E0", "E2", "E4", "E6", "E8", "EA", "EC", "EE", "F0", "F2", "F4", "F6", "F8", "FA", "FC", "FE",
	 "1B", "19", "1F", "1D", "13", "11", "17", "15", "0B", "09", "0F", "0D", "03", "01", "07", "05",
	 "3B", "39", "3F", "3D", "33", "31", "37", "35", "2B", "29", "2F", "2D", "23", "21", "27", "25",
	 "5B", "59", "5F", "5D", "53", "51", "57", "55", "4B", "49", "4F", "4D", "43", "41", "47", "45",
	 "7B", "79", "7F", "7D", "73", "71", "77", "75", "6B", "69", "6F", "6D", "63", "61", "67", "65",
	 "9B", "99", "9F", "9D", "93", "91", "97", "95", "8B", "89", "8F", "8D", "83", "81", "87", "85",
	 "BB", "B9", "BF", "BD", "B3", "B1", "B7", "B5", "AB", "A9", "AF", "AD", "A3", "A1", "A7", "A5",
	 "DB", "D9", "DF", "DD", "D3", "D1", "D7", "D5", "CB", "C9", "CF", "CD", "C3", "C1", "C7", "C5",
	 "FB", "F9", "FF", "FD", "F3", "F1", "F7", "F5", "EB", "E9", "EF", "ED", "E3", "E1", "E7", "E5"
};


// Encryption: Multiply by 3 for MixColumns
const char* mul3[16][16] =
{
	 "00", "03", "06", "05", "0C", "0F", "0A", "09", "18", "1B", "1E", "1D", "14", "17", "12", "11",
	 "30", "33", "36", "35", "3C", "3F", "3A", "39", "28", "2B", "2E", "2D", "24", "27", "22", "21",
	 "60", "63", "66", "65", "6C", "6F", "6A", "69", "78", "7B", "7E", "7D", "74", "77", "72", "71",
	 "50", "53", "56", "55", "5C", "5F", "5A", "59", "48", "4B", "4E", "4D", "44", "47", "42", "41",
	 "C0", "C3", "C6", "C5", "CC", "CF", "CA", "C9", "D8", "DB", "DE", "DD", "D4", "D7", "D2", "D1",
	 "F0", "F3", "F6", "F5", "FC", "FF", "FA", "F9", "E8", "EB", "EE", "ED", "E4", "E7", "E2", "E1",
	 "A0", "A3", "A6", "A5", "AC", "AF", "AA", "A9", "B8", "BB", "BE", "BD", "B4", "B7", "B2", "B1",
	 "90", "93", "96", "95", "9C", "9F", "9A", "99", "88", "8B", "8E", "8D", "84", "87", "82", "81",
	 "9B", "98", "9D", "9E", "97", "94", "91", "92", "83", "80", "85", "86", "8F", "8C", "89", "8A",
	 "AB", "A8", "AD", "AE", "A7", "A4", "A1", "A2", "B3", "B0", "B5", "B6", "BF", "BC", "B9", "BA",
	 "FB", "F8", "FD", "FE", "F7", "F4", "F1", "F2", "E3", "E0", "E5", "E6", "EF", "EC", "E9", "EA",
	 "CB", "C8", "CD", "CE", "C7", "C4", "C1", "C2", "D3", "D0", "D5", "D6", "DF", "DC", "D9", "DA",
	 "5B", "58", "5D", "5E", "57", "54", "51", "52", "43", "40", "45", "46", "4F", "4C", "49", "4A",
	 "6B", "68", "6D", "6E", "67", "64", "61", "62", "73", "70", "75", "76", "7F", "7C", "79", "7A",
	 "3B", "38", "3D", "3E", "37", "34", "31", "32", "23", "20", "25", "26", "2F", "2C", "29", "2A",
	 "0B", "08", "0D", "0E", "07", "04", "01", "02", "13", "10", "15", "16", "1F", "1C", "19", "1A"
};


const char* S_Box[16][16] = {
    {"63", "7C", "77", "7B", "F2", "6B", "6F", "C5", "30", "01", "67", "2B", "FE", "D7", "AB", "76"},
    {"CA", "82", "C9", "7D", "FA", "59", "47", "F0", "AD", "D4", "A2", "AF", "9C", "A4", "72", "C0"},
    {"B7", "FD", "93", "26", "36", "3F", "F7", "CC", "34", "A5", "E5", "F1", "71", "D8", "31", "15"},
    {"04", "C7", "23", "C3", "18", "96", "05", "9A", "07", "12", "80", "E2", "EB", "27", "B2", "75"},
    {"09", "83", "2C", "1A", "1B", "6E", "5A", "A0", "52", "3B", "D6", "B3", "29", "E3", "2F", "84"},
    {"53", "D1", "00", "ED", "20", "FC", "B1", "5B", "6A", "CB", "BE", "39", "4A", "4C", "58", "CF"},
    {"D0", "EF", "AA", "FB", "43", "4D", "33", "85", "45", "F9", "02", "7F", "50", "3C", "9F", "A8"},
    {"51", "A3", "40", "8F", "92", "9D", "38", "F5", "BC", "B6", "DA", "21", "10", "FF", "F3", "D2"},
    {"CD", "0C", "13", "EC", "5F", "97", "44", "17", "C4", "A7", "7E", "3D", "64", "5D", "19", "73"},
    {"60", "81", "4F", "DC", "22", "2A", "90", "88", "46", "EE", "B8", "14", "DE", "5E", "0B", "DB"},
    {"E0", "32", "3A", "0A", "49", "06", "24", "5C", "C2", "D3", "AC", "62", "91", "95", "E4", "79"},
    {"E7", "C8", "37", "6D", "8D", "D5", "4E", "A9", "6C", "56", "F4", "EA", "65", "7A", "AE", "08"},
    {"BA", "78", "25", "2E", "1C", "A6", "B4", "C6", "E8", "DD", "74", "1F", "4B", "BD", "8B", "8A"},
    {"70", "3E", "B5", "66", "48", "03", "F6", "0E", "61", "35", "57", "B9", "86", "C1", "1D", "9E"},
    {"E1", "F8", "98", "11", "69", "D9", "8E", "94", "9B", "1E", "87", "E9", "CE", "55", "28", "DF"},
    {"8C", "A1", "89", "0D", "BF", "E6", "42", "68", "41", "99", "2D", "0F", "B0", "54", "BB", "16"}
};
const char* Rcon[10] = {"01000000", "02000000", "04000000", "08000000", "10000000",
                 "20000000", "40000000", "80000000", "1B000000", "36000000"};

int binToDec(int n)
{
    int num = n;
    int dec = 0;

    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec += last_digit * base;

        base = base * 2;
    }

    return dec;
}





int main()
{

    string input_pt;
    string input_key;

    cin >> input_pt >> input_key;

    string bin_pt;
    string bin_key;

    int i,j;

    for(i=0;i<32;i++)
    {
        if(input_key[i] == '0')
            bin_key.append("0000");
        if(input_key[i] == '1')
            bin_key.append("0001");
        if(input_key[i] == '2')
            bin_key.append("0010");
        if(input_key[i] == '3')
            bin_key.append("0011");
        if(input_key[i] == '4')
            bin_key.append("0100");
        if(input_key[i] == '5')
            bin_key.append("0101");
        if(input_key[i] == '6')
            bin_key.append("0110");
        if(input_key[i] == '7')
            bin_key.append("0111");
        if(input_key[i] == '8')
            bin_key.append("1000");
        if(input_key[i] == '9')
            bin_key.append("1001");
        if(input_key[i] == 'A')
            bin_key.append("1010");
        if(input_key[i] == 'B')
            bin_key.append("1011");
        if(input_key[i] == 'C')
            bin_key.append("1100");
        if(input_key[i] == 'D')
            bin_key.append("1101");
        if(input_key[i] == 'E')
            bin_key.append("1110");
        if(input_key[i] == 'F')
            bin_key.append("1111");
    }

        for(i=0;i<32;i++)
    {
        if(input_pt[i] == '0')
            bin_pt.append("0000");
        if(input_pt[i] == '1')
            bin_pt.append("0001");
        if(input_pt[i] == '2')
            bin_pt.append("0010");
        if(input_pt[i] == '3')
            bin_pt.append("0011");
        if(input_pt[i] == '4')
            bin_pt.append("0100");
        if(input_pt[i] == '5')
            bin_pt.append("0101");
        if(input_pt[i] == '6')
            bin_pt.append("0110");
        if(input_pt[i] == '7')
            bin_pt.append("0111");
        if(input_pt[i] == '8')
            bin_pt.append("1000");
        if(input_pt[i] == '9')
            bin_pt.append("1001");
        if(input_pt[i] == 'A')
            bin_pt.append("1010");
        if(input_pt[i] == 'B')
            bin_pt.append("1011");
        if(input_pt[i] == 'C')
            bin_pt.append("1100");
        if(input_pt[i] == 'D')
            bin_pt.append("1101");
        if(input_pt[i] == 'E')
            bin_pt.append("1110");
        if(input_pt[i] == 'F')
            bin_pt.append("1111");
    }
   // cout << bin_key;
    int w[44][32];
    int round[11][128];

    for(j=0;j<32;j++)
    {
        w[0][j] = bin_key[j] - '0';
        w[1][j] = bin_key[j+32] - '0';
        w[2][j] = bin_key[j+64] - '0';
        w[3][j] = bin_key[j+96] - '0';
    }


    for(i=0;i<32;i++)
    {
        round[0][i] = w[0][i];
        round[0][i+32] = w[1][i];
        round[0][i+64] = w[2][i];
        round[0][i+96] = w[3][i];
    }

    /*for(i=0;i<128;i++)
        cout << round[0][i];*/
   int shift[32];

   int roundNum = 0;
   for(i=0;i<40;i+=4)
    {
        int num = i+3;

        for(j=0;j<32;j++)
            shift[j] = w[num][j];           // temp shift array for byte shifting

        for(j=0;j<8;j++)
        {
            int temp = shift[0];
            for(int k=0;k<31;k++)
                shift[k] = shift[k+1];

            shift[31] = temp;
        }

        string ByteSub;
        int ByteSubBin[32];

        for(j=0;j<32;j+=8)
        {
            int row = shift[j]*1000 + shift[j+1]*100 + shift[j+2]*10 + shift[j+3]*1;
            int col = shift[j+4]*1000 + shift[j+5]*100 + shift[j+6]*10 + shift[j+7]*1;

            int rowdec = binToDec(row);
            int coldec = binToDec(col);

            string tempByte = S_Box[rowdec][coldec];

           // cout << tempByte;


            for(int z = 0; z <2; z++)
            {
                if(tempByte[z] == '0')
                    ByteSub.append("0000");
                if(tempByte[z] == '1')
                    ByteSub.append("0001");
                if(tempByte[z] == '2')
                    ByteSub.append("0010");
                if(tempByte[z] == '3')
                    ByteSub.append("0011");
                if(tempByte[z] == '4')
                    ByteSub.append("0100");
                if(tempByte[z] == '5')
                    ByteSub.append("0101");
                if(tempByte[z] == '6')
                    ByteSub.append("0110");
                if(tempByte[z] == '7')
                    ByteSub.append("0111");
                if(tempByte[z] == '8')
                    ByteSub.append("1000");
                if(tempByte[z] == '9')
                    ByteSub.append("1001");
                if(tempByte[z] == 'A')
                    ByteSub.append("1010");
                if(tempByte[z] == 'B')
                    ByteSub.append("1011");
                if(tempByte[z] == 'C')
                    ByteSub.append("1100");
                if(tempByte[z] == 'D')
                    ByteSub.append("1101");
                if(tempByte[z] == 'E')
                    ByteSub.append("1110");
                if(tempByte[z] == 'F')
                    ByteSub.append("1111");
            }

           //  cout << ByteSub;

        }

        for(int z = 0 ;z < 32;z++)              // Byte Sub string to bytesub int array
            ByteSubBin[z] = ByteSub[z] - '0';


    string tempRC = Rcon[roundNum];

    string temp2RC;

    for(int z=0;z<8;z++)
        {
                if(tempRC[z] == '0')
                    temp2RC.append("0000");
                if(tempRC[z] == '1')
                    temp2RC.append("0001");
                if(tempRC[z] == '2')
                    temp2RC.append("0010");
                if(tempRC[z] == '3')
                    temp2RC.append("0011");
                if(tempRC[z] == '4')
                    temp2RC.append("0100");
                if(tempRC[z] == '5')
                    temp2RC.append("0101");
                if(tempRC[z] == '6')
                    temp2RC.append("0110");
                if(tempRC[z] == '7')
                    temp2RC.append("0111");
                if(tempRC[z] == '8')
                    temp2RC.append("1000");
                if(tempRC[z] == '9')
                    temp2RC.append("1001");
                if(tempRC[z] == 'A')
                    temp2RC.append("1010");
                if(tempRC[z] == 'B')
                    temp2RC.append("1011");
                if(tempRC[z] == 'C')
                    temp2RC.append("1100");
                if(tempRC[z] == 'D')
                    temp2RC.append("1101");
                if(tempRC[z] == 'E')
                    temp2RC.append("1110");
                if(tempRC[z] == 'F')
                    temp2RC.append("1111");
        }

        //cout << temp2RC;

        int addRC[32];

        for(int z=0;z<32;z++)
            addRC[z] = temp2RC[z] - '0';

    int g[32];

    for(int z=0;z<32;z++)
        g[z] = ByteSubBin[z] ^ addRC[z];

   /* for(int z=0;z<32;z++)
        cout << g[z];*/


    for(int z=0;z<32;z++)
        {
            w[i+4][z] = w[i][z] ^ g[z];
            w[i+5][z] = w[i+4][z] ^ w[i+1][z];
            w[i+6][z] = w[i+5][z] ^ w[i+2][z];
            w[i+7][z] = w[i+6][z] ^ w[i+3][z];
        }


     for(int z=0;z<32;z++)
        {
            round[roundNum+1][z] = w[i+4][z];
            round[roundNum+1][z+32] = w[i+5][z];
            round[roundNum+1][z+64] = w[i+6][z];
            round[roundNum+1][z+96] = w[i+7][z];
        }

        roundNum++;


    }

    char roundKey[11][32];
    for(int z=1;z<11;z++)
    {
        int i=0;
        int j=0;

        for(i=0;i<128;i+=4,j++)
        {
            int temp = round[z][i]*8 + round[z][i+1]*4 + round[z][i+2]*2 + round[z][i+3]*1;

            if(temp<=9)
               roundKey[z][j] = temp + '0';

            else
            {
                if(temp == 10)
               roundKey[z][j] = 'A';
                if(temp == 11)
               roundKey[z][j] = 'B';
                if(temp == 12)
               roundKey[z][j] = 'C';
                if(temp == 13)
               roundKey[z][j] = 'D';
                if(temp == 14)
               roundKey[z][j] = 'E';
                if(temp == 15)
               roundKey[z][j] = 'F';

            }

        }

        /*for(int p=0;p<32;p++)
            cout << roundKey[z][p];

        cout << endl;*/
    }


    string plaintext[4][4];

    int cnt = 0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            string temp ;
            for(int z=0;z<8;z++)
                {
                    temp.push_back(bin_pt[cnt+z]);

                }

            cnt+=8;
            plaintext[j][i] = temp;

       }
    }

    string key[4][4];

    cnt = 0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            string temp ;
            for(int z=0;z<8;z++)
                {
                    temp.push_back(round[0][cnt+z] + '0');

                }

               // temp.push_back(' ');
            cnt+=8;
            key[j][i] = temp;

       }
    }



    string statemat[4][4];
//Round 0 key addition
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            string temp1 = plaintext[i][j];
            string temp2 = key[i][j];
            string result;

            int tempA1[8],tempA2[8],tempresult[8];

            for(int z=0;z<8;z++)
            {
                tempA1[z] = temp1[z] - '0';
                tempA2[z] = temp2[z] - '0';
                tempresult[z] = tempA1[z] ^ tempA2[z];
                result.push_back(tempresult[z] + '0');
            }
            statemat[i][j] = result;
        }
    }
 //Byte Substitution for Round 1

 int roundCnt = 1;
 while(roundCnt <11)
 {

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {

            int rowNum =0 , colNum=0;
            int tempA1[4],tempA2[4];

            string temp = statemat[i][j];

            for(int r=0;r<4;r++)
            {
               tempA1[r] = temp[r] - '0';
               tempA2[r] = temp[r+4] - '0';
            }


            rowNum = tempA1[0]*1000 + tempA1[1]*100 + tempA1[2]*10 + tempA1[3]*1;
            colNum = tempA2[0]*1000 + tempA2[1]*100 + tempA2[2]*10 + tempA2[3]*1;

            int rowdec = binToDec(rowNum);
            int coldec = binToDec(colNum);

            string tempRC = S_Box[rowdec][coldec];
            string temp2RC;

            for(int z=0;z<2;z++)
                {
                    if(tempRC[z] == '0')
                        temp2RC.append("0000");
                    if(tempRC[z] == '1')
                        temp2RC.append("0001");
                    if(tempRC[z] == '2')
                        temp2RC.append("0010");
                    if(tempRC[z] == '3')
                        temp2RC.append("0011");
                    if(tempRC[z] == '4')
                        temp2RC.append("0100");
                    if(tempRC[z] == '5')
                        temp2RC.append("0101");
                    if(tempRC[z] == '6')
                        temp2RC.append("0110");
                    if(tempRC[z] == '7')
                        temp2RC.append("0111");
                    if(tempRC[z] == '8')
                        temp2RC.append("1000");
                    if(tempRC[z] == '9')
                        temp2RC.append("1001");
                    if(tempRC[z] == 'A')
                        temp2RC.append("1010");
                    if(tempRC[z] == 'B')
                        temp2RC.append("1011");
                    if(tempRC[z] == 'C')
                        temp2RC.append("1100");
                    if(tempRC[z] == 'D')
                        temp2RC.append("1101");
                    if(tempRC[z] == 'E')
                        temp2RC.append("1110");
                    if(tempRC[z] == 'F')
                        temp2RC.append("1111");
                }

                statemat[i][j] = temp2RC;

        }

    }
    //Shift Rows
    string temp1 = statemat[1][0];

    statemat[1][0] = statemat[1][1];
    statemat[1][1] = statemat[1][2];
    statemat[1][2] = statemat[1][3];
    statemat[1][3] = temp1;

    temp1 = statemat[2][0];
    string temp2 = statemat[2][1];
    statemat[2][0] = statemat[2][2];
    statemat[2][1] = statemat[2][3];
    statemat[2][2] = temp1;
    statemat[2][3] = temp2;

    temp1 = statemat[3][3];
    statemat[3][3] = statemat[3][2];
    statemat[3][2] = statemat[3][1];
    statemat[3][1] = statemat[3][0];
    statemat[3][0] = temp1;

    //Mix Columns

    if(roundCnt!=10)
    {
    int rowdec[16],coldec[16];
    cnt = 0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            int colNum=0,rowNum=0;
            string temp = statemat[j][i];
            int tempA1[4],tempA2[4];

            for(int r=0;r<4;r++)
            {
               tempA1[r] = temp[r] - '0';
               tempA2[r] = temp[r+4] - '0';
            }


            rowNum = tempA1[0]*1000 + tempA1[1]*100 + tempA1[2]*10 + tempA1[3]*1;
            colNum = tempA2[0]*1000 + tempA2[1]*100 + tempA2[2]*10 + tempA2[3]*1;

            rowdec[cnt] = binToDec(rowNum);
            coldec[cnt] = binToDec(colNum);
            cnt++;

        }
    }

    string m2[16],m3[16]; // Char store of mul2 and mul3

    for(int z=0;z<16;z++)
    {
        m2[z] = mul2[rowdec[z]][coldec[z]];
        m3[z] = mul3[rowdec[z]][coldec[z]];
    }

   string m2bin[16],m3bin[16]; //Binary values of mul2 and mul3

    for(int z=0;z<16;z++)
    {
       for(int t=0;t<2;t++)
        {
            if(m2[z][t] == '0')
                m2bin[z].append("0000");
            if(m2[z][t] == '1')
                m2bin[z].append("0001");
            if(m2[z][t] == '2')
                m2bin[z].append("0010");
            if(m2[z][t] == '3')
                m2bin[z].append("0011");
            if(m2[z][t] == '4')
                m2bin[z].append("0100");
            if(m2[z][t] == '5')
                m2bin[z].append("0101");
            if(m2[z][t] == '6')
                m2bin[z].append("0110");
            if(m2[z][t] == '7')
                m2bin[z].append("0111");
            if(m2[z][t] == '8')
                m2bin[z].append("1000");
            if(m2[z][t] == '9')
                m2bin[z].append("1001");
            if(m2[z][t] == 'A')
                m2bin[z].append("1010");
            if(m2[z][t] == 'B')
                m2bin[z].append("1011");
            if(m2[z][t] == 'C')
                m2bin[z].append("1100");
            if(m2[z][t] == 'D')
                m2bin[z].append("1101");
            if(m2[z][t] == 'E')
                m2bin[z].append("1110");
            if(m2[z][t] == 'F')
                m2bin[z].append("1111");

        }
    }

    for(int z=0;z<16;z++)
    {
       for(int t=0;t<2;t++)
        {
            if(m3[z][t] == '0')
                m3bin[z].append("0000");
            if(m3[z][t] == '1')
                m3bin[z].append("0001");
            if(m3[z][t] == '2')
                m3bin[z].append("0010");
            if(m3[z][t] == '3')
                m3bin[z].append("0011");
            if(m3[z][t] == '4')
                m3bin[z].append("0100");
            if(m3[z][t] == '5')
                m3bin[z].append("0101");
            if(m3[z][t] == '6')
                m3bin[z].append("0110");
            if(m3[z][t] == '7')
                m3bin[z].append("0111");
            if(m3[z][t] == '8')
                m3bin[z].append("1000");
            if(m3[z][t] == '9')
                m3bin[z].append("1001");
            if(m3[z][t] == 'A')
                m3bin[z].append("1010");
            if(m3[z][t] == 'B')
                m3bin[z].append("1011");
            if(m3[z][t] == 'C')
                m3bin[z].append("1100");
            if(m3[z][t] == 'D')
                m3bin[z].append("1101");
            if(m3[z][t] == 'E')
                m3bin[z].append("1110");
            if(m3[z][t] == 'F')
                m3bin[z].append("1111");
        }
    }

    int t1[8],t2[8],t3[8],t4[8];
    int res[16][8];

    for(int z=0;z<8;z++)   //Element 0
    {
        t1[z] = m2bin[0][z] - '0';
        t2[z] = m3bin[1][z] - '0';
        t3[z] = statemat[2][0][z] - '0';
        t4[z] = statemat[3][0][z] - '0';

        res[0][z] = t1[z] ^ t2[z] ^ t3[z] ^ t4[z] ;
    }

    for(int z=0;z<8;z++)  //Element 1
    {
        t1[z] = statemat[0][0][z] - '0';
        t2[z] = m2bin[1][z] - '0';
        t3[z] = m3bin[2][z] - '0';
        t4[z] = statemat[3][0][z] - '0';

        res[1][z] = t1[z] ^ t2[z] ^ t3[z] ^ t4[z] ;
    }

    for(int z=0;z<8;z++)  //E2
    {
        t1[z] = statemat[0][0][z] - '0';
        t2[z] = statemat[1][0][z] - '0';
        t3[z] = m2bin[2][z] - '0';
        t4[z] = m3bin[3][z] - '0';

        res[2][z] = t1[z] ^ t2[z] ^ t3[z] ^ t4[z] ;
    }

     for(int z=0;z<8;z++)  //E3
    {
        t1[z] = m3bin[0][z] - '0';
        t2[z] = statemat[1][0][z] - '0';
        t3[z] = statemat[2][0][z] - '0';
        t4[z] = m2bin[3][z] - '0';

        res[3][z] = t1[z] ^ t2[z] ^ t3[z] ^ t4[z] ;
    }



    //Ele 4 to 7
    for(int z=0;z<8;z++)   //Element 4
    {
        t1[z] = m2bin[4][z] - '0';
        t2[z] = m3bin[5][z] - '0';
        t3[z] = statemat[2][1][z] - '0';
        t4[z] = statemat[3][1][z] - '0';

        res[4][z] = t1[z] ^ t2[z] ^ t3[z] ^ t4[z] ;
    }

    for(int z=0;z<8;z++)  //Element 5
    {
        t1[z] = statemat[0][1][z] - '0';
        t2[z] = m2bin[5][z] - '0';
        t3[z] = m3bin[6][z] - '0';
        t4[z] = statemat[3][1][z] - '0';

        res[5][z] = t1[z] ^ t2[z] ^ t3[z] ^ t4[z] ;
    }

    for(int z=0;z<8;z++)  //E6
    {
        t1[z] = statemat[0][1][z] - '0';
        t2[z] = statemat[1][1][z] - '0';
        t3[z] = m2bin[6][z] - '0';
        t4[z] = m3bin[7][z] - '0';

        res[6][z] = t1[z] ^ t2[z] ^ t3[z] ^ t4[z] ;
    }

     for(int z=0;z<8;z++)  //E7
    {
        t1[z] = m3bin[4][z] - '0';
        t2[z] = statemat[1][1][z] - '0';
        t3[z] = statemat[2][1][z] - '0';
        t4[z] = m2bin[7][z] - '0';

        res[7][z] = t1[z] ^ t2[z] ^ t3[z] ^ t4[z] ;
    }


    //Ele 8-11

    for(int z=0;z<8;z++)   //Element 8
    {
        t1[z] = m2bin[8][z] - '0';
        t2[z] = m3bin[9][z] - '0';
        t3[z] = statemat[2][2][z] - '0';
        t4[z] = statemat[3][2][z] - '0';

        res[8][z] = t1[z] ^ t2[z] ^ t3[z] ^ t4[z] ;
    }

    for(int z=0;z<8;z++)  //Element 9
    {
        t1[z] = statemat[0][2][z] - '0';
        t2[z] = m2bin[9][z] - '0';
        t3[z] = m3bin[10][z] - '0';
        t4[z] = statemat[3][2][z] - '0';

        res[9][z] = t1[z] ^ t2[z] ^ t3[z] ^ t4[z] ;
    }

    for(int z=0;z<8;z++)  //E10
    {
        t1[z] = statemat[0][2][z] - '0';
        t2[z] = statemat[1][2][z] - '0';
        t3[z] = m2bin[10][z] - '0';
        t4[z] = m3bin[11][z] - '0';

        res[10][z] = t1[z] ^ t2[z] ^ t3[z] ^ t4[z] ;
    }

     for(int z=0;z<8;z++)  //E11
    {
        t1[z] = m3bin[8][z] - '0';
        t2[z] = statemat[1][2][z] - '0';
        t3[z] = statemat[2][2][z] - '0';
        t4[z] = m2bin[11][z] - '0';

        res[11][z] = t1[z] ^ t2[z] ^ t3[z] ^ t4[z] ;
    }

    //ELe 12-15

    for(int z=0;z<8;z++)   //Element 12
    {
        t1[z] = m2bin[12][z] - '0';
        t2[z] = m3bin[13][z] - '0';
        t3[z] = statemat[2][3][z] - '0';
        t4[z] = statemat[3][3][z] - '0';

        res[12][z] = t1[z] ^ t2[z] ^ t3[z] ^ t4[z] ;
    }

    for(int z=0;z<8;z++)  //Element 13
    {
        t1[z] = statemat[0][3][z] - '0';
        t2[z] = m2bin[13][z] - '0';
        t3[z] = m3bin[14][z] - '0';
        t4[z] = statemat[3][3][z] - '0';

        res[13][z] = t1[z] ^ t2[z] ^ t3[z] ^ t4[z] ;
    }

    for(int z=0;z<8;z++)  //E14
    {
        t1[z] = statemat[0][3][z] - '0';
        t2[z] = statemat[1][3][z] - '0';
        t3[z] = m2bin[14][z] - '0';
        t4[z] = m3bin[15][z] - '0';

        res[14][z] = t1[z] ^ t2[z] ^ t3[z] ^ t4[z] ;
    }

     for(int z=0;z<8;z++)  //E15
    {
        t1[z] = m3bin[12][z] - '0';
        t2[z] = statemat[1][3][z] - '0';
        t3[z] = statemat[2][3][z] - '0';
        t4[z] = m2bin[15][z] - '0';

        res[15][z] = t1[z] ^ t2[z] ^ t3[z] ^ t4[z] ;
    }

    string tempres[16];

    for(int t=0;t<16;t++)
    {
        for(int z=0;z<8;z++)
            tempres[t].push_back(res[t][z] + '0');

    }

    cnt =0;
    for(int p=0;p<4;p++)
    {
        for(int q=0;q<4;q++)
        {
            statemat[q][p] = tempres[cnt];
            cnt++;
        }
    }
    }
    //Add Round KEY


    cnt = 0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            string temp ;
            for(int z=0;z<8;z++)
                {
                    temp.push_back(round[roundCnt][cnt+z] + '0');    //Change RoundNo KEy HERE --------------------------------------->

                }
               // temp.push_back(' ');
            cnt+=8;
            key[j][i] = temp;

       }
    }

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            string temp1 = statemat[i][j];
            string temp2 = key[i][j];
            string result;

            int tempA1[8],tempA2[8],tempresult[8];

            for(int z=0;z<8;z++)
            {
                tempA1[z] = temp1[z] - '0';
                tempA2[z] = temp2[z] - '0';
                tempresult[z] = tempA1[z] ^ tempA2[z];
                result.push_back(tempresult[z] + '0');
            }
            statemat[i][j] = result;
        }
    }


        roundCnt++;

}



    string ciphertext;
    int p=0,q=0;
    for(int p=0;p<4;p++)
    {
        for(int q=0;q<4;q++)
        {
            int i=0;

            //cout << statemat[q][p][3];

            for(i=0;i<8;i+=4)
            {
                int temp = (statemat[q][p][i]-'0')*8 + (statemat[q][p][i+1]-'0')*4 +(statemat[q][p][i+2]-'0')*2 + (statemat[q][p][i+3]-'0')*1;


                if(temp<=9)
                   ciphertext.push_back(temp + '0');

                else
                {
                    if(temp == 10)
                   ciphertext.push_back('A');
                    if(temp == 11)
                   ciphertext.push_back('B');
                    if(temp == 12)
                   ciphertext.push_back('C');
                    if(temp == 13)
                   ciphertext.push_back('D');
                    if(temp == 14)
                   ciphertext.push_back('E');
                    if(temp == 15)
                   ciphertext.push_back('F');

                }

            }


        }
    }


    for(int z=1;z<11;z++)
    {
        for(int p=0;p<32;p++)
            cout << roundKey[z][p];

        cout << endl;

    }


    cout << ciphertext;


    return 0;
}
