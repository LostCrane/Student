#include "sms_head.h"//自定义的头文件

//_CRT_SECURE_NO_WARNINGS			这部分是解决 VS2019 scanf() 和 fopen() 的报错问题（项目-属性-添加进预处理定义）
//fflush(stdin)						此函数在 VS 中无效果

#define LEN sizeof(struct Student)	//结构体的内存大小
#define XM 9						//姓名（最多四个中文）
#define SYD 9						//生源地（最多四个中文）
#define BCZJ 4						//4 字节（用作补充字节）

struct Student {
	unsigned int xh;				//学号（2020500101 <  4 294 967 295）
	char * xm;						//姓名
	char xb;						//性别（0 是男性，反之）
	unsigned int csrq;				//出生日期（20201010）
	char * syd;						//生源地
	char nl;						//年龄（不设输入）
	struct Student * next;
};

//数据的默认保存地址（相对路径），会通过学号对其修改
//目前支持的路径包括：默认地址、20194110系列、20183001系列、20172110系列
char default_address[] = { ".\\Data\\2020\\5\\0\\0\\1\\20205001.Dat" };

int main() {
	//改变控制台背景色和前景色 0 黑色，A 绿色
	system("color 0A");

	ui(0);

	printf("Bye Bye!\n");

	return 0;
}

//负责简单的交互界面
int ui(int n) {
	//i 控制循环，pick 输入选择
	int i, pick;
	// * 或 - 样式的输出个数，用作装饰
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
			default:printf("Main Input Error !\n");		Sleep(1000);//延时 1 秒
			}
			system("cls");//清屏
		}
	}break;

		//Search UI 11
	case 11: {
		system("cls");//清屏
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
			system("cls");	//清屏
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
			system("cls");	//清屏
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
			system("cls");	//清屏
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
	// t 链表的头指针，p 链表的变动指针
	struct Student* t, * p;
	//存放缓存流中不需要的数据
	char scanf_stdin = 0;

	if (ui(21)) {
		return;
	}

	//为链表分配内存地址空间 24 字节(4 * 6),因为结构体内存的问题，这里 char 实际是占用 4 字节（只是在内存中），但只使用 1 字节（详见计算机组成原理）
	t = p = (struct Student*)malloc(LEN);
	while (1) {
		goto A;
		printf("Please input 学号：\t\t\t");
		scanf("%u", &(p->xh));						check(1, &(p->xh));//检查输入有效性

		printf("Please input 姓名（仅支持四个汉字）：\t");		p->xm = (char*)malloc(XM);		scanf("%s", p->xm);

		printf("Please input 性别 男/女(0/1)：\t\t");	while ((scanf_stdin = getchar()) != 10);//清空缓存流
		scanf("%c", &(p->xb));						check(2, &(p->xb));//检查输入有效性
		A:
		printf("Please input 出生日期 (20010101）：\t");
		scanf("%u", &(p->csrq));			p->nl = check(3, &(p->csrq));//检查输入有效性	

		printf("Please input 生源地（仅支持四个汉字）：\t");	p->syd = (char*)malloc(SYD);	scanf("%s", p->syd);

		switch (ui(22)) {
			case 0:	p->next = NULL;			io(1, t);							return;	//保存并退出：为尾节点赋予空指针同时保存到文件后退出
			case 1:	p->next = (struct Student*)malloc(LEN);		p = p->next;	break;	//继续输入：为尾节点开辟新的内存地址空间
			case 2:	break;																//修改本次输入：不做操作重跑一次
			default:printf("Input Error !(Not Search)\n");	Sleep(1000);	system("cls");
		}
	}
}

void Search() {
	//冒泡算法起始指针 p，对比指针 m，头指针 t
	struct Student* p, * m, * t;

	//中间变量，排序时使用
	unsigned int id;
	char age;

	unsigned int x;//学号

	ui(11);
	scanf("%u", &x);
	//确保退出
	if (x == 0) {
		return;
	}

	//根据学号读取该学号所在文件的全部数据，返回组成链表的头指针
	t = p = io(2, x);

	while (1) {
		//m 是 p 结构体中指向的下一个结构体
		m = p->next;

		switch (ui(12)) {
		case 0:		return;

		//使用冒泡算法进行排序
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

		//使用冒泡算法进行排序
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
			printf("学号:%u\t\t", p->xh);
			printf("姓名:%s\n", p->xm);
			switch (p->xb) {
			case 48:printf("性别:男\t\t"); break;
			case 49:printf("性别:女\t\t");
			}
			printf("年龄:%d\n", p->nl);
			printf("出生日期:%u\t\t", p->csrq);
			printf("生源地:%s\n", p->syd);
		}
	}
}

void Delete() {
	struct Student* t;

	unsigned int x;//学号

	while (1) {
		switch (ui(31)) {
		case 0:	return;

		case 1: {
			printf("Please input Student ID : ");
			scanf("%u", &x);
			//根据学号读取该学号所在文件的全部数据，返回组成链表的头指针
			t = io(2, x);

			if (ui(32)) {
				//重新写入数据，将删除的数据不写入
				io(3, t);
				printf("Deletion Complete\n");
			}
		}

		}
	}
}

void Modify() {
	struct Student* t;

	unsigned int x;//学号

	while (1) {
		switch (ui(41)) {
		case 0:	return;
		case 1:
			printf("Please input Student ID : ");
			scanf("%u", &x);
			//根据学号读取该学号所在文件的全部数据，返回组成链表的头指针
			t = io(2, x);
			if (ui(42)) {
				//重新写入数据
				io(4, t);
				printf("Modify Complete\n");
			}
		}
	}
}

//i = 1(Add), 2(Read), 3(Dele), 4(Modify), 对文件的IO操作
struct Student* io(int i, ...) {
	FILE* fp;
	struct Student* t;
	// p 是第二个参数，是写入文件的链表头指针
	struct Student* p = NULL;
	// x 是第三个参数，存放查找的学号，为防止 i = 1 时误调用，故初始化为 0
	unsigned int x = 0;
	//文件内数据的数量
	int u;

	/*访问未命名的参数，首先必须在可变参数函数中声明va_list类型的变量。调用va_start并传入两个参数：
	第一个参数为va_list类型的变量，
	第二个为省略号前最后一个有名字的参数的名称，接着每一调用va_arg就会返回下一个参数，va_arg的第一个参数为va_list，第二个参数为返回的类型。
	最后va_end必须在函数返回前被va_list调用(va_list当作参数)(没有要求要读取完所有参数)。*/

	//定义 va_list 类型变量
	va_list ap;
	//使 va_list 指向可变参数的起始的参数
	va_start(ap, i);
	//依据 i 的值确定本次调用函数的操作功能
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
	va_end(ap);//释放 va_list，释放时的这个参数，仍然可用


	switch (i) {
		//Add
	case 1: {
		//打开文件，向二进制文件尾添加数据（以“ab”形式）
		if ((fp = fopen(address(p->xh), "ab")) == NULL) {
			printf("File Output Error !\n");
			exit(0);
		}

		//将链表数据写入文件
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
		//打开文件，从二进制文件中读取数据（以“rb”形式）
		if ((fp = fopen(address(p->xh), "rb")) == NULL) {
			printf("File Input Error !\n");
			exit(0);
		}

		t = p = (struct Student*)malloc(LEN);

		//将文件内标识指针移至文件末尾，以配合下一步操作
		fseek(fp, 0, 2);
		//文件字节数 / 结构体数据的大小（非结构体大小） = 文件内的信息单位数。在将标识指针移回至文件首部。
		//结构体数据大小包括：学号 4， 姓名 9， 性别 1， 出生日期 4， 生源地 9， 年龄 1
		for (u = ftell(fp) / (sizeof(unsigned int) + XM + sizeof(char) + sizeof(unsigned int) + SYD + sizeof(char)), fseek(fp, 0, 0); ; p->next = (struct Student*)malloc(LEN), p = p->next) {
			//分配内存地址空间
			p->xm = (char*)malloc(XM);
			p->syd = (char*)malloc(SYD);
			//读取文件数据到链表
			fread(&(p->xh), sizeof(unsigned int), 1, fp);
			fread(p->xm, XM, 1, fp);
			fread(&(p->xb), sizeof(char), 1, fp);
			fread(&(p->csrq), sizeof(unsigned int), 1, fp);
			fread(p->syd, SYD, 1, fp);
			fread(&(p->nl), sizeof(char), 1, fp);

			//根据参数 x 查找匹配的信息
			if (p->xh == x) {
				printf("学号:%u\t\t", p->xh);
				printf("姓名:%s\n", p->xm);
				switch (p->xb) {
				case 48:printf("性别:男\t\t"); break;
				case 49:printf("性别:女\t\t");
				}
				printf("年龄:%d\n", p->nl);
				printf("出生日期:%u\t\t", p->csrq);
				printf("生源地:%s\n", p->syd);

			}

			//当循环次数 = 信息数
			if (++i == u) {
				p->next = NULL;
				break;
			}
		}
		fclose(fp);//关闭文件

		return t;//返回读取链表的首指针
	}break;

		//Dele
	case 3: {
		//这里实现的方法是先删除文件，然后重新创建文件并写入数据
		if (remove(address(p->xh)) != 0) {
			printf("File Dele Error !\n");
		}

		//打开文件，向二进制文件添加数据（以“wb”形式）
		if ((fp = fopen(address(p->xh), "wb")) == NULL) {
			printf("File Output Error !\n");
			exit(0);
		}

		//将链表数据写入文件
		for (; p != NULL; p = p->next) {
			//不将删除所匹配的信息写入文件
			if (p->xh == x) {
				//关闭文件，放弃本次循环
				fclose(fp);
				continue;
			}

			//将链表数据写入文件
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
		//这里实现的方法是先删除文件，然后重新创建文件并写入数据
		if (remove(address(p->xh)) != 0) {
			printf("File Dele Error !\n");
		}

		//打开文件，向二进制文件添加数据（以“wb”形式）
		if ((fp = fopen(address(p->xh), "wb")) == NULL) {
			printf("File Output Error !\n");
			exit(0);
		}

		//将链表数据写入文件
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

//供 io 函数选择地址使用，依据输入的学号更改文件的相对路径
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

//i = 1(xh), 2(xb), 3(csrq), 供 Add 函数检查输入有效性
char check(int i, ...) {
	//数据接收变量
	char* xb;
	unsigned int* xh, * csrq;
	//存放缓存流中不需要的数据
	char scanf_stdin = 0;
	//时间类型的变量和数据结构，用来处理出生日期的相关操作
	time_t t;
	struct tm* lt;
	//不定参数的接受变量
	va_list ap;
	va_start(ap, i);

	time(&t);//获取Unix时间戳
	lt = localtime(&t);//转为 tm 数据结构

	switch (i) {
		//检查学号
	case 1: {
		xh = va_arg(ap, unsigned int*);
		while (1) {
			//取出学号前四位，检查是否是 本年 或是 少六年
			if (*xh / 1000000 >= lt->tm_year + 1900 || *xh / 1000000 <= lt->tm_year + 1900 - 6) {
				printf("Input Error ! Again Input:\t\t");
				scanf("%u", xh);
				continue;
			}
			else break;
		}
	}break;

		//检查性别
	case 2: {
		xb = va_arg(ap, char*);
		while ((scanf_stdin = getchar()) != 10);//清空缓存流
		while (1) {
			if (*xb != 48 && *xb != 49) {
				printf("Input Error ! Again Input:\t\t");
				scanf("%c", xb);
				while ((scanf_stdin = getchar()) != 10);//清空缓存流
			}
			else break;
		}
	}break;

		//检查出生日期
	case 3: {
		csrq = va_arg(ap, unsigned int*);
		while (1) {
			//年份在 50 年内，同时不在 10 年内
			if (*csrq / 10000 >= lt->tm_year + 1900 - 50 && *csrq / 10000 <= lt->tm_year + 1900 - 10) {
				switch ((*csrq / 100) % 100) {
					//若年份符合，当 1 3 5 7 8 10 12月份时
				case 1:	case 3:	case 5:	case 7:	case 8:	case 10:	case 12: {
					//日期不能 > 31
					if (*csrq % 100 > 31) {
						printf("Input Error ! Again Input:\n");		Sleep(1000);
						scanf("%u", csrq);		continue;
					}
				}break;

					//若年份符合，当 4 6 9 11月份时
				case 4:	case 6:	case 9:	case 11: {
					//日期不能 > 30
					if (*csrq % 100 > 30) {
						printf("Input Error ! Again Input:\n");		Sleep(1000);
						scanf("%u", csrq);		continue;
					}
				}break;

					// 2 月份特殊处理
				case 2: {
					//判断闰年
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
					//检查日期
					if (i) {
						//闰年 < 30
						if (*csrq % 100 > 29) {
							printf("Input Error ! Again Input:\n");		Sleep(1000);
							scanf("%u", csrq);	continue;
						}
					}
					else {//反之 < 29
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
			//年份不符合标准时
			else {
				printf("Input Error ! Again Input:\t\t");		Sleep(1000);
				scanf("%u", csrq);				continue;
			}

			//当系统月份 = 出生日期月份，继续比较日期大小
			//mon 是 tm 时间的结构体中放月份的变量，因从 0 开始，所以 + 1
			if (lt->tm_mon + 1 == (*csrq / 100) % 100) {
				//当今天日期大于生日时，虚岁与周岁差一岁
				if (lt->tm_mday > *csrq % 100) {
					va_end(ap);
					return lt->tm_year - (*csrq / 10000 - 1970) - 1;
				}
				//反之，包括生日当天，差两岁
				else {
					va_end(ap);
					return lt->tm_year - (*csrq / 10000 - 1970) - 2;
				}
			}
			//当系统月份 < 出生日期月份，差两岁
			else {
				if (lt->tm_mon + 1 < (*csrq / 100) % 100) {
					va_end(ap);
					return lt->tm_year - (*csrq / 10000 - 1970) - 2;
				}
				//当系统月份 > 出生日期月份，差一岁
				else {
					va_end(ap);
					return lt->tm_year - (*csrq / 10000 - 1970) - 1;
				}
			}
		}
	}

	}
}

/*程序输出结果是正确的，但是却引发了异常中断，中断信息为:Run-Time Check Failure #2 - Stack around the variable ‘a’ was corrupted.
从网上搜了一下，这是因为栈被破坏了。
最常引起这种错误的情形是对数组进行操作时，比如说定义一个 int num[10]这样的数组，当你想要改变num[10]的值时，就会引发异常中断，
这是因为数组下表是从0开始的，数组num的10个元素分别是num[0]~num[9]，根本没有num[10]这个元素。
前面说过，scanf(“%*[^\n]%*c”,&a)是用来读取一行字符串存储到&a这个地址，注意是字符串，字符串的末尾要有一个’\0’，
这样当你输入一个字符之后按回车，实际上要存储两个字符，一个是你输入的字符，另一个是自动添加的’\0’，而我们对a的定义是char a,
也就是说只能访问&a的地址，而不能访问&a + 1的地址，如果你想要强行访问，就会引发异常中断。*/
/*％*〔^\n〕将逐个读取缓冲区中的'\n'字符之前的其它字符，％后面的*表示将读取的这些字符丢弃直到遇到'\n'字符时便停止读取操作.
此时，缓冲区中尚有一个'\n'字符遗留，所以后面的％*c将读取并丢弃这个遗留的换行符，这里的星号和前面的星号作用相同。
由于所有从键盘的输入都是以回车结束的，而回车会产生一个'\n'字符，所以将'\n'连同它之前的字符全部读取并丢弃之后，也就相当于清除了输入缓冲区。*/