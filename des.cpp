#include "des.h"



/* the file input needs to be changed so it can read hex input */

using namespace std;
string HexToBin(char s)
{
	string bin = "";
	
		switch (s)
		{
		case '0':
			bin += "0000";
			break;
		case '1':
			bin += "0001";
			break;
		case '2':
			bin += "0010";
			break;
		case '3':
			bin += "0011";
			break;
		case '4':
			bin += "0100";
			break;
		case '5':
			bin += "0101";
			break;
		case '6':
			bin += "0110";
			break;
		case '7':
			bin += "0111";
			break;
		case '8':
			bin += "1000";
			break;
		case '9':
			bin += "1001";
			break;
		case 'A':
		case 'a':
			bin += "1010";
			break;
		case 'B':
		case 'b':
			bin += "1011";
			break;
		case 'C':
		case 'c':
			bin += "1100";
			break;
		case 'D':
		case 'd':
			bin += "1101";
			break;
		case 'E':
		case 'e':
			bin += "1110";
			break;
		case 'F':
		case 'f':
			bin += "1111";
			break;
		}
	return bin;
}


// every module or block should be an function
// initial permutation hopefully done
bitset<64> intialPermutation(bitset<64>plainText){
		//  Initial Permutation (IP)
	const int IP_t[64] = {58, 50, 42, 34, 26, 18, 10, 2, // intital permutation table
						  60, 52, 44, 36, 28, 20, 12, 4,
						  62, 54, 46, 38, 30, 22, 14, 6,
						  64, 56, 48, 40, 32, 24, 16, 8,
						  57, 49, 41, 33, 25, 17, 9, 1,
						  59, 51, 43, 35, 27, 19, 11, 3,
						  61, 53, 45, 37, 29, 21, 13, 5,
						  63, 55, 47, 39, 31, 23, 15, 7};
	string s="";
	for(int i=0;i<64;i++){
		s+="0";
	}
	bitset<64> result(s);
	// for debugging
/* 			cout<<(plainText<<(64-10))<<endl;
			cout<<((plainText<<(64-10))>>63)<<endl;
			cout<<(((plainText<<(64-10))>>63)<<7-1)<<endl; */

	for(int i=0;i<64;i++){
		result = result|(((plainText<<(64-IP_t[i]))>>63)<<((i==0)? i:i-1));
	}
	return result;
}

// void expansion(bitset<64> *rightText){


// }

// bitset<64> plaintext,bitset<64>key
void round(bitset<64> plaintext,bitset<64>key){
	// initial split
	string ones ="", zeros ="";
	for(int i=0;i<64/2;i++){
		ones+="1";
		zeros+="0";
	}
	string right=zeros+ones;
	string left =ones+zeros;
	bitset<64> leftText(left);
	bitset<64> rightText(left);
	cout<<leftText<<"    "<<right<<endl;
	leftText = plaintext|leftText;
	rightText = plaintext|rightText;


	// f is the input of the xor
	// rightText = leftText^F;
	// leftText = rightText

}

int main()
{
	// round();
	// this values are for debugging
	/* "0000000000000000000000000000000000000000000000000000000000000010"	2
	"0000001000000000000000000000000000000000000000000000000000000000"	58
	"0000000000000000000000000000000000000000000000000000001000000000"	10
	string z = "0000001000000000000000000000000000000000000000000000000000000000";
	cout<<z.size()<<endl<<z.find("1")<<endl;
	bitset<64> s("0000001000000000000000000000000000000000000000000000000000000000");
	cout<<s<<endl;
	cout<<intialPermutation(s); */

	ifstream read;
	read.open("trial.txt");
	ofstream write;
	write.open("binary.txt");
	string x;
	// writing biary
	string bin="";
	while (getline(read, x))
	{
		for (int i = 0; i < x.size(); i++)
		{
			bin = HexToBin(x[i]);
			cout<<bin;
	 	if (i %16  == 0 && i > 0)
			{
				write << "\n";
				bin = "";
			}
		// 	// write string rep in file
		// 	// write<<decToBinary(let);
		// 	// write binary rep in file
		// 	bitset<8> bset(decToBinary(let));
			write << bin;
		}
	}
	read.close();
	write.close();
	read.open("binary.txt");
	write.open("cypher.txt");
	while (getline(read, x))
	{
		write << x << endl;
	}
	return 0;
}