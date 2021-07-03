#include "sms_head.h"//�Զ����ͷ�ļ�

//_CRT_SECURE_NO_WARNINGS			�ⲿ���ǽ�� VS2019 scanf() �� fopen() �ı������⣨��Ŀ-����-��ӽ�Ԥ�����壩
//fflush(stdin)						�˺����� VS ����Ч��

#define LEN sizeof(struct Student)	//�ṹ����ڴ��С
#define XM 9						//����������ĸ����ģ�
#define SYD 9						//��Դ�أ�����ĸ����ģ�
#define BCZJ 4						//4 �ֽڣ����������ֽڣ�

struct Student {
	unsigned int xh;				//ѧ�ţ�2020500101 <  4 294 967 295��
	char * xm;						//����
	char xb;						//�Ա�0 �����ԣ���֮��
	unsigned int csrq;				//�������ڣ�20201010��
	char * syd;						//��Դ��
	char nl;						//���䣨�������룩
	struct Student * next;
};

//���ݵ�Ĭ�ϱ����ַ�����·��������ͨ��ѧ�Ŷ����޸�
//Ŀǰ֧�ֵ�·��������Ĭ�ϵ�ַ��20194110ϵ�С�20183001ϵ�С�20172110ϵ��
char default_address[] = { ".\\Data\\2020\\5\\0\\0\\1\\20205001.Dat" };

int main() {
	//�ı����̨����ɫ��ǰ��ɫ 0 ��ɫ��A ��ɫ
	system("color 0A");

	ui(0);

	printf("Bye Bye!\n");

	return 0;
}

//����򵥵Ľ�������
int ui(int n) {
	//i ����ѭ����pick ����ѡ��
	int i, pick;
	// * �� - ��ʽ���������������װ��
	const int Unit = 80;

	switch (n) {
		//Main UI 0
	case 0: {
		while (1) {
			printf("\t\t Student Management System \n");
			for (i = 0; i < Unit; i++) { printf("*");		Sleep(Unit / 10); }
			printf("\nQuti input 0, Search input 1 , Add input 2 , Delete input 3 , Modify input 4 :");

			scanf("%d", &pick);
			switch (pick) {
			case 0:	return 0;
			case 1:	Search();	break;
			case 2:	Add();		break;
			case 3:	Delete();	break;
			case 4:	Modify();	break;
			default:printf("Main Input Error !\n");		Sleep(1000);//��ʱ 1 ��
			}
			system("cls");//����
		}
	}break;

		//Search UI 11
	case 11: {
		system("cls");//����
		printf("\t\t Search Student Information \n");
		for (i = 0; i < Unit; i++) { printf("-");		Sleep(Unit / 10); }
		printf("\nReturn input 0 , Search input Student ID :");
	}break;

		//Search UI 12
	case 12: {
		while (1) {
			for (i = 0; i < Unit; i++) { printf("-");		Sleep(Unit / 10); }
			printf("\nReturn input 0  , (Student ID)List All input 1 , (Age)List All input 2 :");

			scanf("%d", &pick);
			switch (pick) {
			case 0:		return 0;
			case 1:		return 1;
			case 2:		return 2;
			default:printf("Search Input Error !\n");		Sleep(1000);
			}
		}
	}break;

		//Add  UI 21
	case 21: {
		while (1) {
			system("cls");	//����
			printf("\t\t Add Student Information \n");
			for (i = 0; i < Unit; i++) { printf("-");		Sleep(Unit / 10); }
			printf("\nContinue input 1 , Return input 0 :");

			scanf("%d", &pick);
			switch (pick) {
			case 0:		return 1;
			case 1:		return 0;
			default:printf("Add Input Error !\n");		Sleep(1000);
			}
		}
	}break;

		//Add UI 22
	case 22: {
		for (i = 0; i < Unit; i++) { printf("-");		Sleep(Unit / 10); }
		printf("\nSave and Return input 0 , Continue input 1 , Revise input 2 :");

		scanf("%d", &pick);
		return pick;
	}break;

		//Detele UI 31
	case 31: {
		while (1) {
			system("cls");	//����
			printf("\t\tDetele Student Information \n");
			for (i = 0; i < Unit; i++) { printf("-");		Sleep(Unit / 10); }
			printf("\nReturn input 0 , Detele input 1:");

			scanf("%d", &pick);
			switch (pick) {
			case 0:		return 0;
			case 1:		return 1;
			default:printf("Detele Input Error !\n");		Sleep(1000);
			}
		}
	}break;

		//Detele UI 32
	case 32: {
		while (1) {
			for (i = 0; i < Unit; i++) { printf("-");		Sleep(Unit / 10); }
			printf("/nConfirm inout 1 , Cancel Detele inout 0 :");

			scanf("%d", &pick);
			switch (pick) {
			case 0:		return 0;
			case 1:		return 1;
			default:printf("Detele Input Error !\n");		Sleep(1000);
			}
		}
	}break;

		//Modify UI 41
	case 41: {
		while (1) {
			system("cls");	//����
			printf("\t\tModify Student Information \n");
			for (i = 0; i < Unit; i++) { printf("-");		Sleep(Unit / 10); }
			printf("\nReturn input 0 , Modify input 1:");

			scanf("%d", &pick);
			switch (pick) {
			case 0:		return 0;
			case 1:		return 1;
			default:printf("Modify Input Error !\n");		Sleep(1000);
			}
		}
	}break;

		//Modify UI 42
	case 42: {
		while (1) {
			for (i = 0; i < Unit; i++) { printf("-");		Sleep(Unit / 10); }
			printf("/nConfirm inout 1 , Cancel Modify inout 0 :");

			scanf("%d", &pick);
			switch (pick) {
			case 0:		return 0;
			case 1:		return 1;
			default:printf("Modify Input Error !\n");		Sleep(1000);
			}
		}
	}break;

	}
	return 0;
}

void Add() {
	// t �����ͷָ�룬p ����ı䶯ָ��
	struct Student* t, * p;
	//��Ż������в���Ҫ������
	char scanf_stdin = 0;

	if (ui(21)) {
		return;
	}

	//Ϊ��������ڴ��ַ�ռ� 24 �ֽ�(4 * 6),��Ϊ�ṹ���ڴ�����⣬���� char ʵ����ռ�� 4 �ֽڣ�ֻ�����ڴ��У�����ֻʹ�� 1 �ֽڣ������������ԭ��
	t = p = (struct Student*)malloc(LEN);
	while (1) {
		goto A;
		printf("Please input ѧ�ţ�\t\t\t");
		scanf("%u", &(p->xh));						check(1, &(p->xh));//���������Ч��

		printf("Please input ��������֧���ĸ����֣���\t");		p->xm = (char*)malloc(XM);		scanf("%s", p->xm);

		printf("Please input �Ա� ��/Ů(0/1)��\t\t");	while ((scanf_stdin = getchar()) != 10);//��ջ�����
		scanf("%c", &(p->xb));						check(2, &(p->xb));//���������Ч��
		A:
		printf("Please input �������� (20010101����\t");
		scanf("%u", &(p->csrq));			p->nl = check(3, &(p->csrq));//���������Ч��	

		printf("Please input ��Դ�أ���֧���ĸ����֣���\t");	p->syd = (char*)malloc(SYD);	scanf("%s", p->syd);

		switch (ui(22)) {
			case 0:	p->next = NULL;			io(1, t);							return;	//���沢�˳���Ϊβ�ڵ㸳���ָ��ͬʱ���浽�ļ����˳�
			case 1:	p->next = (struct Student*)malloc(LEN);		p = p->next;	break;	//�������룺Ϊβ�ڵ㿪���µ��ڴ��ַ�ռ�
			case 2:	break;																//�޸ı������룺������������һ��
			default:printf("Input Error !(Not Search)\n");	Sleep(1000);	system("cls");
		}
	}
}

void Search() {
	//ð���㷨��ʼָ�� p���Ա�ָ�� m��ͷָ�� t
	struct Student* p, * m, * t;

	//�м����������ʱʹ��
	unsigned int id;
	char age;

	unsigned int x;//ѧ��

	ui(11);
	scanf("%u", &x);
	//ȷ���˳�
	if (x == 0) {
		return;
	}

	//����ѧ�Ŷ�ȡ��ѧ�������ļ���ȫ�����ݣ�������������ͷָ��
	t = p = io(2, x);

	while (1) {
		//m �� p �ṹ����ָ�����һ���ṹ��
		m = p->next;

		switch (ui(12)) {
		case 0:		return;

		//ʹ��ð���㷨��������
		case 1: {
			for (; p->next != NULL; p = p->next) {
				for (; m->next != NULL; m = m->next) {
					if (p->xh > m->xh) {
						memcpy(&id, p, sizeof(struct Student));
						memcpy(p, m, sizeof(struct Student));
						memcpy(m, &id, sizeof(struct Student));
					}
				}
			}
		}break;

		//ʹ��ð���㷨��������
		case 2: {
			for (; p->next != NULL; p = p->next) {
				for (; m->next != NULL; m = m->next) {
					if (p->nl < m->nl) {
						memcpy(&age, p, sizeof(struct Student));
						memcpy(p, m, sizeof(struct Student));
						memcpy(m, &age, sizeof(struct Student));
					}
				}
			}
		}break;

		}

		for (p = t; p != NULL; p = p->next) {
			printf("ѧ��:%u\t\t", p->xh);
			printf("����:%s\n", p->xm);
			switch (p->xb) {
			case 48:printf("�Ա�:��\t\t"); break;
			case 49:printf("�Ա�:Ů\t\t");
			}
			printf("����:%d\n", p->nl);
			printf("��������:%u\t\t", p->csrq);
			printf("��Դ��:%s\n", p->syd);
		}
	}
}

void Delete() {
	struct Student* t;

	unsigned int x;//ѧ��

	while (1) {
		switch (ui(31)) {
		case 0:	return;

		case 1: {
			printf("Please input Student ID : ");
			scanf("%u", &x);
			//����ѧ�Ŷ�ȡ��ѧ�������ļ���ȫ�����ݣ�������������ͷָ��
			t = io(2, x);

			if (ui(32)) {
				//����д�����ݣ���ɾ�������ݲ�д��
				io(3, t);
				printf("Deletion Complete\n");
			}
		}

		}
	}
}

void Modify() {
	struct Student* t;

	unsigned int x;//ѧ��

	while (1) {
		switch (ui(41)) {
		case 0:	return;
		case 1:
			printf("Please input Student ID : ");
			scanf("%u", &x);
			//����ѧ�Ŷ�ȡ��ѧ�������ļ���ȫ�����ݣ�������������ͷָ��
			t = io(2, x);
			if (ui(42)) {
				//����д������
				io(4, t);
				printf("Modify Complete\n");
			}
		}
	}
}

//i = 1(Add), 2(Read), 3(Dele), 4(Modify), ���ļ���IO����
struct Student* io(int i, ...) {
	FILE* fp;
	struct Student* t;
	// p �ǵڶ�����������д���ļ�������ͷָ��
	struct Student* p = NULL;
	// x �ǵ�������������Ų��ҵ�ѧ�ţ�Ϊ��ֹ i = 1 ʱ����ã��ʳ�ʼ��Ϊ 0
	unsigned int x = 0;
	//�ļ������ݵ�����
	int u;

	/*����δ�����Ĳ��������ȱ����ڿɱ��������������va_list���͵ı���������va_start����������������
	��һ������Ϊva_list���͵ı�����
	�ڶ���Ϊʡ�Ժ�ǰ���һ�������ֵĲ��������ƣ�����ÿһ����va_arg�ͻ᷵����һ��������va_arg�ĵ�һ������Ϊva_list���ڶ�������Ϊ���ص����͡�
	���va_end�����ں�������ǰ��va_list����(va_list��������)(û��Ҫ��Ҫ��ȡ�����в���)��*/

	//���� va_list ���ͱ���
	va_list ap;
	//ʹ va_list ָ��ɱ��������ʼ�Ĳ���
	va_start(ap, i);
	//���� i ��ֵȷ�����ε��ú����Ĳ�������
	switch (i) {
	case 1://Add
		p = va_arg(ap, struct Student*);	break;
	case 2://Read
	case 3://Dele
	case 4://Modify
		x = va_arg(ap, unsigned int);	break;
	default:
		printf("Function Parameter Error io()!\n");
		exit(0);
	}
	va_end(ap);//�ͷ� va_list���ͷ�ʱ�������������Ȼ����


	switch (i) {
		//Add
	case 1: {
		//���ļ�����������ļ�β������ݣ��ԡ�ab����ʽ��
		if ((fp = fopen(address(p->xh), "ab")) == NULL) {
			printf("File Output Error !\n");
			exit(0);
		}

		//����������д���ļ�
		for (; p != NULL; p = p->next) {
			fwrite(&(p->xh), sizeof(unsigned int), 1, fp);
			fwrite(p->xm, XM, 1, fp);
			fwrite(&(p->xb), sizeof(char), 1, fp);
			fwrite(&(p->csrq), sizeof(unsigned int), 1, fp);
			fwrite(p->syd, SYD, 1, fp);
			fwrite(&(p->nl), sizeof(char), 1, fp);
			fclose(fp);
		}
	}break;

		//Read
	case 2: {
		//���ļ����Ӷ������ļ��ж�ȡ���ݣ��ԡ�rb����ʽ��
		if ((fp = fopen(address(p->xh), "rb")) == NULL) {
			printf("File Input Error !\n");
			exit(0);
		}

		t = p = (struct Student*)malloc(LEN);

		//���ļ��ڱ�ʶָ�������ļ�ĩβ���������һ������
		fseek(fp, 0, 2);
		//�ļ��ֽ��� / �ṹ�����ݵĴ�С���ǽṹ���С�� = �ļ��ڵ���Ϣ��λ�����ڽ���ʶָ���ƻ����ļ��ײ���
		//�ṹ�����ݴ�С������ѧ�� 4�� ���� 9�� �Ա� 1�� �������� 4�� ��Դ�� 9�� ���� 1
		for (u = ftell(fp) / (sizeof(unsigned int) + XM + sizeof(char) + sizeof(unsigned int) + SYD + sizeof(char)), fseek(fp, 0, 0); ; p->next = (struct Student*)malloc(LEN), p = p->next) {
			//�����ڴ��ַ�ռ�
			p->xm = (char*)malloc(XM);
			p->syd = (char*)malloc(SYD);
			//��ȡ�ļ����ݵ�����
			fread(&(p->xh), sizeof(unsigned int), 1, fp);
			fread(p->xm, XM, 1, fp);
			fread(&(p->xb), sizeof(char), 1, fp);
			fread(&(p->csrq), sizeof(unsigned int), 1, fp);
			fread(p->syd, SYD, 1, fp);
			fread(&(p->nl), sizeof(char), 1, fp);

			//���ݲ��� x ����ƥ�����Ϣ
			if (p->xh == x) {
				printf("ѧ��:%u\t\t", p->xh);
				printf("����:%s\n", p->xm);
				switch (p->xb) {
				case 48:printf("�Ա�:��\t\t"); break;
				case 49:printf("�Ա�:Ů\t\t");
				}
				printf("����:%d\n", p->nl);
				printf("��������:%u\t\t", p->csrq);
				printf("��Դ��:%s\n", p->syd);

			}

			//��ѭ������ = ��Ϣ��
			if (++i == u) {
				p->next = NULL;
				break;
			}
		}
		fclose(fp);//�ر��ļ�

		return t;//���ض�ȡ�������ָ��
	}break;

		//Dele
	case 3: {
		//����ʵ�ֵķ�������ɾ���ļ���Ȼ�����´����ļ���д������
		if (remove(address(p->xh)) != 0) {
			printf("File Dele Error !\n");
		}

		//���ļ�����������ļ�������ݣ��ԡ�wb����ʽ��
		if ((fp = fopen(address(p->xh), "wb")) == NULL) {
			printf("File Output Error !\n");
			exit(0);
		}

		//����������д���ļ�
		for (; p != NULL; p = p->next) {
			//����ɾ����ƥ�����Ϣд���ļ�
			if (p->xh == x) {
				//�ر��ļ�����������ѭ��
				fclose(fp);
				continue;
			}

			//����������д���ļ�
			fwrite(&(p->xh), sizeof(unsigned int), 1, fp);
			fwrite(p->xm, XM, 1, fp);
			fwrite(&(p->xb), sizeof(char), 1, fp);
			fwrite(&(p->csrq), sizeof(unsigned int), 1, fp);
			fwrite(p->syd, SYD, 1, fp);
			fwrite(&(p->nl), sizeof(char), 1, fp);
			fclose(fp);
		}
	}break;

		//Modify
	case 4: {
		//����ʵ�ֵķ�������ɾ���ļ���Ȼ�����´����ļ���д������
		if (remove(address(p->xh)) != 0) {
			printf("File Dele Error !\n");
		}

		//���ļ�����������ļ�������ݣ��ԡ�wb����ʽ��
		if ((fp = fopen(address(p->xh), "wb")) == NULL) {
			printf("File Output Error !\n");
			exit(0);
		}

		//����������д���ļ�
		for (; p != NULL; p = p->next) {
			fwrite(&(p->xh), sizeof(unsigned int), 1, fp);
			fwrite(p->xm, XM, 1, fp);
			fwrite(&(p->xb), sizeof(char), 1, fp);
			fwrite(&(p->csrq), sizeof(unsigned int), 1, fp);
			fwrite(p->syd, SYD, 1, fp);
			fwrite(&(p->nl), sizeof(char), 1, fp);
			fclose(fp);
		}
	}break;

	}
}

//�� io ����ѡ���ַʹ�ã����������ѧ�Ÿ����ļ������·��
char* address(unsigned int xh) {
	int i = 7;
	//TODO, But...				2020500101
	default_address[i++] = xh / 1000000000;//2
	default_address[i++] = xh / 100000000;//0
	default_address[i++] = xh / 10000000;//2
	default_address[i++] = xh / 1000000; i++;//0
	default_address[i++] = xh / 100000; i++;//5
	default_address[i++] = xh / 10000; i++;//0
	default_address[i++] = xh / 1000; i++;//0
	default_address[i++] = xh / 100; i++;//1
	default_address[i++] = xh / 1000000000;//2
	default_address[i++] = xh / 100000000;//0
	default_address[i++] = xh / 10000000;//2
	default_address[i++] = xh / 1000000;//0
	default_address[i++] = xh / 100000;//5
	default_address[i++] = xh / 10000;//0
	default_address[i++] = xh / 1000;//0
	default_address[i++] = xh / 100;//1
	return default_address;
}

//i = 1(xh), 2(xb), 3(csrq), �� Add �������������Ч��
char check(int i, ...) {
	//���ݽ��ձ���
	char* xb;
	unsigned int* xh, * csrq;
	//��Ż������в���Ҫ������
	char scanf_stdin = 0;
	//ʱ�����͵ı��������ݽṹ����������������ڵ���ز���
	time_t t;
	struct tm* lt;
	//���������Ľ��ܱ���
	va_list ap;
	va_start(ap, i);

	time(&t);//��ȡUnixʱ���
	lt = localtime(&t);//תΪ tm ���ݽṹ

	switch (i) {
		//���ѧ��
	case 1: {
		xh = va_arg(ap, unsigned int*);
		while (1) {
			//ȡ��ѧ��ǰ��λ������Ƿ��� ���� ���� ������
			if (*xh / 1000000 >= lt->tm_year + 1900 || *xh / 1000000 <= lt->tm_year + 1900 - 6) {
				printf("Input Error ! Again Input:\t\t");
				scanf("%u", xh);
				continue;
			}
			else break;
		}
	}break;

		//����Ա�
	case 2: {
		xb = va_arg(ap, char*);
		while ((scanf_stdin = getchar()) != 10);//��ջ�����
		while (1) {
			if (*xb != 48 && *xb != 49) {
				printf("Input Error ! Again Input:\t\t");
				scanf("%c", xb);
				while ((scanf_stdin = getchar()) != 10);//��ջ�����
			}
			else break;
		}
	}break;

		//����������
	case 3: {
		csrq = va_arg(ap, unsigned int*);
		while (1) {
			//����� 50 ���ڣ�ͬʱ���� 10 ����
			if (*csrq / 10000 >= lt->tm_year + 1900 - 50 && *csrq / 10000 <= lt->tm_year + 1900 - 10) {
				switch ((*csrq / 100) % 100) {
					//����ݷ��ϣ��� 1 3 5 7 8 10 12�·�ʱ
				case 1:	case 3:	case 5:	case 7:	case 8:	case 10:	case 12: {
					//���ڲ��� > 31
					if (*csrq % 100 > 31) {
						printf("Input Error ! Again Input:\n");		Sleep(1000);
						scanf("%u", csrq);		continue;
					}
				}break;

					//����ݷ��ϣ��� 4 6 9 11�·�ʱ
				case 4:	case 6:	case 9:	case 11: {
					//���ڲ��� > 30
					if (*csrq % 100 > 30) {
						printf("Input Error ! Again Input:\n");		Sleep(1000);
						scanf("%u", csrq);		continue;
					}
				}break;

					// 2 �·����⴦��
				case 2: {
					//�ж�����
					if (*csrq / 10000 % 400 == 0) {
						i = 1;
					}
					else
					{
						if (*csrq / 10000 % 4 == 0 && *csrq / 10000 % 100 != 0)
							i = 1;
						else
							i = 0;
					}
					//�������
					if (i) {
						//���� < 30
						if (*csrq % 100 > 29) {
							printf("Input Error ! Again Input:\n");		Sleep(1000);
							scanf("%u", csrq);	continue;
						}
					}
					else {//��֮ < 29
						if (*csrq % 100 > 28) {
							printf("Input Error ! Again Input:\n");		Sleep(1000);
							scanf("%u", csrq);	continue;
						}
					}

				}break;

				default: {
					printf("Input Error ! Again Input:\t\t");		Sleep(1000);
					scanf("%u", csrq);			continue;
				}

				}
			}
			//��ݲ����ϱ�׼ʱ
			else {
				printf("Input Error ! Again Input:\t\t");		Sleep(1000);
				scanf("%u", csrq);				continue;
			}

			//��ϵͳ�·� = ���������·ݣ������Ƚ����ڴ�С
			//mon �� tm ʱ��Ľṹ���з��·ݵı�������� 0 ��ʼ������ + 1
			if (lt->tm_mon + 1 == (*csrq / 100) % 100) {
				//���������ڴ�������ʱ�������������һ��
				if (lt->tm_mday > *csrq % 100) {
					va_end(ap);
					return lt->tm_year - (*csrq / 10000 - 1970) - 1;
				}
				//��֮���������յ��죬������
				else {
					va_end(ap);
					return lt->tm_year - (*csrq / 10000 - 1970) - 2;
				}
			}
			//��ϵͳ�·� < ���������·ݣ�������
			else {
				if (lt->tm_mon + 1 < (*csrq / 100) % 100) {
					va_end(ap);
					return lt->tm_year - (*csrq / 10000 - 1970) - 2;
				}
				//��ϵͳ�·� > ���������·ݣ���һ��
				else {
					va_end(ap);
					return lt->tm_year - (*csrq / 10000 - 1970) - 1;
				}
			}
		}
	}

	}
}

/*��������������ȷ�ģ�����ȴ�������쳣�жϣ��ж���ϢΪ:Run-Time Check Failure #2 - Stack around the variable ��a�� was corrupted.
����������һ�£�������Ϊջ���ƻ��ˡ�
��������ִ���������Ƕ�������в���ʱ������˵����һ�� int num[10]���������飬������Ҫ�ı�num[10]��ֵʱ���ͻ������쳣�жϣ�
������Ϊ�����±��Ǵ�0��ʼ�ģ�����num��10��Ԫ�طֱ���num[0]~num[9]������û��num[10]���Ԫ�ء�
ǰ��˵����scanf(��%*[^\n]%*c��,&a)��������ȡһ���ַ����洢��&a�����ַ��ע�����ַ������ַ�����ĩβҪ��һ����\0����
������������һ���ַ�֮�󰴻س���ʵ����Ҫ�洢�����ַ���һ������������ַ�����һ�����Զ���ӵġ�\0���������Ƕ�a�Ķ�����char a,
Ҳ����˵ֻ�ܷ���&a�ĵ�ַ�������ܷ���&a + 1�ĵ�ַ���������Ҫǿ�з��ʣ��ͻ������쳣�жϡ�*/
/*��*��^\n���������ȡ�������е�'\n'�ַ�֮ǰ�������ַ����������*��ʾ����ȡ����Щ�ַ�����ֱ������'\n'�ַ�ʱ��ֹͣ��ȡ����.
��ʱ��������������һ��'\n'�ַ����������Ժ���ģ�*c����ȡ��������������Ļ��з���������Ǻź�ǰ����Ǻ�������ͬ��
�������дӼ��̵����붼���Իس������ģ����س������һ��'\n'�ַ������Խ�'\n'��ͬ��֮ǰ���ַ�ȫ����ȡ������֮��Ҳ���൱����������뻺������*/