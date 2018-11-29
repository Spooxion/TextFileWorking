#include "Library_of_functions.h"

#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

//1) добавления текста в файл; 2) подсчета количества строк в файле;
//3) подсчета количества знаков препинания в файле; 4) поиска самого длинного и самого короткого слов в файле; 
//5) редактирования текста в файле по следующему правилу : перед знаками препинания не может быть пробела
//6) получения в другом файле слов, состоящих из 5 букв в исходном файле; 7) вывода на экран содержимого текстового файла.

int main(int argc, char *argv[]) {
	unsigned char cmd;
	unsigned char file_name[] = "file.txt";
	system("chcp 1251");
	for(int iiii=101;iiii>100;iiii)
	{
		showMenu();
		cmd = getch();
		system("cls");
		switch(cmd)
		{
			case '1': ;
				unsigned char text[256];
				printf("Enter text: \n");
				gets(text);
				appendToFile("file.txt",text);
				printf("\n");
				printf("Text successfully added to file!\n");
				Sleep(1000);
			break;
			case '2':
				printf("Count of strings in file: %d \n\n",getCountOfStrings("file.txt"));
				system("pause");
			break;
			case '3':
				printf("Count of punctuation marks in file: %d \n\n",getCountOfSigns("file.txt"));
				system("pause");
			break;
			case '4': ;
				findShortestAndBiggestWord("file.txt");
				printf("\n");
				system("pause");
			break;
			case '5':	
				
				EditTextbyRule("file.txt");
				printf("File was edited\n");
				system("pause");		
			break;
			case '6':
				CopyWordinNewFile("file.txt","file2.txt");
				printf("Word copy in the new file.\n");
				system("pause");
			break;
			case '7':
				displayText();
				system("pause");
			break;
			case '8':
				ClearText("file.txt");
				printf("File was clear.\n");
				system("pause");
				break;
			case '9':
				ClearText("file.txt");
				printf("File2 was clear.\n");
				system("pause");
			case 'e':
				iiii = 1;
				printf("\n");
				break;
			default:
				
				system("cls");
			break;
		}
	}
	showMenu();
	return 0;
}