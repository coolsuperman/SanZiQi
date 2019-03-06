//实现一个电话本，使得，增加，删除，修改，查找，打印全部，按姓名排序，清空所有记录
#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"

int main()
{
	FILE* fp1 = fopen("../PhoneBook.txt", "w");
	fclose(fp1);
	printf("%s","通话录:");
	PhoneBook FirstBook;
	InitBook(&FirstBook);
	Load(FirstBook);
	fun ChooseFun[10] = { AddContact,DeletContact,ChangeContact,FindContact,PrintAll,SortbyName,CleanAll};
	int choice = 0;
	do
	{
		choice = menu();
		if (choice)
		{
			ChooseFun[choice - 1](&FirstBook);
			printf("\n");
			ChooseFun[4](&FirstBook);
		}
	} while (choice);
	Save(FirstBook);
	free(FirstBook.Book);
	system("pause");
	return 0;
}
