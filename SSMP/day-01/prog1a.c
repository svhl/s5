// simulate the following file organization techniques
// single level directory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file
{
	char name[50];
};

struct singlelevel
{
	struct file f[50];
	int count;
};

void main()
{
	struct singlelevel sl;
	sl.count = 0;
	int ch;
	
	while(1)
	{
		printf("Menu\n");
		printf("1. Create file\n");
		printf("2. List files\n");
		printf("3. Search file\n");
		printf("4. Delete file\n");
		printf("Any other value to exit\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);
		
		if(ch == 1)
		{
			char name[50];
			printf("Enter file name:\n");
			scanf(" %[^\n]", name);
			strcpy(sl.f[sl.count].name, name);
			sl.count++;
		}
		
		else if(ch == 2)
		{
			if(sl.count == 0)
			{
				printf("No files in directory\n");
			}
			
			else
			{
				for(int i = 0; i < sl.count; i++)
				{
					printf("/singlelevel/%s\n", sl.f[i].name);
				}
			}
		}
		
		else if(ch == 3)
		{
			if(sl.count == 0)
			{
				printf("No files in directory\n");
			}
			
			else
			{
				char name[50];
				printf("Enter file to search:\n");
				scanf(" %[^\n]", name);
				int found = 0;
				
				for(int i = 0; i < sl.count; i++)
				{
					if(strcmp(sl.f[i].name, name) == 0)
					{
						found = 1;
						break;
					}
				}
				
				if(found == 1)
				{
					printf("File found\n");
				}
				
				else
				{
					printf("File not found\n");
				}
			}
		}
			
		else if(ch == 4)
		{
			if(sl.count == 0)
			{
				printf("No files in directory\n");
			}
			
			else
			{
				char name[50];
				printf("Enter file to delete:\n");
				scanf(" %[^\n]", name);
				int found = 0;
				
				for(int i = 0; i < sl.count; i++)
				{
					if(strcmp(sl.f[i].name, name) == 0)
					{
						for(int j = i; j < sl.count; j++)
						{
							strcpy(sl.f[j].name, sl.f[j+1].name);
						}
						
						found = 1;
						sl.count--;
					}
				}
				
				if(found == 1)
				{
					printf("File(s) deleted\n");
				}
				
				else
				{
					printf("File not found\n");
				}
			}
		}
		
		else
		{
			return;
		}
	}
}
