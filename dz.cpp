#define _CRT_SECURE_NO_WARNINGS


#include <Windows.h>
#include <cstdlib>
#include <stdio.h>
#include <ctime>


int** bin(int arr_len, int* arr_dec, int** arr_bin, int* arr_bin_len)
{
	


	for (int i = 0; i < arr_len; ++i) 
	{


		arr_bin[i] = (int*)malloc(sizeof(int));
		int elem = arr_dec[i];


		int k = 0;
		if (elem == 0)
		{
			arr_bin[i][k] = 0;
			k++;
		}

		while (elem > 0)
		{
			arr_bin[i][k] = elem % 2;
			arr_bin[i] = (int*)realloc(arr_bin[i], sizeof(int) * (k + 2));


			elem /= 2;
			k++;
		}
		arr_bin_len[i] = k - 1;
	}
	return arr_bin;
}

int* dec(int* arr_len,  int answr2)
{
	if (answr2)
	{
		srand(time(0));
		*arr_len = rand() % 100 + 1;

		printf("Сгенерированное множество: A = {");


		int* arr_dec = (int*)malloc(sizeof(int) * (*arr_len));
		for (int i = 0; i < *arr_len; ++i)
		{
			if (i % 4 == 0 && i != 0)
				printf("\n\t\t\t\t");
			arr_dec[i] = rand() % 10000 + 1;		

			if(i == *arr_len - 1)
				printf("%d}\n\n", arr_dec[i]);
			else
				printf("%d,", arr_dec[i]);

		}

		for (int i = 0; i < *arr_len; ++i)
		{
			for (int j = i; j < *arr_len - 1; ++j)
			{
				if (arr_dec[i] == arr_dec[j + 1])
				{
					printf("\nМножество не подходит по требованиям: элементы номер %d и номер %d одинаковые\n\nПопробуйте еще раз\n\n", i + 1, j + 2);
					*arr_len = 0;
					system("pause");
					system("cls");
					arr_dec = dec(arr_len, answr2);
				}
			}
		}

		return arr_dec;
	}
	else
	{
		int* arr_dec = (int*)malloc(sizeof(int));
		printf("Введите элементы(пример {1,2,3}): A = {");
		scanf("%d", &arr_dec[0]);
		for (int i = 0; arr_dec[i] >= 0; ++i)
		{
			++*arr_len;
			
			if (getchar() == '}')
				break;

			arr_dec = (int*)realloc(arr_dec, sizeof(int) * (i + 2));
			
			scanf("%d", &arr_dec[i + 1]);
		}


		for (int i = 0; i < *arr_len; ++i)
		{
			for (int j = i; j < *arr_len - 1; ++j)
			{
				if (arr_dec[i] == arr_dec[j + 1])
				{
					printf("\nМножество не подходит по требованиям: элементы номер %d и номер %d одинаковые\n\nПопробуйте еще раз\n\n", i + 1, j + 2);
					*arr_len = 0;
					system("pause");
					system("cls");
					arr_dec = dec(arr_len, answr2);
				}
			}
		}
		return arr_dec;
	}
}

void print_dec_bin(int arr_len, int* arr_dec, int** arr_bin, int* arr_bin_len)
{
	printf("\n\nДесятичное множество: \t   A = {");
	for (int i = 0; i < arr_len; ++i)
	{
		if (i % 4 == 0 && i != 0)
			printf("\n\t\t\t\t");
		if (i == arr_len - 1)
			printf("%d}", arr_dec[i]);
		else
			printf("%d,", arr_dec[i]);
	}

	printf("\n\nДвоичное множество: \t   B = {");
	for (int i = 0; i < arr_len; ++i)
	{
		if (i % 4 == 0 && i != 0)
			printf("\n\t\t\t\t");

		for (int z = 0; (z < 4 - (arr_bin_len[i] + 1) % 4) && (arr_bin_len[i] + 1) % 4 != 0; ++z)
		{
			printf("0");
		}

		for (int g = arr_bin_len[i]; g >= 0; --g)
		{
			if ((g + 1) % 4 == 0 && arr_bin_len[i] != g && g != 0)
			{
				printf(".%d", arr_bin[i][g]);
			}
			else
			{
				printf("%d", arr_bin[i][g]);
			}

		}
		if (i == arr_len - 1)
			printf("}\n\n");
		else
			printf(", ");

	}
}

void auto_or_not()
{
	
	int arr_len = 0;
	int* arr_dec ;
	


	int answr2;
	printf("Задать элементы вручную (0) или автоматически (1)?\n");
	scanf("%d", &answr2);

	arr_dec = dec( &arr_len, answr2);

	int* arr_bin_len = (int*)malloc(sizeof(int) * arr_len);
	int** arr_bin = (int**)malloc(sizeof(int*) * arr_len);

	arr_bin = bin(arr_len, arr_dec, arr_bin, arr_bin_len);

	print_dec_bin(arr_len, arr_dec, arr_bin, arr_bin_len);
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int answr;
	
	printf("0 - Выход\n\n1 - Ввод множества\n\nВведите команду: ");
	scanf("%d", &answr);
	while (answr)
	{
		system("pause");
		system("cls");
		auto_or_not();
		printf("0 - Выход\n\n1 - Ввод множества\n\nВведите команду: ");
		scanf("%d", &answr);
	}

	system("pause");
	return 0;
}


