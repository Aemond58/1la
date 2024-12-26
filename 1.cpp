#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	int i;
	struct student {
		char famil[20];
		char name[20];
		char facult[20];
		int Nomzach;
	} stud[3];

	// Ввод данных о студентах
	for (i = 0; i < 3; i++) {
		printf("fam\n");
		scanf("%19s", stud[i].famil);
	}
	for (i = 0; i < 3; i++) {
		printf("imya %s\n", stud[i].famil);
		scanf("%19s", stud[i].name);
	}
	for (i = 0; i < 3; i++) {
		printf("fakult %s %s\n", stud[i].famil, stud[i].name);
		scanf("%19s", stud[i].facult);
	}
	for (i = 0; i < 3; i++) {
		printf("zachetka %s %s\n", stud[i].famil, stud[i].name);
		scanf("%d", &stud[i].Nomzach);
	}

	// Вывод данных о студентах
	for (i = 0; i < 3; i++) {
		printf("student %s %s obuchaetsa na fak %s, nomer zachetki %d\n",
			stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
	}

	// Поиск студента
	char search_param[20];
	printf("Vvedite parametrl dlya poiska (familiya, imya, nomer zachetki): ");
	scanf("%19s", search_param);

	int found = 0; // Флаг для проверки, найден ли студент

	// Проверяем, является ли введённое значение числом (для поиска по номеру зачётной книжки)
	char* endptr;
	long int search_nomzach = strtol(search_param, &endptr, 10);

	// Если это число, ищем по номеру зачётной книжки
	if (*endptr == '\0') {
		for (i = 0; i < 3; i++) {
			if (stud[i].Nomzach == search_nomzach) {
				printf("naiden student: %s %s, fak: %s, zach: %d\n",
					stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
				found = 1;
				break;
			}
		}
	}
	else { // Иначе ищем по фамилии или имени
		for (i = 0; i < 3; i++) {
			if (strcmp(stud[i].famil, search_param) == 0 || strcmp(stud[i].name, search_param) == 0) {
				printf("naiden student: %s %s, fak: %s, zach: %d\n",
					stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
				found = 1;
				break;
			}
		}
	}

	if (!found) {
		printf("student s parametrom %s ne naiden\n", search_param);
	}

	return 0;
}
