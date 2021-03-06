// Вильковского О. С., 1 курс, ПИз-18
// Лабораторная 2, вариант 15
// Текст представляет собой программу на языке C. Подсчитать количество инструкций for вложенных одна в одну

#include "pch.h"
#include <iostream>
#include <locale>
#define LENGTHSTR 1024
#define N 3
const char word[4] = "for";

using namespace std;

void setOptions() {
	setlocale(LC_ALL, "Russian");
	system("color F0");
}

int countWord(char str[]) {
	int sum = 0;
	int word_len = strlen(word);
	for (size_t i = 0; i <= strlen(str) - word_len; i++) {
		for (int j = 0; j < word_len; j++) {
			if (str[i + j] != word[j]) {
				break;
			}
			else {
				if (j == word_len - 1) {
					sum++;
				}
			}
		}
	}
	if (sum > 0)
		sum -= 1;
	return sum;
}

int main()
{
	setOptions();
	char str[LENGTHSTR];
	cout << "Подсчет вложенных инструкций " << word << endl;
	for (int i = 0; i < N; i++)
	{
		do {
			cout << "Введите текст : ";
			cin.getline(str, sizeof(str));
		} while (strlen(str) < strlen(word));

		cout << "Вложенных инструкций " << word << ": " << countWord(str) << endl;
	}
	system("pause");
}
