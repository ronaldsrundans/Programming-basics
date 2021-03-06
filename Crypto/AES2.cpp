
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
int ip[64] = { 58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,
62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,
57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,
61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7 };
int kp[64] = { 57,49,41,33,25,17,9,1,58,50,42,34,26,18,
10,2,59,51,43,35,27,19,11,3,60,52,44,36,
63,55,47,39,31,23,15,7,62,54,46,38,30,22,
14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
int bsh[16] = { 1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };
int debsh[16] = { 0,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };
int cp[48] = { 14,17,11,24,1,5,3,28,15,6,21,10,
23,19,12,4,26,8,16,7,27,20,13,2,
41,52,31,37,47,55,30,40,51,45,33,48,
44,49,39,56,34,53,46,42,50,36,29,32 };
int ep[48] = { 32,1,2,3,4,5,4,5,6,7,8,9,
8,9,10,11,12,13,12,13,14,15,16,17,
16,17,18,19,20,21,20,21,22,23,24,25,
24,25,26,27,28,29,28,29,30,31,32,1 };

int fp[64] = { 40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,
38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,
36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,
34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25 };

int sbox1[4][16] = { { 14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7 },
{ 0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8 },
{ 4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0 },
{ 15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13 } };

int sbox2[4][16] = { { 15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10 },
{ 3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5 },
{ 0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15 },
{ 13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9 } };

int sbox3[4][16] = { { 10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8 },
{ 13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1 },
{ 13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7 },
{ 1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12 } };

int sbox4[4][16] = { { 7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15 },
{ 13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9 },
{ 10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4 },
{ 3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14 } };

int sbox5[4][16] = { { 2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9 },
{ 14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6 },
{ 4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14 },
{ 11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3 } };

int sbox6[4][16] = { { 12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11 },
{ 10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8 },
{ 9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6 },
{ 4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13 } };

int sbox7[4][16] = { { 4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1 },
{ 13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6 },
{ 1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2 },
{ 6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12 } };

int sbox8[4][16] = { { 13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7 },
{ 1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2 },
{ 7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8 },
{ 2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11 } };

int pbox[32] = { 16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,
2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25 };

void shift(int* arr, int n)
{
	int tmp1, tmp2, tmp3;
	tmp1 = arr[0];
	tmp2 = arr[1];
	tmp3 = arr[27];
	for (int k = 0; k<26; k++)
	{
		arr[k] = arr[k + n];
	}
	if (n == 2)
	{
		arr[26] = tmp1;
		arr[27] = tmp2;
	}
	else if (n == 1)
	{
		arr[27] = tmp1;
		arr[26] = tmp3;
	}
}
void deshift(int* arr, int n)
{
	int tmp1, tmp2, tmp3;
	tmp1 = arr[0];
	tmp2 = arr[26];
	tmp3 = arr[27];
	//tmp4=arr[1];
	for (int k = 25; k >= 0; k--)
	{
		arr[k + n] = arr[k];
	}
	if (n == 2)
	{
		arr[0] = tmp2;
		arr[1] = tmp3;
	}
	else if (n == 1)
	{
		arr[27] = tmp2;
		arr[0] = tmp3;
	}
}
void xorfunc(int *arr1, int *arr2, int* arr3, int n)
{
	for (int i = 0; i<n; i++)
	{
		if (((arr1[i] == 1)||(arr2[i] == 1)) && (arr1[i] != arr2[i]))
		{
			arr3[i] = 1;
		}
		else
		{
			arr3[i] = 0;
		}
	}
}

void permutation(int n, int* arr1, int *arr2, int *arrp)
{
	int tmp;
	for (int i = 0; i<n; i++)
	{
		arr2[i] = arr1[arrp[i] - 1];
	}
}
void desdectobin(int dec, int* bin)
{
	int tmp = dec;
	for (int i = 3; i >= 0; i--)
	{
		bin[i] = tmp % 2;
		tmp = tmp / 2;
	}
}
void split(int *arr, int* arr1, int *arr2, int n)
{
	for (int i = 0; i<n; i++)
	{
		arr1[i] = arr[i];
		arr2[i] = arr[i + n];
	}
}


void hextobin(char* hex, int hexcount, int *arr)
{
	int n, k, i;
	for (k = 0; k<hexcount; k++)
	{
		n = (int)hex[k];
		if (n >= 'a')
		{
			n = n - 'a' + 10;
		}
		else
		{
			n = n - '0';
		}
		for (i = 3; i >= 0; i--)
		{
			arr[i + k * 4] = n % 2;
			n = n / 2;
		}
	}
}
void bintohex(int *bin, int binsize)//,char* hex)
{
	int n = 0;
	int k = 1;
	int i;
	char c;
	for (i = binsize - 1; i >= 0; i--)
	{
		n = n + bin[i] * k;
		k = k * 2;
	}
	c = n + '0';
	if (c>'9')
	{
		c = c - '0' - 10 + 'a';
	}
	cout << c;
}
void xorfunc(int arr1[][4], int ** arr2, int arr3[][4], int n, int col)
{
	for (int i = 0; i<n; i++)
	{
		if (((arr1[i][col] == 1)||(arr2[i][col] == 1)) && (arr1[i][col] != arr2[i][col]))
		{
			arr3[i][col] = 1;
		}
		else
		{
			arr3[i][col] = 0;
		}
	}
}
void copyState(int state[][4], int nk, char* plain)
{
	int arrt[4];
	int k, i, j, n, l;//=1;
	char c;
	for (i = 0; i<nk; i++)
	{
		for (j = 0; j<8; j++)
		{
			for (int k = 0; k<4; k++)
			{
				arrt[k] = state[j * 4 + k][i];
			}
			n = 0;
			k = 1;
			for (l = 4 - 1; l >= 0; l--)
			{
				n = n + arrt[l] * k;
				k = k * 2;
			}
			c = n + '0';
			if (c>'9')
			{
				c = c - '0' - 10 + 'a';
			}
			plain[i * 8 + j] = c;
		}
	}
}
void copyDES(char* plain, int *des)
{
	int arrt[4];
	int k, i, n, l;//=1;
	char c;
	for (i = 0; i<16; i++)
	{
		// for(j=0;j<8;j++)
		//{
		for (k = 0; k<4; k++)
		{
			arrt[k] = des[i * 4 + k];
		}
		n = 0;
		k = 1;
		for (l = 3; l >= 0; l--)
		{
			n = n + arrt[l] * k;
			k = k * 2;
		}
		c = n + '0';
		if (c>'9')
		{
			c = c - '0' - 10 + 'a';
		}
		plain[i] = c;
	}
	// }

}
void printState(int state[][4], int nk)
{
	for (int i = 0; i<nk; i++)
	{
		int arrt[4];
		for (int j = 0; j<8; j++)
		{
			for (int k = 0; k<4; k++)
			{
				arrt[k] = state[j * 4 + k][i];
			}
			bintohex(arrt, 4);
		}
	}
	cout << endl;
}
void printKey(int **state, int nk)
{
	int i, j, k;
	for (i = 0; i<nk; i++)
	{
		int arrt[4];
		for (j = 0; j<8; j++)
		{
			for (k = 0; k<4; k++)
			{
				arrt[k] = state[j * 4 + k][i];
			}
			bintohex(arrt, 4);
		}
	}
	cout << endl;
}
void printRow(int *arr)
{
	cout << "PrintRow=";
	int arrt[4];
	int k, j;
	for (j = 0; j<8; j++)
	{
		for (k = 0; k<4; k++)
		{
			arrt[k] = arr[k + j * 4];
		}
		bintohex(arrt, 4);
	}
	cout << endl;
}
void xorfunc8(int *arr1, int *arr2, int *arr3)
{
	for (int i = 0; i<8; i++)
	{
		if (((arr1[i] == 1)||(arr2[i] == 1)) && (arr1[i] != arr2[i]))
		{
			arr3[i] = 1;
		}
		else
		{
			arr3[i] = 0;
		}
	}
}
void xorfuncN(int *arr1, int *arr2, int *arr3, int n)
{
	for (int i = 0; i<n; i++)
	{
		if (((arr1[i] == 1)||(arr2[i] == 1)) && (arr1[i] != arr2[i]))
		{
			arr3[i] = 1;
		}
		else
		{
			arr3[i] = 0;
		}
	}
}
void bintodec(int arr[], int j)
{
	int n = 0;
	int b = 1;
	for (int i = j; i >= 0; i--)
	{
		n = n + b*arr[i];
		b = b * 2;
		arr[i] = 0;
	}
	arr[0] = n;
}
void dectobin(int a, int *arr)
{
	int n = a;
	for (int i = 7; i >= 0; i--)
	{
		arr[i] = n % 2;
		n = n / 2;
	}
}
void subbytes(int sbox[][16], int input[][4])
{
	int x, y, i, j, k;
	int arr1[4];
	int arr2[4];
	for (j = 0; j<4; j++)///col
	{
		for (i = 0; i<4; i++)///row
		{
			x = 0;
			y = 0;
			for (k = 0; k<4; k++)///x and y
			{
				arr1[k] = input[k + i * 8][j];
				arr2[k] = input[k + 4 + i * 8][j];
			}
			bintodec(arr1, 3);
			bintodec(arr2, 3);
			x = arr1[0];
			y = arr2[0];
			for (k = 0; k<4; k++)///x and y
			{
				input[k + i * 8][j] = sbox[y * 8 + k][x];
				input[k + 4 + i * 8][j] = sbox[y * 8 + k + 4][x];
			}
		}
	}
}
void subRow(int *arr, int sbox[][16])
{
	int arrx[4];
	int arry[4];
	int i, j, x, y, k;
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			arrx[j] = arr[j + i * 8];
			arry[j] = arr[j + 4 + i * 8];
		}
		bintodec(arrx, 3);
		bintodec(arry, 3);
		x = arrx[0];
		y = arry[0];
		for (k = 0; k<4; k++)///x and y
		{
			arr[k + i * 8] = sbox[y * 8 + k][x];
			arr[k + 4 + i * 8] = sbox[y * 8 + k + 4][x];
		}
	}
}
void binsumarr(int *arr1, int *arr2, int *arr3)
{
	bintodec(arr1, 7);
	bintodec(arr2, 7);
	int n1 = arr1[0];
	int n2 = arr2[0];
	int n3;
	n3 = n1 + n2;
	if (n3>255)
	{
		n3 = n3 - 255;
	}
	dectobin(n3, arr3);
}
void printTable(int sbox[][16])
{
	int i, j, k;
	for (j = 0; j<16; j++)///col
	{
		int arrt[4];
		for (i = 0; i<16; i++)///row
		{
			for (k = 0; k<4; k++)
			{
				arrt[k] = sbox[i * 8 + k][j];
			}
			bintohex(arrt, 4);
			for (k = 4; k<8; k++)
			{
				arrt[k - 4] = sbox[i * 8 + k][j];
			}
			bintohex(arrt, 4);
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void shiftrows(int arr[][4])
{
	int tmp[48];
	int i, j;
	for (i = 0; i<8; i++)///row1 copy
	{
		tmp[i] = arr[i + 8][0];
	}
	for (j = 0; j<3; j++)///row1 shift
	{
		for (i = 0; i<8; i++)
		{
			arr[i + 8][j] = arr[i + 8][j + 1];
		}
	}
	for (i = 0; i<8; i++)///row1 paste
	{
		arr[i + 8][3] = tmp[i];
	}

	for (j = 0; j<2; j++)///row2 copy
	{
		for (i = 0; i<8; i++)
		{
			tmp[i + j * 8 + 8] = arr[i + 16][j];
		}
	}
	for (j = 0; j<2; j++)///row2 shift
	{
		for (i = 0; i<8; i++)
		{
			arr[i + 16][j] = arr[i + 16][j + 2];
		}
	}
	for (j = 2; j<4; j++)///row2 paste
	{
		for (i = 0; i<8; i++)
		{
			arr[i + 16][j] = tmp[i + j * 8 - 8];
		}
	}
	for (j = 0; j<3; j++)///row 3 copy
	{
		for (i = 0; i<8; i++)
		{
			tmp[i + 24 + 8 * j] = arr[i + 24][j];
		}
	}
	///row 3 shift

	for (i = 0; i<8; i++)
	{
		arr[i + 24][0] = arr[i + 24][3];
	}

	for (j = 1; j<4; j++)///row 3 paste
	{
		for (i = 0; i<8; i++)
		{
			arr[i + 24][j] = tmp[i + 16 + j * 8];
		}
	}
}
void invshiftrows(int arr[][4])
{
	int tmp[48];
	int i, j;
	for (i = 0; i<8; i++)///row1 copy
	{
		tmp[i] = arr[i + 8][3];
	}
	for (j = 3; j>0; j--)///row1 shift
	{
		for (i = 0; i<8; i++)
		{
			arr[i + 8][j] = arr[i + 8][j - 1];
		}
	}
	for (i = 0; i<8; i++)///row1 paste
	{
		arr[i + 8][0] = tmp[i];
	}
	for (j = 2; j<4; j++)///row2 copy
	{
		for (i = 0; i<8; i++)
		{
			tmp[i + j * 8 - 8] = arr[i + 16][j];
		}
	}
	for (j = 3; j>1; j--)///row2 shift
	{
		for (i = 0; i<8; i++)
		{
			arr[i + 16][j] = arr[i + 16][j - 2];
		}
	}
	for (j = 0; j<2; j++)///row2 paste
	{
		for (i = 0; i<8; i++)
		{
			arr[i + 16][j] = tmp[i + j * 8 + 8];
		}
	}
	for (j = 1; j<4; j++)///row 3 copy
	{
		for (i = 0; i<8; i++)
		{
			tmp[i + 16 + 8 * j] = arr[i + 24][j];
		}
	}
	///row 3 shift

	for (i = 0; i<8; i++)
	{
		arr[i + 24][3] = arr[i + 24][0];
	}
	for (j = 0; j<3; j++)///row 3 paste
	{
		for (i = 0; i<8; i++)
		{
			arr[i + 24][j] = tmp[i + 24 + j * 8];
		}
	}
}
void multiply(int tableL[][16], int tableE[][16], int *arr1, int *arr2, int*arr3)
{
	int i, x1, y1, x2, y2, x3, y3;
	int arr10[4];
	int arr11[4];
	int arr20[4];
	int arr21[4];
	int arr18[8];
	int arr28[8];
	int arrrez[8];
	for (i = 0; i<4; i++)
	{
		arr10[i] = arr1[i];
		arr11[i] = arr1[i + 4];
		arr20[i] = arr2[i];
		arr21[i] = arr2[i + 4];
	}
	bintodec(arr10, 3);
	bintodec(arr11, 3);
	bintodec(arr20, 3);
	bintodec(arr21, 3);
	x1 = arr10[0];
	y1 = arr11[0];
	x2 = arr20[0];
	y2 = arr21[0];
	if (x2 == 0 && y2 == 0)
	{
		for (i = 0; i<8; i++)
		{
			arr3[i] = 0;
		}
	}
	else
	{
		for (i = 0; i<8; i++)
		{
			arr18[i] = tableL[8 * y1 + i][x1];///asis ir otradi
			arr28[i] = tableL[8 * y2 + i][x2];
		}
		binsumarr(arr18, arr28, arrrez);
		for (i = 3; i >= 0; i--)
		{
			arr10[i] = arrrez[i];
			arr11[i] = arrrez[i + 4];
		}
		bintodec(arr10, 3);
		bintodec(arr11, 3);
		x3 = arr10[0];
		y3 = arr11[0];
		for (i = 0; i<8; i++)
		{
			arr3[i] = tableE[8 * y3 + i][x3];
		}
	}
}
void mixcol(int tableL[][16], int tableE[][16], int input[][4])
{
	char hex1[] = "01";
	char hex2[] = "02";
	char hex3[] = "03";
	int arr01[8];
	int arr02[8];
	int arr03[8];
	hextobin(hex1, 2, arr01);
	hextobin(hex2, 2, arr02);
	hextobin(hex3, 2, arr03);
	int a1[8];
	int a2[8];
	int a3[8];
	int a4[8];
	int r11[8];
	int r12[8];
	int r13[8];
	int r14[8];
	int r21[8];
	int r22[8];
	int r23[8];
	int r24[8];
	int r31[8];
	int r32[8];
	int r33[8];
	int r34[8];
	int r41[8];
	int r42[8];
	int r43[8];
	int r44[8];
	int rx11[8];
	int rx12[8];
	int rx13[8];
	int rx21[8];
	int rx22[8];
	int rx23[8];
	int rx31[8];
	int rx32[8];
	int rx33[8];
	int rx41[8];
	int rx42[8];
	int rx43[8];
	int j, i;
	for (j = 0; j<4; j++)
	{
		for (i = 0; i<8; i++)
		{
			a1[i] = input[i][j];
			a2[i] = input[i + 8][j];
			a3[i] = input[i + 16][j];
			a4[i] = input[i + 24][j];
		}
		///pirma rinda * pirma kolonna
		multiply(tableL, tableE, arr02, a1, r11);
		multiply(tableL, tableE, arr03, a2, r12);
		multiply(tableL, tableE, arr01, a3, r13);
		multiply(tableL, tableE, arr01, a4, r14);
		xorfunc8(r11, r12, rx11);
		xorfunc8(r13, r14, rx12);
		xorfunc8(rx11, rx12, rx13);
		///otra rinda * pirma kolonna
		multiply(tableL, tableE, arr01, a1, r21);
		multiply(tableL, tableE, arr02, a2, r22);
		multiply(tableL, tableE, arr03, a3, r23);
		multiply(tableL, tableE, arr01, a4, r24);
		xorfunc8(r21, r22, rx21);
		xorfunc8(r23, r24, rx22);
		xorfunc8(rx21, rx22, rx23);
		///tresa rinda * pirma kolonna
		multiply(tableL, tableE, arr01, a1, r31);
		multiply(tableL, tableE, arr01, a2, r32);
		multiply(tableL, tableE, arr02, a3, r33);
		multiply(tableL, tableE, arr03, a4, r34);
		xorfunc8(r31, r32, rx31);
		xorfunc8(r33, r34, rx32);
		xorfunc8(rx31, rx32, rx33);
		///ceturta rinda * pirma kolonna
		multiply(tableL, tableE, arr03, a1, r41);
		multiply(tableL, tableE, arr01, a2, r42);
		multiply(tableL, tableE, arr01, a3, r43);
		multiply(tableL, tableE, arr02, a4, r44);
		xorfunc8(r41, r42, rx41);
		xorfunc8(r43, r44, rx42);
		xorfunc8(rx41, rx42, rx43);
		for (i = 0; i<8; i++)
		{
			input[i][j] = rx13[i];
			input[i + 8][j] = rx23[i];
			input[i + 16][j] = rx33[i];
			input[i + 24][j] = rx43[i];
		}
	}
}
void invmixcol(int tableL[][16], int tableE[][16], int input[][4])
{
	char hex1[] = "0e";
	char hex2[] = "0b";
	char hex3[] = "0d";
	char hex4[] = "09";
	int arr0e[8];
	int arr0b[8];
	int arr0d[8];
	int arr09[8];
	hextobin(hex1, 2, arr0e);
	hextobin(hex2, 2, arr0b);
	hextobin(hex3, 2, arr0d);
	hextobin(hex4, 2, arr09);
	int a1[8];
	int a2[8];
	int a3[8];
	int a4[8];
	int r11[8];
	int r12[8];
	int r13[8];
	int r14[8];
	int r21[8];
	int r22[8];
	int r23[8];
	int r24[8];
	int r31[8];
	int r32[8];
	int r33[8];
	int r34[8];
	int r41[8];
	int r42[8];
	int r43[8];
	int r44[8];
	int rx11[8];
	int rx12[8];
	int rx13[8];
	int rx21[8];
	int rx22[8];
	int rx23[8];
	int rx31[8];
	int rx32[8];
	int rx33[8];
	int rx41[8];
	int rx42[8];
	int rx43[8];
	int i, j;
	for (j = 0; j<4; j++)
	{
		for (i = 0; i<8; i++)
		{
			a1[i] = input[i][j];
			a2[i] = input[i + 8][j];
			a3[i] = input[i + 16][j];
			a4[i] = input[i + 24][j];
		}
		///pirma rinda * pirma kolonna
		multiply(tableL, tableE, arr0e, a1, r11);
		multiply(tableL, tableE, arr0b, a2, r12);
		multiply(tableL, tableE, arr0d, a3, r13);
		multiply(tableL, tableE, arr09, a4, r14);
		xorfunc8(r11, r12, rx11);
		xorfunc8(r13, r14, rx12);
		xorfunc8(rx11, rx12, rx13);
		///otra rinda * pirma kolonna
		multiply(tableL, tableE, arr09, a1, r21);
		multiply(tableL, tableE, arr0e, a2, r22);
		multiply(tableL, tableE, arr0b, a3, r23);
		multiply(tableL, tableE, arr0d, a4, r24);
		xorfunc8(r21, r22, rx21);
		xorfunc8(r23, r24, rx22);
		xorfunc8(rx21, rx22, rx23);
		///tresa rinda * pirma kolonna
		multiply(tableL, tableE, arr0d, a1, r31);
		multiply(tableL, tableE, arr09, a2, r32);
		multiply(tableL, tableE, arr0e, a3, r33);
		multiply(tableL, tableE, arr0b, a4, r34);
		xorfunc8(r31, r32, rx31);
		xorfunc8(r33, r34, rx32);
		xorfunc8(rx31, rx32, rx33);
		///ceturta rinda * pirma kolonna
		multiply(tableL, tableE, arr0b, a1, r41);
		multiply(tableL, tableE, arr0d, a2, r42);
		multiply(tableL, tableE, arr09, a3, r43);
		multiply(tableL, tableE, arr0e, a4, r44);
		xorfunc8(r41, r42, rx41);
		xorfunc8(r43, r44, rx42);
		xorfunc8(rx41, rx42, rx43);
		for (i = 0; i<8; i++)
		{
			input[i][j] = rx13[i];
			input[i + 8][j] = rx23[i];
			input[i + 16][j] = rx33[i];
			input[i + 24][j] = rx43[i];
		}
	}
}
void rcon(int n, int *arr)///for 128bit key only
{
	char c16[] = { "01020408102040801b36" };
	char tmp[9];
	int i;
	tmp[0] = c16[n * 2];
	tmp[1] = c16[n * 2 + 1];
	for (i = 2; i<8; i++)
	{
		tmp[i] = '0';
	}
	tmp[i] = 0;
	hextobin(tmp, 8, arr);
}
void rotWord(int *arr, int n)
{
	int arrtmp[8];
	int j;
	for (j = 0; j<8; j++)
	{
		arrtmp[j] = arr[j];
	}
	for (j = 8; j<8 * n; j++)
	{
		arr[j - 8] = arr[j];
	}
	for (j = 0; j<8; j++)
	{
		arr[8 * (n - 1) + j] = arrtmp[j];
	}
}

void tableLelem(int *arr11, int *arr12, int *arr21, int *arr22, int tableL[][16], int *r1, int *r2)
{
	int x1, x2, y1, y2;
	int arr1[8];
	int arr2[8];
	bintodec(arr11, 3);
	bintodec(arr12, 3);
	bintodec(arr21, 3);
	bintodec(arr22, 3);
	x1 = arr11[0];
	y1 = arr12[0];
	x2 = arr21[0];
	y2 = arr22[0];
	cout << x1 << endl;
	cout << x2 << endl;
	cout << y1 << endl;
	cout << y2 << endl;
}
void shiftKey(int **arr, int nk, int rows)
{
	int i, j;
	for (i = 0; i<nk - 1; i++)
	{
		for (j = 0; j<rows; j++)
		{
			arr[j][i] = arr[j][i + 1];
		}
	}

}
///
void cript(char *key16, int keysize, char *plain16)
{
	int i, j, k;
	int s = keysize;///new key size
	int nk = s / 32;
	int nb = 4;
	int idec = 0;
	if (nk == 4)
	{
		idec = 44;
	}
	else if (nk == 6)
	{
		idec = 52;
	}
	else
	{
		idec = 60;
	}
	int rows = 32;
	int *arrk = new int[s];
	int *arrp = new int[nb*rows];
	char sbox16[513] = { "637c777bf26b6fc53001672bfed7ab76ca82c97dfa5947f0add4a2af9ca472c0b7fd9326363ff7cc34a5e5f171d8311504c723c31896059a071280e2eb27b27509832c1a1b6e5aa0523bd6b329e32f8453d100ed20fcb15b6acbbe394a4c58cfd0efaafb434d338545f9027f503c9fa851a3408f929d38f5bcb6da2110fff3d2cd0c13ec5f974417c4a77e3d645d197360814fdc222a908846eeb814de5e0bdbe0323a0a4906245cc2d3ac629195e479e7c8376d8dd54ea96c56f4ea657aae08ba78252e1ca6b4c6e8dd741f4bbd8b8a703eb5664803f60e613557b986c11d9ee1f8981169d98e949b1e87e9ce5528df8ca1890dbfe6426841992d0fb054bb16" };
	char tableE16[513] = { "0103050f113355ff1a2e7296a1f813355fe13848d87395a4f702060a1e2266aae5345ce43759eb266abed97090abe63153f5040c143c44cc4fd168b8d36eb2cd4cd467a9e03b4dd762a6f10818287888839eb9d06bbddc7f8198b3ce49db769ab5c457f9103050f00b1d2769bbd661a3fe192b7d8792adec2f7193aee92060a0fb163a4ed26db7c25de73256fa153f41c35ee23d47c940c05bed2c749cbfda759fbad564acef2a7e829dbcdf7a8e89809bb6c158e82365afea256fb1c843c554fc1f2163a5f407091b2d7799b0cb46ca45cf4ade798b8691a8e33e42c651f30e12365aee297b8d8c8f8a8594a7f20d17394bdd7c8497a2fd1c246cb4c752f601" };
	char tableL16[513] = { "0000190132021ac64bc71b6833eedf036404e00e348d81ef4c7108c8f8691cc17dc21db5f9b9276a4de4a6729ac90978652f8a05210fe12412f082453593da8e968fdbbd36d0ce94135cd2f14046833866ddfd30bf068b62b325e298228891107e6e48c3a3b61e423a6b2854fa853dba2b790a159b9f5eca4ed4ace5f373a757af58a850f4ead6744faee9d5e7e6ade82cd7757aeb160bf559cb5fb09ca951a07f0cf66f17c449ecd8431f2da4767bb7ccbb3e5afb60b1863b52a16caa55299d97b2879061bedcfcbc95cfcd373f5bd15339843c41a26d47142a9e5d56f2d3ab441192d923202e89b47cb8267799e3a5674aeddec531fe180d638c80c0f77007" };
	char invsbox16[513] = { "52096ad53036a538bf40a39e81f3d7fb7ce339829b2fff87348e4344c4dee9cb547b9432a6c2233dee4c950b42fac34e082ea16628d924b2765ba2496d8bd12572f8f66486689816d4a45ccc5d65b6926c704850fdedb9da5e154657a78d9d8490d8ab008cbcd30af7e45805b8b34506d02c1e8fca3f0f02c1afbd0301138a6b3a9111414f67dcea97f2cfcef0b4e67396ac7422e7ad3585e2f937e81c75df6e47f11a711d29c5896fb7620eaa18be1bfc563e4bc6d279209adbc0fe78cd5af41fdda8338807c731b11210592780ec5f60517fa919b54a0d2de57a9f93c99cefa0e03b4dae2af5b0c8ebbb3c83539961172b047eba77d626e169146355210c7d" };
	int tableE2[2048];
	int tableL2[2048];
	int sbox2[2048];
	int invsbox2[2048];
	int tableE[128][16];
	int tableL[128][16];
	int sbox[128][16];
	int invsbox[128][16];
	int col = 0;
	int keyfirst[32];
	int keylast[32];
	int arrRcon[32];
	int tmpstate[32];
	hextobin(sbox16, 512, sbox2);
	hextobin(invsbox16, 512, invsbox2);
	hextobin(tableE16, 512, tableE2);
	hextobin(tableL16, 512, tableL2);
	hextobin(key16, nk * 8, arrk);
	hextobin(plain16, rows, arrp);
	for (j = 0; j<16; j++)
	{
		for (i = 0; i<128; i++)
		{
			sbox[i][j] = sbox2[i + j * 128];
			invsbox[i][j] = invsbox2[i + j * 128];
			tableE[i][j] = tableE2[i + j * 128];
			tableL[i][j] = tableL2[i + j * 128];
		}
	}
	int plain2d[32][4];
	int state[32][4];
	int state2[32][4];
	int **keyw = new int*[rows];
	for (i = 0; i<rows; i++)
	{
		keyw[i] = new int[nk];
	}
	for (int i = 0; i<nk; i++)
	{
		for (j = 0; j<rows; j++)
		{
			keyw[j][i] = arrk[j + i*rows];
		}
	}
	for (i = 0; i<nb; i++)
	{
		for (j = 0; j<rows; j++)
		{
			state[j][i] = arrp[j + i*rows];
		}
	}
	delete[]arrp;
	///plain izdruka
	//  cout<<"Check Plain:"<<endl;
	//   printState(state,nb);
	///keyw izdruka
	// cout<<"Check keyw:"<<endl;
	//   printKey(keyw,nb);

	for (k = 0; k<idec; k++)
	{
		///state manip
		if (k>0 && k%nb == 0)
		{
			subbytes(sbox, state);
			shiftrows(state);
			///dont mix last manip
			if (k != idec - nb)
			{
				mixcol(tableL, tableE, state);
			}
		}
		///copy
		for (i = 0; i<rows; i++)
		{
			keyfirst[i] = keyw[i][0];
			keylast[i] = keyw[i][nk - 1];
			tmpstate[i] = state[i][col];
		}
		///update rcon
		rcon(k / nk, arrRcon);
		///key manip
		if (k%nk == 0)
		{
			rotWord(keylast, nb);
			subRow(keylast, sbox);
			xorfuncN(arrRcon, keylast, keylast, rows);
		}
		///for 256 key only
		if (nk == 8)
		{
			if (k<idec - nb)
			{
				if (k % 8 != 0)
				{
					if (k % 4 == 0)
					{
						subRow(keylast, sbox);
					}
				}
			}
		}
		///make new last key elem
		xorfuncN(keyfirst, keylast, keylast, rows);
		///keyshift
		shiftKey(keyw, nk, rows);
		///make new state elem
		xorfuncN(keyfirst, tmpstate, tmpstate, rows);
		///save new key elem
		for (i = 0; i<rows; i++)
		{
			state[i][col] = tmpstate[i];
			keyw[i][nk - 1] = keylast[i];
		}
		///xor-s
		if (col == 0)
		{
			col = 1;
		}
		else if (col == 1)
		{
			col = 2;
		}
		else if (col == 2)
		{
			col = 3;
		}
		else if (col == 3)
		{
			col = 0;
		}

	}
	//  cout<<"Cypher text:"<<endl;
	// printState(state,nb);
	copyState(state, nb, plain16);
	///
	// for()

}
///Decrypt sakas
void decript(char *key16, int keysize, char *plain16)
{
	int i, j, k, w, idec, last;
	int s = keysize;
	int nk = s / 32;
	int nb = 4;
	int col = 0;
	int keyfirst[32];
	int keylast[32];
	int arrRcon[32];
	int tmpstate[32];
	if (nk == 4)
	{
		idec = 44;
	}
	else if (nk == 6)
	{
		idec = 52;
	}
	else
	{
		idec = 60;
	}
	int rows = 32;
	int *arrk = new int[s];
	int *arrp = new int[nb*rows];
	char sbox16[513] = { "637c777bf26b6fc53001672bfed7ab76ca82c97dfa5947f0add4a2af9ca472c0b7fd9326363ff7cc34a5e5f171d8311504c723c31896059a071280e2eb27b27509832c1a1b6e5aa0523bd6b329e32f8453d100ed20fcb15b6acbbe394a4c58cfd0efaafb434d338545f9027f503c9fa851a3408f929d38f5bcb6da2110fff3d2cd0c13ec5f974417c4a77e3d645d197360814fdc222a908846eeb814de5e0bdbe0323a0a4906245cc2d3ac629195e479e7c8376d8dd54ea96c56f4ea657aae08ba78252e1ca6b4c6e8dd741f4bbd8b8a703eb5664803f60e613557b986c11d9ee1f8981169d98e949b1e87e9ce5528df8ca1890dbfe6426841992d0fb054bb16" };
	char tableE16[513] = { "0103050f113355ff1a2e7296a1f813355fe13848d87395a4f702060a1e2266aae5345ce43759eb266abed97090abe63153f5040c143c44cc4fd168b8d36eb2cd4cd467a9e03b4dd762a6f10818287888839eb9d06bbddc7f8198b3ce49db769ab5c457f9103050f00b1d2769bbd661a3fe192b7d8792adec2f7193aee92060a0fb163a4ed26db7c25de73256fa153f41c35ee23d47c940c05bed2c749cbfda759fbad564acef2a7e829dbcdf7a8e89809bb6c158e82365afea256fb1c843c554fc1f2163a5f407091b2d7799b0cb46ca45cf4ade798b8691a8e33e42c651f30e12365aee297b8d8c8f8a8594a7f20d17394bdd7c8497a2fd1c246cb4c752f601" };
	char tableL16[513] = { "0000190132021ac64bc71b6833eedf036404e00e348d81ef4c7108c8f8691cc17dc21db5f9b9276a4de4a6729ac90978652f8a05210fe12412f082453593da8e968fdbbd36d0ce94135cd2f14046833866ddfd30bf068b62b325e298228891107e6e48c3a3b61e423a6b2854fa853dba2b790a159b9f5eca4ed4ace5f373a757af58a850f4ead6744faee9d5e7e6ade82cd7757aeb160bf559cb5fb09ca951a07f0cf66f17c449ecd8431f2da4767bb7ccbb3e5afb60b1863b52a16caa55299d97b2879061bedcfcbc95cfcd373f5bd15339843c41a26d47142a9e5d56f2d3ab441192d923202e89b47cb8267799e3a5674aeddec531fe180d638c80c0f77007" };
	char invsbox16[513] = { "52096ad53036a538bf40a39e81f3d7fb7ce339829b2fff87348e4344c4dee9cb547b9432a6c2233dee4c950b42fac34e082ea16628d924b2765ba2496d8bd12572f8f66486689816d4a45ccc5d65b6926c704850fdedb9da5e154657a78d9d8490d8ab008cbcd30af7e45805b8b34506d02c1e8fca3f0f02c1afbd0301138a6b3a9111414f67dcea97f2cfcef0b4e67396ac7422e7ad3585e2f937e81c75df6e47f11a711d29c5896fb7620eaa18be1bfc563e4bc6d279209adbc0fe78cd5af41fdda8338807c731b11210592780ec5f60517fa919b54a0d2de57a9f93c99cefa0e03b4dae2af5b0c8ebbb3c83539961172b047eba77d626e169146355210c7d" };
	int tableE2[2048];
	int tableL2[2048];
	int sbox2[2048];
	int invsbox2[2048];
	int tableE[128][16];
	int tableL[128][16];
	int sbox[128][16];
	int invsbox[128][16];
	hextobin(sbox16, 512, sbox2);
	hextobin(invsbox16, 512, invsbox2);
	hextobin(tableE16, 512, tableE2);
	hextobin(tableL16, 512, tableL2);
	hextobin(key16, nk * 8, arrk);
	hextobin(plain16, rows, arrp);
	for (j = 0; j<16; j++)
	{
		for (i = 0; i<128; i++)
		{
			sbox[i][j] = sbox2[i + j * 128];
			invsbox[i][j] = invsbox2[i + j * 128];
			tableE[i][j] = tableE2[i + j * 128];
			tableL[i][j] = tableL2[i + j * 128];
		}
	}
	int plain2d[32][4];
	int state[32][4];
	int state2[32][4];
	int **keyw = new int*[rows];
	for (i = 0; i<rows; i++)
	{
		keyw[i] = new int[nk];
	}
	for (i = 0; i<nk; i++)
	{
		for (j = 0; j<rows; j++)
		{
			keyw[j][i] = arrk[j + i*rows];
		}
	}
	for (i = 0; i<nb; i++)
	{
		for (j = 0; j<rows; j++)
		{
			state[j][i] = arrp[j + i*rows];
		}
	}
	delete[]arrp;

	///reset key
	for (i = 0; i<nk; i++)
	{
		for (j = 0; j<rows; j++)
		{
			keyw[j][i] = arrk[j + i*rows];
		}
	}
	//cout<<"Check Cyphertext:"<<endl;
	//printState(state,nb);

	last = idec - nb;
	///get key
	for (k = 0; k<last; k++)
	{
		///copy
		for (i = 0; i<rows; i++)
		{
			keyfirst[i] = keyw[i][0];
			keylast[i] = keyw[i][nk - 1];
		}
		///update rcon
		rcon(k / nk, arrRcon);
		///key manip
		if (k%nk == 0)
		{
			rotWord(keylast, nb);
			subRow(keylast, sbox);
			xorfuncN(arrRcon, keylast, keylast, rows);
		}
		///for 256 key only
		if (nk == 8)
		{
			if (k<idec - nb)
			{
				if (k % 8 != 0)
				{
					if (k % 4 == 0)
					{
						subRow(keylast, sbox);
					}
				}
			}
		}
		///make new last key elem
		xorfuncN(keyfirst, keylast, keylast, rows);
		///keyshift
		shiftKey(keyw, nk, rows);
		///save new key elem
		for (i = 0; i<rows; i++)
		{
			keyw[i][nk - 1] = keylast[i];
		}
	}
	for (i = 0; i<nb; i++)
	{
		xorfunc(state, keyw, state, rows, i);
	}
	for (w = 0; w<idec / nb - 1; w++)
	{
		invshiftrows(state);
		subbytes(invsbox, state);
		///reset key
		for (i = 0; i<nk; i++)
		{
			for (j = 0; j<rows; j++)
			{
				keyw[j][i] = arrk[j + i*rows];
			}
		}
		last = last - nb;
		///new key
		///get key
		for (k = 0; k<last; k++)
		{
			///copy
			for (i = 0; i<rows; i++)
			{
				keyfirst[i] = keyw[i][0];
				keylast[i] = keyw[i][nk - 1];
			}
			///update rcon
			rcon(k / nk, arrRcon);
			///key manip
			if (k%nk == 0)
			{
				rotWord(keylast, nb);
				subRow(keylast, sbox);
				xorfuncN(arrRcon, keylast, keylast, rows);
			}
			///for 256 key only
			if (nk == 8)
			{
				if (k<idec - nb)
				{
					if (k % 8 != 0)
					{
						if (k % 4 == 0)
						{
							subRow(keylast, sbox);
						}
					}
				}
			}
			///make new last key elem
			xorfuncN(keyfirst, keylast, keylast, rows);
			///keyshift
			shiftKey(keyw, nk, rows);
			///save new key elem
			for (i = 0; i<rows; i++)
			{
				keyw[i][nk - 1] = keylast[i];
			}
		}
		for (i = 0; i<nb; i++)
		{
			xorfunc(state, keyw, state, rows, i);
		}
		///invMIX
		if (w<idec / nb - 2)
		{
			invmixcol(tableL, tableE, state);
		}

	}
	//cout<<"Decript Plain:"<<endl;

	//printState(state,nb);
	copyState(state, nb, plain16);


	///Decrypt beidzas
	for (i = 0; i<rows; i++)
	{
		delete[]keyw[i];
	}
	delete[]keyw;
	delete[]arrk;
}

void descript(char *key16, char* plain16)//(int *keyfsh)
{
	// fstream fout;
	//  fstream fin ("in.txt", ios::in);
	// fout.open ("out.txt", ios::out);

	int keyfsh[56];
	int kpkeyl[28];
	int kpkeyr[28];
	//  int test1[64];
	//  int test2[48];
	int kpkey[56];
	int fkey[56];
	int cpkey[48];
	int rnexp[48];
	int bintmp[4];
	int sbox[32];
	int xbox[32];
	int   dekey[64];
	int   key[64];
	int plain[64];
	///fill key and plain
	/* for(int i=0;i<64;i++)
	{
	key[i]=1;
	plain[i]=1;
	// test1[i]=i+1;
	} */
	hextobin(key16, 16, key);
	hextobin(plain16, 16, plain);
	// int plain[64]={0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,0,1,1,1,1};
	// int   key[64]={0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1};
	int c;

	int m = 0;

	/* cout << "plain="<<endl;
	for(int i=0;i<64;i++)
	{
	cout<<plain[i];
	}
	cout<<endl;
	cout<<endl;*/
	int ipplain[64];
	int cypher[64];
	int exp[48];
	int rn[32];
	int ln[32];
	int rn1[32];
	int ln1[32];
	int tmp;
	int row;
	int col;
	int stmp;
	int ctmp;
	int i = 0, j = 0;
	///Initial permutation
	permutation(64, plain, ipplain, ip);
	///key permutationS
	permutation(56, key, kpkey, kp);
	///split key
	split(kpkey, kpkeyl, kpkeyr, 28);
	///function F
	for (i = 0; i<16; i++)
	{
		///split into L and R
		split(ipplain, ln, rn, 32);
		///l(n+1)
		for (j = 0; j<32; j++)
		{
			ln1[j] = rn[j];
		}
		///bit shift
		shift(kpkeyl, bsh[i]);
		shift(kpkeyr, bsh[i]);
		for (j = 0; j<28; j++)
		{
			fkey[j] = kpkeyl[j];
			fkey[j + 28] = kpkeyr[j];
		}
		///fkey compression permutation
		permutation(48, fkey, cpkey, cp);
		///Expantion Permutation
		permutation(48, rn, rnexp, ep);
		/// XOR (RNEXP,CPKEY)
		xorfunc(rnexp, cpkey, exp, 48);
		///Sbox substitution
		ctmp = 0;
		for (j = 0; j<48; j = j + 6)
		{
			row = exp[j] * 2 + exp[j + 5];
			col = 8 * exp[j + 1] + 4 * exp[j + 2] + 2 * exp[j + 3] + exp[j + 4];
			stmp = 0;
			if (j == 0)stmp = sbox1[row][col];
			if (j == 6)stmp = sbox2[row][col];
			if (j == 12)stmp = sbox3[row][col];
			if (j == 18)stmp = sbox4[row][col];
			if (j == 24)stmp = sbox5[row][col];
			if (j == 30)stmp = sbox6[row][col];
			if (j == 36)stmp = sbox7[row][col];
			if (j == 42)stmp = sbox8[row][col];
			desdectobin(stmp, bintmp);

			for (int k = 0; k<4; k++)
			{
				sbox[ctmp + k] = bintmp[k];
			}
			ctmp = ctmp + 4;
		}///Sbox substitution END

		 ///Pbox permutation
		permutation(32, sbox, xbox, pbox);


		/// XOR(xbox,ln)
		xorfunc(xbox, ln, rn1, 32);

		///new ipplain
		for (j = 0; j<32; j++)
		{
			ipplain[j] = ln1[j];
			ipplain[j + 32] = rn1[j];
		}
	}///function F end
	for (j = 0; j<32; j++)
	{
		ipplain[j] = rn1[j];
		ipplain[j + 32] = ln1[j];
	}
	///Final permutation
	permutation(64, ipplain, cypher, fp);
	// permutation(64, test1,test2 , fp);
	copyDES(plain16, cypher);


}

void desdecript(char *key16, char* plain16)
{
	int keyfsh[56];
	int kpkeyl[28];
	int kpkeyr[28];
	int test1[64];
	int test2[48];
	int kpkey[56];
	int fkey[56];
	int cpkey[48];
	int rnexp[48];
	int bintmp[4];
	int sbox[32];
	int xbox[32];
	int   dekey[64];
	int   key[64];
	int plain[64];
	int ipplain[64];
	int cypher[64];
	int exp[48];
	int rn[32];
	int ln[32];
	int rn1[32];
	int ln1[32];
	int tmp;
	int row;
	int col;
	int stmp;
	int ctmp;
	int i = 0, j = 0;
	///fill key and plain
	/* for(int i=0;i<64;i++)
	{
	key[i]=1;
	plain[i]=1;
	// test1[i]=i+1;
	} */
	hextobin(key16, 16, key);
	hextobin(plain16, 16, plain);
	///Decryption
	///Initial permutation
	permutation(64, plain, ipplain, ip);
	///key permutationS


	///reverse keys

	for (i = 0; i<56; i++)
	{
		key[i] = fkey[i];
	}
	///split key

	split(key, kpkeyl, kpkeyr, 28);

	///function F
	for (i = 0; i<16; i++)
	{
		///split into L and R
		split(ipplain, ln, rn, 32);
		for (j = 0; j<32; j++)
		{
			ln1[j] = rn[j];
		}
		///bit shift
		deshift(kpkeyl, debsh[i]);
		deshift(kpkeyr, debsh[i]);
		for (j = 0; j<28; j++)
		{
			fkey[j] = kpkeyl[j];
			fkey[j + 28] = kpkeyr[j];
		}
		///fkey compression permutation
		permutation(48, fkey, cpkey, cp);

		///Expantion Permutation
		permutation(48, rn, rnexp, ep);
		/// XOR (RNEXP,CPKEY)
		xorfunc(rnexp, cpkey, exp, 48);
		///Sbox substitution
		ctmp = 0;
		for (j = 0; j<48; j = j + 6)
		{
			row = exp[j] * 2 + exp[j + 5];
			col = 8 * exp[j + 1] + 4 * exp[j + 2] + 2 * exp[j + 3] + exp[j + 4];
			stmp = 0;
			if (j == 0)stmp = sbox1[row][col];
			if (j == 6)stmp = sbox2[row][col];
			if (j == 12)stmp = sbox3[row][col];
			if (j == 18)stmp = sbox4[row][col];
			if (j == 24)stmp = sbox5[row][col];
			if (j == 30)stmp = sbox6[row][col];
			if (j == 36)stmp = sbox7[row][col];
			if (j == 42)stmp = sbox8[row][col];
			desdectobin(stmp, bintmp);
			for (int k = 0; k<4; k++)
			{
				sbox[ctmp + k] = bintmp[k];
			}
			ctmp = ctmp + 4;
		}///Sbox substitution END

		 ///Pbox permutation
		permutation(32, sbox, xbox, pbox);

		/// XOR(xbox,ln)

		xorfunc(xbox, ln, rn1, 32);

		///new ipplain
		for (j = 0; j<32; j++)
		{
			ipplain[j] = ln1[j];
			ipplain[j + 32] = rn1[j];
		}
	}///function F end
	for (j = 0; j<32; j++)
	{
		ipplain[j] = rn1[j];
		ipplain[j + 32] = ln1[j];
	}
	///Final permutation
	permutation(64, ipplain, cypher, fp);
	copyDES(plain16, cypher);
}

int main()
{
	// fstream fin("ind3.txt",ios::in);
	// fstream fout("out3d.txt",ios::out);
	int i, j, k, s, p, m;
	fstream fin("in.txt", ios::in);
	fstream fout("out.txt", ios::out);
	//  int s;//=256;///new key size
	int rows = 32;
	char plain16[33];//"00112233445566778899aabbccddeeff";
	char *key16;


	char c;
	fin.get(c);
	while (fin.good())
	{

		if (c == 'P')
		{
			i = 0;
			fin.get(c);
			fin.get(c);
			while (c != '\n')
			{
				///store plain
				// cout<<c;
				plain16[i] = c;
				fin.get(c);
				i++;
			}
			plain16[i] = 0;
		}
		if (c == 'S')
		{
			fin.get(c);
			fin >> s;
			//cout<<"size="<<s<<endl;
			key16 = new char[s + 1];
		}
		if (c == 'K')
		{
			j = 0;
			fin.get(c);
			fin.get(c);
			while (c != '\n')
			{
				///store plain
				// cout<<c<<j<<endl;
				key16[j] = c;
				fin.get(c);
				j++;
			}
			//plain16[i]=0;
		}
		if (c == 'M')
		{
			fin >> m;
			fin.get(c);
			//cout<<"m="<<m<<endl;//break;
		}
		if (c == 'C')
		{
			fout << "Plain=";
			i = 0;
			while (plain16[i] != 0)
			{
				fout << plain16[i];
				i++;
			}
			fout << endl;
			// cout<<"cript"<<endl;
			if (m == 1)
			{
				cript(key16, s, plain16);
			}
			else
			{
				descript(key16, plain16);
			}
			i = 0;
			fout << "Cypher=";
			while (plain16[i] != 0)
			{
				fout << plain16[i];
				i++;
			}
			fout << endl;
		}
		if (c == 'D')
		{
			// cout<<"decript"<<endl;
			// decript(key16,s,plain16);
			fout << "Cypher=";
			i = 0;
			while (plain16[i] != 0)
			{
				fout << plain16[i];
				i++;
			}
			fout << endl;
			// cout<<"cript"<<endl;
			// decript(key16,s,plain16);
			if (m == 1)
			{
				decript(key16, s, plain16);
			}
			else
			{
				desdecript(key16, plain16);
			}
			i = 0;
			fout << "Plain=";
			while (plain16[i] != 0)
			{
				fout << plain16[i];
				i++;
			}
			fout << endl;
		}
		fin.get(c);
	}
	fin.close();
	fout.close();
	//cout<<plain16<<endl;
	delete[]key16;
	return 0;
}
