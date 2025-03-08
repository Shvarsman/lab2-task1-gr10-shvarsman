/*
Выполнил Шварцман Диджар Азатович
Файл содержит реализацию функций для сортировки массива чисел
по сумме цифр, работу с маршрутами (структура MARSHRUT), а также 
вывод сведений об ученика 7ых классов
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROUTES 10
#define MAX_NAME_LENGTH 50
#define MAX_STRING_LEN 50
#define MAX_KIDS 100

typedef struct {
		int number;
		char start[MAX_NAME_LENGTH];
		char end[MAX_NAME_LENGTH];
		int length;
} MARSHRUT;

typedef struct {
		int year;
		int month;
		int day;
} Date;

typedef struct {
		char postal_code[10];
		char country[MAX_STRING_LEN];
		char region[MAX_STRING_LEN];
		char district[MAX_STRING_LEN];
		char city[MAX_STRING_LEN];
		char street[MAX_STRING_LEN];
		int house;
		int apartment;
} Address;

typedef struct {
		char surname[MAX_STRING_LEN];
		char name[MAX_STRING_LEN];
		char patronymic[MAX_STRING_LEN];
		char gender;
		char nationality[MAX_STRING_LEN];
		int height;
		int weight;
		Date birth_date;
		char phone[15];
		Address home_address;
		char school[MAX_STRING_LEN];
		char class[10];
} Schoolkid;

//Декларация функций
int sumOfDigits(int number);
void sortByDigitSum(int* array, int size);
void createRoutes(MARSHRUT* routes, int* count);
MARSHRUT findLongestRoute(MARSHRUT* routes, int count);
void sortRoutesByNumber(MARSHRUT* routes, int count);
void printRoutesByLocation(MARSHRUT* routes, int count, const char* location);
void printSchoolkid(const Schoolkid *k);
void printSeventhClass(Schoolkid *kids, int count);


//Определения функций

/*
Функция: sumOfDigits
Возвращает сумму цифр числа.
Параметры:
		- number: число, сумму цифр которого нужно вычислить.
*/
int sumOfDigits(int number) {
		int sum = 0;
		while (number != 0) {
				sum += number % 10;
				number /= 10;
		}
		return sum;
}

/*
Функция: sortByDigitSum
Сортирует массив чисел по убыванию суммы цифр.
Параметры:
		- array: массив чисел.
		- size: размер массива.
*/
void sortByDigitSum(int* array, int size) {
		for (int i = 0; i < size - 1; i++) {
				for (int j = i + 1; j < size; j++) {
						if (sumOfDigits(array[i]) < sumOfDigits(array[j])) {
								int temp = array[i];
								array[i] = array[j];
								array[j] = temp;
						}
				}
		}
}

/*
Функция: createRoutes
Создает массив маршрутов (ввод данных с клавиатуры).
Параметры:
		- routes: массив структур MARSHRUT.
		- count: указатель на переменную, хранящую количество маршрутов.
*/
void createRoutes(MARSHRUT* routes, int* count) {
		printf("Введите количество маршрутов (не более %d): ", MAX_ROUTES);
		scanf("%d", count);

		for (int i = 0; i < *count; i++) {
				printf("Маршрут %d:\n", i + 1);
				printf("Номер маршрута: ");
				scanf("%d", &routes[i].number);
				printf("Начальный пункт: ");
				scanf("%s", routes[i].start);
				printf("Конечный пункт: ");
				scanf("%s", routes[i].end);
				printf("Длина маршрута: ");
				scanf("%d", &routes[i].length);
		}
}

/*
Функция: findLongestRoute
Находит и возвращает маршрут с максимальной длиной.
Параметры:
		- routes: массив структур MARSHRUT.
		- count: количество маршрутов.
*/
MARSHRUT findLongestRoute(MARSHRUT* routes, int count) {
		MARSHRUT longest = routes[0];
		for (int i = 1; i < count; i++) {
				if (routes[i].length > longest.length) {
						longest = routes[i];
				}
		}
		return longest;
}
