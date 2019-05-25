#include <stdio.h>

//char������ ��ȯ�� ���ڸ� ó��(����)
int card_conver(unsigned x, int n, char d[]);
//x�� n�ڸ����� ������ �迭 d�� ����
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
	unsigned no;	//��ȯ�ϴ� ����
	int cd;			//���
	int dno;		//��ȯ�� �ڸ���
	char cno[512];	
	int retry;

	do {
	puts("��ȯ�ϴ� ���� �ƴ� ����");
	scanf_s("%u", &no);

		do {
			printf("� ������ ��ȯ�ұ��?(2-36): ");
			scanf_s("%d", &cd);
		} while (cd < 2 || cd >36);

		dno = card_conver(no, cd, cno);
		for (i = dno - 1; i >= 0 ; i--) {
			//printf("%c", *(cno + i));
			printf("%c", cno[i]);
		}
		printf("�ѹ���?(1:Yes/ 0:No)");
		scanf_s("%d", &retry);
	}while (retry == 1);
	
	return 0;
})