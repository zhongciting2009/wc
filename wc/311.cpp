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
	printf("ѡ���ܣ�-c ͳ�Ƴ����ļ��е��ַ���\n-w ͳ�Ƴ����ļ��еĵ�����\n-l ͳ�Ƴ����ļ��е�����");
	scanf("%s", words);
	printf("�����������ļ�����");
	scanf("%s", filename);
		while (1)
		{
			int i = 0;
			if ((words[i] == '-') && (words[i + 1] == 'c'))
			{
				CharCount(filename);
				printf("�����ļ��е��ַ���Ϊ%d", a);
				break;
			}
			if ((words[i] == '-') && (words[i + 1] == 'w'))
			{
				WordCount(filename);
				printf("�����ļ��еĵ�����Ϊ%d", b);
				break;
			}
			if ((words[i] == '-') && (words[i + 1] == 'l'))
			{
				LineCount(filename);
				printf("�����ļ��е�����Ϊ%d", c);
				break;
			}
			else
				printf("\n���빦��ָ����������������\n");
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
