#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#define MAX 256
void find_files(const char * prefix)
{
	DIR * dir;
	struct dirent * entry;
	dir=opendir(".");
	if(dir==NULL)
	{
		printf("error");
		exit (0);
	}
	while ((entry=readdir(dir))!=NULL)
	{
		if(entry->d_type==DT_REG && strncmp(entry->d_name,prefix,
		strlen(prefix))==0)
		{
			printf("%s\n",entry->d_name);
		}
	}
	closedir(dir);
}
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("Enter the proper argument");
		exit(0);
	}
	const char * prefix=argv[1];
	if (strlen(prefix)==0)
	{
		printf("Prefix cannot be empty.\n");
		return 0;
	}
	find_files(prefix);
	return 0;
}
