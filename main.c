#include <stdlib.h>
#include <stdio.h>
#include "urldecode.h"
#include <string.h>

#define VERSION "0.0.1"

void printVersion();
void printHelp();
void decodeFileName(char*input);

int main(int argc,char**argv)
{
	
	if(argc==1)
	{
		printf("NO input file(s)!\n");
		printHelp();
		return 0;
	
	}
	else if(argc==2)
	{
		if(strcmp(argv[1],"-v")==0||strcmp(argv[1],"--version")==0)	
		{
			printVersion();
			return 0;
		}
		else if(!strcmp(argv[1],"--help"))
		{
			printHelp();
			return 0;
		}
		else if(argv[1][0]=='-')
		{
			printf("Unrecognized command line option\n");
			printHelp();
			return 0;
		}
		else
		{
				decodeFileName(argv[1]);
				return 0;
		}

	}
	for(int i=1;i<argc;i++)
	{
		decodeFileName(argv[i]);
	}

	return 0;
}


void decodeFileName(char*input)
{
	char cmd[550];
	char* out;
	out = urlDecode(input);
	printf("%s\n",out);
	sprintf(cmd,"mv \"%s\" \"%s\"",input,out);
	system(cmd);
}



void printHelp()
{
	printf("fileNameDecode\t[file(s)...]\n");
	printf("fileNameDecode\t--help\n");
	printf("fileNameDecode\t-v/--version\n");
}


void printVersion()
{
	printf("fileNameDecode ");
	printf(VERSION);
	printf("\n");
}
