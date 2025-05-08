#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define data_base_size 2
#define max_len 10

struct abonent
{
	char name[max_len];
	char second_name[max_len];
	char tel[max_len];
};

void InitializationAbonentsList(struct abonent data_base[]);
void AddAbonent(struct abonent data_base[], int *index);
void RemoveAbonent(struct abonent data_base[], int *index);
void FixDataBaseAfterRemove(struct abonent data_base[], int index, int indexToDelete);
void FindAbonentsByName(struct abonent data_base[], int index);
void ShowAllAbonents(struct abonent data_base[], int index, int flag);


int main(void)
{
	int choice, index = 0;
	char symbol;
	struct abonent data_base[data_base_size];
	
	InitializationAbonentsList(data_base);
	
	while(1)
	{
		system("clear");
		printf("1) Добавить абонента\n");
		printf("2) Удалить абонента\n");
		printf("3) Поиск абонентов по имени\n");
		printf("4) Вывод всех записей\n");
		printf("5) Выход\n");
		
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				system("clear");
				AddAbonent(data_base, &index);
				break;
			case 2:
				system("clear");
				RemoveAbonent(data_base, &index);
				break;
			case 3:
				system("clear");
				FindAbonentsByName(data_base, index);
				break;
			case 4:
				system("clear");
				ShowAllAbonents(data_base, index, 1);
				break;
			case 5:
				printf("Досвидания!\n");
				fflush(stdout);
				sleep(2);
				system("clear");
				exit(0);
			default:
				printf("Выберите существующую опцию!");
				break;
		}
	}
	
	return 0;
}

void InitializationAbonentsList(struct abonent data_base[])
{
	for(int i = 0; i < data_base_size; i++)
	{
		memset(data_base[i].name, '\0', sizeof(data_base[i].name));
		memset(data_base[i].second_name, '\0', sizeof(data_base[i].second_name));
		memset(data_base[i].tel, '\0', sizeof(data_base[i].tel));
	}
}

void AddAbonent(struct abonent data_base[], int *index)
{	
	int symbol;
	char name[max_len] = { '\0' }, second_name[max_len] = { '\0' }, tel[max_len] = { '\0' };
	
	if(*index >= data_base_size)
	{
		printf("Произошла ошибка при добавлении абонента! Доступный размер в базе данных: %d; номер абонента, которого хотите добавить: %d\n", data_base_size, *index + 1);
		while((symbol = getchar()) != EOF && symbol != '\n') {}
		printf("Для продолжения нажмите любую клавишу!\n");
		getchar();
		return;
	}
	
	
	printf("Введите имя человека: \n");
	scanf("%s", name);
	name[strcspn(name, "\n")] = '\0';
	if(strlen(name) > max_len)
	{
		printf("Имя не может превышать заданную длину: %d\n", max_len);
		while((symbol = getchar()) != EOF && symbol != '\n') {}
		printf("Для продолжения нажмите любую клавишу!\n");
		getchar();
		return;
	}
	
	printf("\nВведите фамилию человека: \n");
	scanf("%s", second_name);
	second_name[strcspn(second_name, "\n")] = '\0';
	if(strlen(second_name) > max_len)
	{
		printf("Фамилия не может превышать заданную длину: %d\n", max_len);
		while((symbol = getchar()) != EOF && symbol != '\n') {}
		printf("Для продолжения нажмите любую клавишу!\n");
		getchar();
		return;
	}
	
	printf("\nВведите телефон человека: \n");
	scanf("%s", tel);
	tel[strcspn(tel, "\n")] = '\0';
	if(strlen(tel) > max_len)
	{
		printf("Телефон не может превышать заданную длину: %d\n", max_len);
		while((symbol = getchar()) != EOF && symbol != '\n') {}
		printf("Для продолжения нажмите любую клавишу!\n");
		getchar();
		return;
	}
	

	strcpy(data_base[*index].name, name);
	strcpy(data_base[*index].second_name, second_name);
	strcpy(data_base[*index].tel, tel);
	*index = *index + 1;
	printf("Абонент успешно добавлен!\n");

	
	memset(name, '\0', sizeof(name));
	memset(second_name, '\0', sizeof(second_name));
	memset(tel, '\0', sizeof(tel));
	
	while((symbol = getchar()) != EOF && symbol != '\n') {}
	printf("Для продолжения нажмите любую клавишу!\n");
	getchar();
}

void RemoveAbonent(struct abonent data_base[], int *index)
{
	int indexToDelete, symbol;
	
	if(*index == 0)
	{
		printf("База данных пуста! Неского удалять!\n");
		while((symbol = getchar()) != EOF && symbol != '\n') {}
		printf("Для продолжения нажмите любую клавишу!\n");
		getchar();
		return;
	}
	else
	{
		ShowAllAbonents(data_base, *index, 0);
		printf("Введите номер абонента, которого хотите удалить: ");
		scanf("%d", &indexToDelete);
		
		memset(data_base[indexToDelete - 1].name, '\0', sizeof(data_base[indexToDelete - 1].name));
		memset(data_base[indexToDelete - 1].second_name, '\0', sizeof(data_base[indexToDelete - 1].second_name));
		memset(data_base[indexToDelete - 1].tel, '\0', sizeof(data_base[indexToDelete - 1].tel));
		
		FixDataBaseAfterRemove(data_base, *index, indexToDelete);
		*index = *index - 1;
		
		printf("\nАбонент успешно удален!\n");
		
		while((symbol = getchar()) != EOF && symbol != '\n') {}
		printf("Для продолжения нажмите любую клавишу!\n");
		getchar();
	}
}

void FixDataBaseAfterRemove(struct abonent data_base[], int index, int indexToDelete)
{
	for(int i = indexToDelete - 1; i < index; i++)
	{
		strcpy(data_base[i].name, data_base[i + 1].name);
		strcpy(data_base[i].second_name, data_base[i + 1].second_name);
		strcpy(data_base[i].tel, data_base[i + 1].tel);
	}
}

void FindAbonentsByName(struct abonent data_base[], int index)
{
	int symbol, flag = 0;
	char name[max_len];
	printf("Введите имя, которое хотите найти в справочнике: ");
	scanf("%s", name);
	
	for(int i = 0; i < index; i++)
	{
		if(!strcmp(data_base[i].name, name))
		{
			printf("%d) ", i + 1);
			printf("%s ", data_base[i].name);
			printf("%s ", data_base[i].second_name);
			printf("%s\n", data_base[i].tel);
		}
	}
	
	if(!flag)
	{
		printf("Абонента с таким именем нет в справочнике!\n");
	}
	
	memset(name, '\0', sizeof(name));
	
	while((symbol = getchar()) != EOF && symbol != '\n') {}
	printf("Для продолжения нажмите любую клавишу!\n");
	getchar();
}

void ShowAllAbonents(struct abonent data_base[], int index, int flag)
{
	int symbol;
	
	printf("Список абонентов: \n");
	
	if(index == 0)
	{
		printf("Телефонная книга пуста!\n");
		while((symbol = getchar()) != EOF && symbol != '\n') {}
		printf("Для продолжения нажмите любую клавишу!\n");
		getchar();
		return;
	}
	else
	{
		for(int i = 0; i < index; i++)
		{
			printf("%d) ", i + 1);
			printf("%s ", data_base[i].name);
			printf("%s ", data_base[i].second_name);
			printf("%s\n", data_base[i].tel);
		}
	}
	
	if(flag)
	{
		while((symbol = getchar()) != EOF && symbol != '\n') {}
		printf("Для продолжения нажмите любую клавишу!\n");
		getchar();
	}
}
