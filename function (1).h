#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctime>
struct Date
{
	char startTime;
	char endTime;
};
typedef struct Date date;
struct ToDo
{
	char buffer[101];
	int severity;
	int count;
	date data;
	int complete;
	struct ToDo *next;
};
//
time_t now = time(NULL);
tm *t = localtime(&now);
char *ch1 = asctime(t);
//
typedef struct ToDo todo;
todo *start = NULL;
void adjustcount()
{
	todo *temp;
	int i = 1;
	temp = start;
	while (temp != NULL)
	{
		temp->count = i;
		i++;
		temp = temp->next;
	}
}
todo *addGlo, *tempGlo;
void createtodo()
{
	char check;
	system("cls");
	while (17)
	{
		printf("\nNHAP 'Y' DE TAO TODO-NHAP 'N' DE THOAT ");
		fflush(stdin);
		scanf("%s", &check);
		if (check == 'N' || check == 'n')
			break;
		else if (check == 'Y' || check == 'y')
		{
			if (start == NULL)
			{
				addGlo = (todo *)calloc(1, sizeof(todo));
				start = addGlo;
				printf("\nMOI BAN NHAP TODO MOI:");
				fflush(stdin);
				gets(addGlo->buffer);
				printf("\nMOI BAN NHAP MUC DO QUAN TRONG CUA TODO: ");
				fflush(stdin);
				fflush(stdin);
				do
				{
					printf("\nMUC DO QUAN TRONG(1:CUC KI QUAN TRONG, 2 QUAN TRONG, 3 IT QUAN TRONG): ");
					scanf("%d", &addGlo->severity);
				} while (addGlo->severity != 1 && addGlo->severity != 2 && addGlo->severity != 3);
				printf("\nMOI BAN NHAP THOI GIAN BAT DAU CONG VIEC: ");
				fflush(stdin);
				scanf("%d", &addGlo->data.startTime);
				do
				{
					printf("\nMOI BAN NHAP THOI GIAN KET THUC CONG VIEC: ");
					fflush(stdin);
					scanf("%d", &addGlo->data.endTime);
					if (addGlo->data.endTime < addGlo->data.startTime || addGlo->data.endTime > 24)
					{
						printf("\nNHAP SAI! THOI GIAN KET THUC PHAI LON HON THOI GIAN BAN DAU.MOI BAN NHAP LAi! ");
					}
				} while (addGlo->data.endTime < addGlo->data.startTime || addGlo->data.endTime > 24);
				addGlo->complete = 0;
				addGlo->count = 1;
				start->next = NULL;
			}
			else
			{
				tempGlo = (todo *)calloc(1, sizeof(todo));
				printf("\n\nMOI BAN NHAP TODO MOI:");
				fflush(stdin);
				gets(tempGlo->buffer);
				fflush(stdin);
				do
				{
					printf("\nMUC DO QUAN TRONG(1:CUC KI QUAN TRONG, 2 QUAN TRONG, 3 IT QUAN TRONG): ");
					scanf("%d", &tempGlo->severity);
				} while (tempGlo->severity != 1 && tempGlo->severity != 2 && tempGlo->severity != 3);
				printf("\nMOI BAN NHAP THOI GIAN BAT DAU CONG VIEC: ");
				fflush(stdin);
				scanf("%d", &tempGlo->data.startTime);
				do
				{
					printf("\nMOI BAN NHAP THOI GIAN KET THUC CONG VIEC: ");
					fflush(stdin);
					scanf("%d", &tempGlo->data.endTime);
					if (tempGlo->data.endTime < tempGlo->data.startTime || tempGlo->data.endTime > 24)
					{
						printf("\nNHAP SAI! THOI GIAN KET THUC PHAI LON HON THOI GIAN BAN DAU.MOI BAN NHAP LAi! ");
					}
				} while (tempGlo->data.endTime < tempGlo->data.startTime || tempGlo->data.endTime > 24);
				tempGlo->complete = 0;
				tempGlo->next = NULL;
				addGlo->next = tempGlo;
				addGlo = addGlo->next;
			}
			adjustcount();
		}
		else
		{
			printf("\n\n\t\t\t\t\tSAI CU PHAP, MOI BAN NHAP LAI!");
			sleep(1);
			createtodo();
		}
	}
}

void seetodo()
{

	system("cls");
	todo *temp;
	temp = start;
	if (start == NULL)
		printf("\n\n\t\t\t\t\tTUYET VOI BAN DA HOAN THANH TODO HOM NAY \n");
	while (temp != NULL)
	{
		printf("\nVIEC %d.)", temp->count);
		puts(temp->buffer);
		fflush(stdin);
		printf("\nMUC DO QUAN TRONG CUA CONG VIEC: ");
		if (temp->severity == 1)
		{
			printf("CUC KI QUAN TRONG");
		}
		else if (temp->severity == 2)
		{
			printf("QUAN TRONG");
		}
		else
		{
			printf("IT QUAN TRONG");
		}
		fflush(stdin);
		printf("\nTHOI GIAN THUC HIEN CONG VIEC:%dH-%dH", temp->data.startTime, temp->data.endTime);
		if (temp->data.endTime < t->tm_hour)
		{
			printf("\nMUC DO HOAN THANH:DA QUA HAN");
		}
		else
		{
			if (temp->complete == 0)
			{
				printf("\nMUC DO HOAN THANH:CHUA HOAN THANH");
			}
			else
			{
				printf("\nMUC DO HOAN THANH:DA HOAN THANH");
			}
		}
		temp = temp->next;
	}
	printf("\n\n\n");
}
void unfinishTodo()
{
	system("cls");
	todo *temp = start;
	int i = 0;
	if (temp == NULL)
	{
		printf("\nBAN CHUA NHAP TODO NGAY %d/%d/%d", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->complete == 0 && temp->data.endTime > t->tm_hour)
			{
				i++;
				printf("\n%d) %s ", temp->count, temp->buffer);
				printf("THOI GIAN CON LAI DE HOAN THANH:%dH:%dP", (temp->data.endTime - t->tm_hour), t->tm_min);
			}
			temp = temp->next;
		}
	}
	printf("\n\n\n");
	system("pause");
}
void overdueTodo()
{
	system("cls");
	todo *temp = start;
	if (temp == NULL)
	{
		printf("\nTUYET VOI KHONG CO TODO NAO HET HAN");
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->data.endTime < t->tm_hour && temp->complete != 1)
			{
				printf("\nTO DO: %s DA HET HAN TU %d:%dPHUT TRUOC ", temp->buffer, (t->tm_hour - temp->data.endTime), t->tm_min);
			}
			temp = temp->next;
		}
	}
	printf("\n\n\n");
}
void rankTodo()
{
	system("cls");
	todo *temp = start, *temp2 = start, *temp3 = start;
	if (temp == NULL)
	{
		printf("\nTUYET VOI BAN DA HOAN THANH TODO HOM NAY");
	}
	else
	{
		int i;
		i = 1;
		printf("\nDANH SACH TODO CAN LAM SAP THEO MUC DO CONG VIEC: ");
		while (temp != NULL)
		{
			if (temp->severity == 1 && temp->data.endTime > t->tm_hour)
			{
				printf("\n%d.%s", i, temp->buffer);
				printf("\nMUC DO: CUC KI QUAN TRONG");
				printf("\nTHOI GIAN CON LAI DE HOAN THANH:%dH:%dP", (temp->data.endTime - t->tm_hour), t->tm_min);
				i++;
			}
			temp = temp->next;
		}
		while (temp2 != NULL)
		{
			if (temp2->severity == 2 && temp2->data.endTime > t->tm_hour)
			{
				printf("\n%d.%s", i, temp2->buffer);
				printf("\nMUC DO: QUAN TRONG");
				printf("\nTHOI GIAN CON LAI DE HOAN THANH:%dH:%dP", (temp2->data.endTime - t->tm_hour), t->tm_min);
				i++;
			}
			temp2 = temp2->next;
		}
		while (temp3 != NULL)
		{
			if (temp3->severity == 3 && temp3->data.endTime > t->tm_hour)
			{
				printf("\n%d.%s", i, temp3->buffer);
				printf("\nMUC DO: IT QUAN TRONG");
				printf("\nTHOI GIAN CON LAI DE HOAN THANH:%dH:%dP", (temp3->data.endTime - t->tm_hour), t->tm_min);
				i++;
			}
			temp3 = temp3->next;
		}
	}
	printf("\n\n\n");
	system("pause");
}
void completeTodo()
{
	system("cls");
	todo *temp1 = start, *temp2 = start;
	int i = 0;
	while (temp1 != NULL)
	{
		if (temp1->complete == 1)
		{
			i++;
		}
		temp1 = temp1->next;
	}
	if (i > 0)
	{
		if (i != 1)
		{
			printf("\nCAC TODO DA HOAN THANH: ");
		}
		else
		{
			printf("\nTODO DA HOAN THANH: ");
		}
		while (temp2->complete == 1)
		{
			printf("\n%s", temp2->buffer);
			temp2 = temp2->next;
		}
	}
	else
	{
		printf("\nBAN CHUA HOAN THANH TODO NAO TRONG NGAY %d/%d/%d", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
	}
	printf("\n\n\n");
	system("pause");
}
void repairTodo()
{
	system("cls");
	int x, index;
	todo *repair;
	repair = start;
	if (repair == NULL)
	{
		printf("\nCHUA CO TODO NAO DUOC TAO");
	}
	else
	{
		seetodo();
		printf("NHAP THU TU TODO MUON BAN MUON SUA: ");
		scanf("%d", &x);
		system("cls");
		printf("\nNHAP '1' DE SUA TOAN BO TODO");
		printf("\nNHAP '2' DE SUA TEN TODO");
		printf("\nNHAP '3' DE SUA MUC DO HOAN THANH CUA TODO");
		printf("\nNHAP '4' DE SUA MUC DO QUAN TRONG CUA TODO");
		printf("\nNHAP '5' DE SUA THOI GIAN BAT DAU VA KET THUC CUA TODO");
		printf("\nNHAP '6' DE QUAN LAI");
		printf("\nNHAP LUA CHON CUA BAN:");
		scanf("%d", &index);
		system("cls");
		switch (index)
		{
		case 1:
			if (repair != NULL)
			{
				while (17)
				{
					if (repair->count == x)
					{
						printf("\n\nMOI BAN NHAP LAI TODO: .....\n");
						fflush(stdin);
						gets(repair->buffer);
						fflush(stdin);
						do
						{
							printf("\nMUC DO QUAN TRONG(1:CUC KI QUAN TRONG, 2 QUAN TRONG, 3 IT QUAN TRONG): ");
							scanf("%d", &repair->severity);
							if (repair->severity != 1 && repair->severity != 2 && repair->severity != 3)
							{
								printf("\nSAI CU PHAP VUI LONG NHAP LAI: ");
							}
						} while (repair->severity != 1 && repair->severity != 2 && repair->severity != 3);
						printf("\nMOI BAN NHAP THOI GIAN BAT DAU CONG VIEC: ");
						fflush(stdin);
						scanf("%d", &repair->data.startTime);
						do
						{
							printf("\nNHAP THOI GIAN KET THUC CONG VIEC: ");
							fflush(stdin);
							scanf("%d", &repair->data.endTime);
							if (repair->data.endTime < repair->data.startTime || repair->data.endTime > 24)
							{
								printf("\nNHAP SAI! THOI GIAN KET THUC PHAI LON HON THOI GIAN BAN DAU.MOI BAN NHAP LAI! ");
							}
						} while (repair->data.endTime < repair->data.startTime || repair->data.endTime > 24);
						do
						{
							printf("\nMUC DO HOANH THANH CONG VIEC(NHAP 1 KHI 'HOAN THANH', 0 NEU CHUA HOAN THANH): ");
							scanf("%d", &repair->complete);
							if (repair->complete != 1 && repair->complete != 0)
							{
								printf("\nSAI CU PHAP VUI LONG NHAP LAI! ");
							}
						} while (repair->complete != 1 && repair->complete != 0);
						break;
					}
					else
					{
						repair = repair->next;
					}
				}
			}
			break;
		case 2:
			while (17)
			{
				if (repair->count == x)
				{
					printf("\nMOI BAN NHAP LAI TEN CONG VIEC:");
					fflush(stdin);
					gets(repair->buffer);
					break;
				}
				else
				{
					repair = repair->next;
				}
			}
			break;
		case 3:
			while (repair != NULL)
			{
				if (repair->count == x)
				{
					printf("\nMUC DO HOANH THANH CONG VIEC(NHAP 1 KHI 'HOAN THANH', 0 NEU CHUA HOAN THANH): ");
					fflush(stdin);
					scanf("%d", &repair->complete);
					break;
				}
				else
				{
					repair = repair->next;
				}
			}
			break;
		case 4:
			while (repair != NULL)
			{
				if (repair->count == x)
				{
					printf("\nMUC DO QUAN TRONG(1:CUC KI QUAN TRONG, 2 QUAN TRONG, 3 IT QUAN TRONG): ");
					fflush(stdin);
					scanf("%d", &repair->severity);
					break;
				}
				else
				{
					repair = repair->next;
				}
			}
			break;
		case 5:
			while (17)
			{
				if (repair->count == x)
				{
					printf("\nMOI BAN NHAP THOI GIAN BAT DAU CONG VIEC: ");
					fflush(stdin);
					scanf("%d", &repair->data.startTime);
					printf("\nMOI BAN NHAP THOI GIAN KET THUC CONG VIEC: ");
					fflush(stdin);
					scanf("%d", &repair->data.endTime);
					break;
				}
				else
				{
					repair = repair->next;
				}
			}
			break;
		default:
			repairTodo();
			break;
		}
	}
	printf("\n\n\n");
}
void deleteTodo()
{
	system("cls");
	int x;
	todo *del, *temp;
	if (start == NULL)
		printf("\n\n\t\t\t\t\tTUYET VOI BAN DA HOAN THANH TODO HOM NAY \n\n");
	else
	{
		seetodo();
		printf("\n\n\t\t\t\t\tNHAP DIA CHI TODO BAN MUON XOA:");
		scanf("%d", &x);
		del = start;
		temp = start->next;
		while (1)
		{
			if (del->count == x)
			{
				start = start->next;
				free(del);
				adjustcount();
				break;
			}
			if (temp->count == x)
			{
				del->next = temp->next;
				free(temp);
				adjustcount();
				break;
			}
			else
			{
				del = temp;
				temp = temp->next;
			}
		}
	}
	system("pause");
}
