
#ifndef _MOD_H 
#define _MOD_H

#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
void showMenu(void)
{
	printf("\t\tFILE MENU\n");
	printf("1. Add text to file.\n");
	printf("2. Counting the number of lines in a file.\n");
	printf("3. Counting the number of punctuation marks in a file.\n");
	printf("4. Search for the longest and shortest words in the file.\n");
	printf("5. Edit text file according to the rule.\n");
	printf("6. Getting in another file the words consisting of 5 letters in the source file.\n");
	printf("7. Displaying the contents of a text file.\n");
	printf("8. Clear file.txt.\n");
	printf("8. Clear file2.txt\n");
	printf("e. Exit.\n");

}
void appendToFile(char *file_name, char *text)
{
	FILE *fp;
	fp = fopen(file_name, "a");
	strcat(text, "\n");
	fputs(text, fp);
	fclose(fp);
}
int getCountOfStrings(char *file_name)
{
	FILE *fp;
	unsigned int sum = 0;
	unsigned char text[256];
	memset(text, 0, 256);
	fp = fopen(file_name, "r");
	unsigned char i;
	while (fgets(text, sizeof(text), fp))
	{
		for (i = 0; i < strlen(text); i++)
		{
			if (text[i] == '\n')
			{
				sum++;
			}
		}
	}
	fclose(fp);
	return sum;

}
void displayText()
{
	FILE *fp;
	char text[1024];
	memset(text, 0, 1024);
	fp = fopen("file.txt", "r");


	fread(text, sizeof(char), 1024, fp);

	fclose(fp);
	printf("%s", text);
}
int getCountOfSigns(char *file_name)
{
	FILE *fp;
	unsigned int sum = 0;
	unsigned char text[256];
	memset(text, 0, 256);
	fp = fopen(file_name, "r");
	unsigned char i;
	while (fgets(text, sizeof(text), fp))
	{
		for (i = 0; i < strlen(text); i++)
		{
			if (text[i] == '.'
				|| text[i] == ','
				|| text[i] == '!'
				|| text[i] == '?'
				|| text[i] == ';'
				|| text[i] == ':'
				|| text[i] == '\"')
			{
				sum++;
			}
		}
	}
	fclose(fp);
	return sum;
}
void findShortestAndBiggestWord(char *file_name)
{

	FILE *fp;
	fp = fopen(file_name, "r");

	unsigned char	text[1024],
		ansMin[1024],
		ansMax[1024],
		word[1024];

	unsigned int	minSize = 1024,
		maxSize = 0,
		sizeNow = 0,
		i = 0;

	memset(text, 0, 1024);
	memset(ansMin, 0, 1024);
	memset(ansMax, 0, 1024);
	memset(word, 0, 1024);



	while (!feof(fp))
	{
		fscanf(fp, "%s", text);
		if (strlen(text) < minSize)
		{
			unsigned int i = 0;
			minSize = strlen(text);
			while (i < strlen(text))
			{
				ansMin[i] = text[i];
				++i;
			}
			ansMin[i] = '\0';
		}
		if (strlen(text) > maxSize)
		{
			unsigned int i = 0;
			maxSize = strlen(text);
			while (i < strlen(text))
			{
				ansMax[i] = text[i];
				++i;
			}
			ansMax[i] = '\0';
		}

	}
	printf("\n Maximum Word: %s", ansMax);
	printf("\n Minimum Word: %s", ansMin);

	fclose(fp);


}
void ClearText(char *file_name)

{
	FILE *fp;
	unsigned char buffer[1024];
	memset(buffer, 0, 1024);
	unsigned int i = 0, c = 0;
	fp = fopen(file_name, "r");
	fread(buffer, sizeof(char) * 20, sizeof(buffer) * 20, fp);
	fclose(fp);
	buffer[strlen(buffer)] = 0;
	for (i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] == ',')//Если нашли запятую
		{
			if (buffer[i - 1] == ' ')//Если слева пробел, то 
			{
				while (buffer[i - 1] == ' ')
				{
					for (c = i - 1; c < strlen(buffer); c++)
					{
						buffer[c] = buffer[c + 1];
					}
					buffer[strlen(buffer)] = 0;
					i--;
				}

			}
		}
	}
	fp = fopen(file_name, "w");
	fputs(buffer, fp);
	fclose(fp);
}
void CopyWordinNewFile(char *file_name, char *file_name2)
{

	FILE *fp, *fp2;
	char c;
	unsigned char
		text[1024];


	unsigned int	i = 0;

	memset(text, 0, 1024);



	fp = fopen(file_name, "r");  
	fp2 = fopen(file_name2, "a"); 
	while (!feof(fp)) 
	{

		fscanf(fp, "%s", text); 
		if (strlen(text) == 5) 
		{

			fputs(text, fp2);
			fputs(" ", fp2);

			memset(text, 0, 1024);
		}


	}
	fclose(fp);
	fclose(fp2);
	return 0;
}
void EditTextbyRule(char *file_name)
{
	FILE *fp;
	unsigned char buffer[1024];
	memset(buffer, 0, 1024);
	unsigned int i = 0, c = 0;
	fp = fopen(file_name, "r");
	fread(buffer, sizeof(char), sizeof(buffer), fp);
	fclose(fp);
	buffer[strlen(buffer)] = 0;

	for (i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] == ',' || buffer[i] == '.' || buffer[i] == ';' || buffer[i] == ':' || buffer[i] == '!' || buffer[i] == '?' || buffer[i] == '\"')
		{
			if (buffer[i - 1] == ' ')
			{
				while (buffer[i - 1] == ' ')
				{
					for (c = i - 1; c < strlen(buffer); c++)
					{
						buffer[c] = buffer[c + 1];
					}
					buffer[strlen(buffer)] = 0;
					i--;
				}

			}
		}
	}


	fp = fopen(file_name, "w");
	fputs(buffer, fp);
	fclose(fp);
}

#define _CRT_SECURE_NO_WARNINGS

#endif 