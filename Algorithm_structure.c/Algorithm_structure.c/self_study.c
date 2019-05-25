#include <stdio.h>

//char형으로 변환할 숫자를 처리(교재)
int card_conver(unsigned x, int n, char d[]);
//x를 n자리수로 나눠서 배열 d에 저장
int card_conver(unsigned x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEF";
	int digits = 0;
	if (x == 0)
		d[digits++] = dchar[0];
	else
		while (x)
		{
			d[digits++] = dchar[x%n];
			x /= n;
		}
	return digits;
}

int main()
{
	int i;
	unsigned no;	//변환하는 정수
	int cd;			//기수
	int dno;		//변환후 자리수
	char cno[512];	
	int retry;

	do {
	puts("변환하는 음이 아닌 정수");
	scanf_s("%u", &no);

		do {
			printf("어떤 진수로 변환할까요?(2-36): ");
			scanf_s("%d", &cd);
		} while (cd < 2 || cd >36);

		dno = card_conver(no, cd, cno);
		for (i = dno - 1; i >= 0 ; i--) {
			//printf("%c", *(cno + i));
			printf("%c", cno[i]);
		}
		printf("한번더?(1:Yes/ 0:No)");
		scanf_s("%d", &retry);
	}while (retry == 1);
	
	return 0;
})