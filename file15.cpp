// file15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "common.h"

#define ENDLF(x) fwrite("\n", sizeof(char), 1, x)
#define MAX_CHILDS 9


struct Node
{
	Node* m_Par;
	Node* m_childs[MAX_CHILDS + 1];
	size_t m_cSize;

	int m_ID;
};

bool addNode(Node* parent, Node* newN)
{
	if (parent->m_cSize < MAX_CHILDS)
		return false;
	parent->m_cSize++;
	parent->m_childs[parent->m_cSize] = newN;
	newN->m_Par = parent;
	return true;
};

void delNode(Node* nd)
{
	if (nd->m_Par)
	{
		for (size_t i = 0; i < nd->m_Par->m_cSize; i++)
		{
			if (nd->m_Par->m_childs[i] == nd)
			{
				nd->m_Par->m_childs[i] = nullptr;
			}
		}
	};

	for (size_t i = 0; i < nd->m_cSize; i++)
		if (nd->m_childs[i])
			delNode(nd->m_childs[i]);

	delete nd;
};

Node* FindNode(Node* pFrom, int id)
{
	return nullptr;
};

Node* NewNode(int id)
{
	Node* pNode = new Node;
	pNode->m_ID = id;
	pNode->m_Par = nullptr;
	pNode->m_cSize = 0;

	return pNode;
};

int main3()
{
	Node* pRoot = NewNode(0);

	Node* p = NewNode(1);
	addNode(pRoot,p);

	addNode(p, NewNode(11));
	addNode(p, NewNode(12));

	p = NewNode(2);
	addNode(pRoot, p);

	addNode(p, NewNode(21));

	return 0;
}


struct Student
{
	int id;
	char Name[128];
	char Surname[128];
	int Age;

	Student* pNext;
};



Student* Construct(int newId, char* name, char* srname, int age)
{
	Student* p = new Student;
	p->id = newId;
	p->pNext = nullptr;
	return p;
}

int main()
{
	setlocale(LC_ALL, "russian");
	FILE* pFile;
	fopen_s(&pFile, "test.txt", "w+");
	if (!pFile)
	{
		printf("File can not be opened");
		return 404;
	}
	printf("Файл открыт");
	char name[128];
	char surname[128];

	int age;
	size_t len;
	size_t lens;
	printf("Введите 'closeIt' в имя следующего персонажа, чтобы закрыть программу \n");
	printf("Введите ваш текст ниже \n");
	int id = 0;
	do
	{
		id++;
		printf("Введите имя персонажа \n");
		std::cin.getline(name, 128);
		if (!strcmp(name, "closeIt"))
		{
			printf("Пока");
			break;
		}
		printf("Введите фамилию персонажа \n");
		std::cin.getline(surname, 128);
		printf("Введите возраст \n");
		std::cin >> age;

		Construct(id, name, surname, age);

		fwrite("Student ID: ", sizeof(char), 13, pFile);
		//fwrite((char*)id, sizeof(char), sizeof(id), pFile);
		ENDLF(pFile);
		fwrite("Name: ", sizeof(char), 7, pFile);
		lens = strlen(name);
		fwrite(name, sizeof(char), sizeof(name), pFile);
		ENDLF(pFile);
		fwrite("Surname: ", sizeof(char), 10, pFile);

		lens = strlen(surname);
		fwrite(surname, sizeof(char), lens, pFile);
		ENDLF(pFile);
		fwrite("Age: ", sizeof(char), 6, pFile);
		//fwrite((char*)age, sizeof(char), sizeof(age), pFile);
		ENDLF(pFile);

		lens = strlen(name);
		len = fwrite(name, sizeof(char), lens, pFile);
		if (len != lens)
		{
			printf("Something wrong 1 \n");
			break;
		}
		ENDLF(pFile); ENDLF(pFile); ENDLF(pFile);
	} while (1);

	fclose(pFile);
	return 0;
}

int main2()
{
	setlocale(LC_ALL, "russian");
	FILE* pFile;
	fopen_s(&pFile, "test.txt", "r+");
	if (!pFile)
	{
		printf("Не откривается, шось не так");
		return 404;
	}
	printf("Файл открыт\nЧитаем\n");
	size_t len;
	char buf[9];
	while (len = fread(buf, sizeof(char), sizeof(buf) - 1, pFile))
	{
		buf[len] = 0;
		printf("%s", buf);
	}
	fclose(pFile);
	printf("\n\n");

	fopen_s(&pFile, "test.txt", "a+");
	if (!pFile)
	{
		printf("Не откривается, шось не так");
		return 404;
	}
	char input[128];
	printf("Введите 'closeIt' чтобы закрыть программу \n");
	printf("Введите ваш текст ниже \n");
	do
	{
		std::cin.getline(input, 128);
		if (!strcmp(input, "closeIt"))
		{
			printf("Пока");
			break;
		}
		size_t lens = strlen(input);
		len = fwrite(input, sizeof(char), lens, pFile);
		if (len != lens)
		{
			printf("Something wrong \n");
			break;
		}
		len = fwrite("\n", sizeof(char), 1, pFile);
		if (len != 1)
		{
			printf("Something wrong \n");
			break;
		}
	} while (1);
	fclose(pFile);
	return 0;
}

int main1()
{
	setlocale(LC_ALL, "russian");
	FILE* pFile;
	fopen_s(&pFile, "test.txt", "w");
	if (!pFile)
	{
		printf("File can not be opened");
		return 404;
	}
	printf("Файл открыт");
	char input[128];
	size_t len;
	printf("Введите 'closeIt' чтобы закрыть программу \n");
	printf("Введите ваш текст ниже \n");
	do
	{
		std::cin.getline(input, 128);
		if (!strcmp(input, "closeIt"))
		{
			printf("Пока");
			break;
		}
		size_t lens = strlen(input);
		len = fwrite(input, sizeof(char), lens, pFile);
		if (len != lens)
		{
			printf("Something wrong \n");
			break;
		}
		len = fwrite("\n", sizeof(char), 1, pFile);
		if (len != 1)
		{
			printf("Something wrong \n");
			break;
		}
	} while (1);

	fclose(pFile);
	return 0;
}