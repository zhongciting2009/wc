#include<stdio.h>
#include<stdlib.h>

#include <windows.h>
#include <direct.h>
#include <io.h>
#include <string.h>
#pragma warning(disable:4996)

int a = 0;
int b = 0;
int c = 0;
int main()
{
	void LineCount(char filename[]);
	void WordCount(char filename[]);
	void CharCount(char filename[]);
		char words[10], filename[100];
	printf("选择功能：-c 统计程序文件中的字符数\n-w 统计程序文件中的单词数\n-l 统计程序文件中的行数");
	scanf("%s", words);
	printf("请输入所用文件名：");
	scanf("%s", filename);
		while (1)
		{
			int i = 0;
			if ((words[i] == '-') && (words[i + 1] == 'c'))
			{
				CharCount(filename);
				printf("程序文件中的字符数为%d", a);
				break;
			}
			if ((words[i] == '-') && (words[i + 1] == 'w'))
			{
				WordCount(filename);
				printf("程序文件中的单词数为%d", b);
				break;
			}
			if ((words[i] == '-') && (words[i + 1] == 'l'))
			{
				LineCount(filename);
				printf("程序文件中的行数为%d", c);
				break;
			}
			else
				printf("\n输入功能指令有误，请重新输入\n");
			scanf("%s", words);
		}
}

void CharCount(char filename[])
{
	
	FILE *fp = NULL;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("cannot open this file", filename);
		exit(0);
	}
	char ch;
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch != ' '&&ch != '\n'&&ch != '\t'&&ch != ','&&ch != '.'&&ch != '!'&&ch != ';'&&ch != '=');
		a++;
		ch = fgetc(fp);
	}
	a--;
	fclose(fp);
}

void WordCount(char filename[])
{
	
	FILE *fp = NULL;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("cannot open this file", filename);
		exit(0);
	}
	char ch;
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch==' '||ch=='\n'||ch==','||ch=='.'||ch=='!'||ch=='='||ch==';')
		
			b++;
			ch = fgetc(fp);
			b--;
	}
	fclose(fp);
}

void LineCount(char filename[])
{
	
	FILE *fp = NULL;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("cannot open this file", filename);
		exit(0);
	}
	char ch;
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch == '\n' || ch == '\t')
			c++;
		ch = fgetc(fp);
	}
	c++;
	fclose(fp);
}
