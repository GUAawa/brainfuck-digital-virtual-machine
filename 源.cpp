#include<iostream>
#include<stdio.h>
using namespace std;

unsigned char IAR = 0;
unsigned char MAR = 0;
unsigned char InsROM[256] = "+++++++[->+++++++<]>.+.+.";
unsigned char DtRAM[256];
unsigned char INS() {
	return InsROM[IAR];
}
unsigned char DATA() {
	return DtRAM[MAR];
}
void INSi() {
	InsROM[IAR]++;
}
void DATAi() {
	DtRAM[MAR]++;
}
void INSd() {
	InsROM[IAR]--;
}
void DATAd() {
	DtRAM[MAR]--;
}
void INSs(unsigned char v) {
	InsROM[IAR] = v;
}
void DATAs(unsigned char v) {
	DtRAM[MAR] = v;
}
char JP = 0;
bool halt = false;

/*
<>+-,.[]
01234567
+++++++[->+++++++<]>.+.+.
2222222631222222207152525

*/

int main() {
	while (!halt) {
		if (JP == 0 && DATA() == 0 && INS() == '[') { JP++;  IAR++; } //0
		else if (JP == 0 && DATA() != 0 && INS() == '[') { JP;  IAR++; } //1
		else if (JP == -1 && INS() == '[') { JP++; IAR; } //2
		else if (JP == 0 && INS() == ']') { JP--; IAR--; } //3
		else if (JP != 0) { //4{}
			int dI;
			int dJ;
			if (JP > 0) dI = 1;//
			else if (JP < 0) dI = -1;//
			if (INS() == '[') dJ = 1;//
			else if (INS() == ']') dJ = -1;//
			else dJ = 0;
			IAR += dI;
			JP += dJ;
		}
		else {
			switch (INS()) {
			case '<': //5{}
				if (MAR == 0) {//
					halt = true;
				}
				//
				MAR--;
				IAR++;
				break;
			case '>': //6
				MAR++;
				IAR++;
				break;
			case '+': //7
				DATAi();
				IAR++;
				break;
			case '-': //8
				DATAd();
				IAR++;
				break;
			case ',': //9
				unsigned char v;
				scanf("%c", &v);
				DATAs(v);
				IAR++;
				break;
			case '.': //a
				printf("%c ", (DATA()));
				IAR++;
				break;
			default:
				return 0;
			}
		}
	}

	return 0;
}