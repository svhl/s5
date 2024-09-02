// simulate the following file organization techniques
// two level directory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file
{
	char name[50];
};

struct dir
{
	struct file f[50];
	char name[50];
	int count;
};

struct twolevel
{
	struct dir d[50];
	int count;
};

void main()
{
	struct twolevel tl;
	tl.count = 0;
	int ch;
	
	while(1)
	{
		printf("Menu\n");
		printf("1. Create directory\n");
		printf("2. Create file\n");
		printf("3. List files\n");
		printf("4. Search file\n");
		printf("5. Delete directory\n");
		printf("6. Delete file\n");
		printf("Any other value to exit\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);

		if(ch == 1)
		{
			char name[50];
			printf("Enter directory name:\n");
			scanf(" %[^\n]", name);
			strcpy(tl.d[tl.count].name, name);
			tl.d[tl.count].count = 0;
			tl.count++;
		}
		
		else if(ch == 2)
		{
			char dname[50], fname[50];
			printf("Enter directory name:\n");
			scanf(" %[^\n]", dname);
			printf("Enter file name:\n");
			scanf(" %[^\n]", fname);
			int found = 0;

			for(int i = 0; i < tl.count; i++)
			{
				if(strcmp(tl.d[i].name, dname) == 0)
				{
					strcpy(tl.d[i].f[tl.d[i].count].name, fname);
					tl.d[i].count++;
					found = 1;
				}
			}

			if(found == 0)
			{
				printf("directory doesn't exist\n");
			}
		}
		
		else if(ch == 3)
		{
			if(tl.count == 0)
			{
				printf("No directories or files\n");
			}
			
			else
			{
				for(int i = 0; i < tl.count; i++)
				{
					for(int j = 0; j < tl.d[i].count; j++)
					{
						printf("/twolevel/%s/%s\n", tl.d[i].name, tl.d[i].f[j].name);
					}
				}
			}
		}
		
		else if(ch == 4)
		{
			char name[50];
			printf("Enter file to search:\n");
			scanf(" %[^\n]", name);
			int found = 0;

			for(int i = 0; i < tl.count; i++)
			{
				for(int j = 0; j < tl.d[i].count; j++)
				{
					if(strcmp(tl.d[i].f[j].name, name) == 0)
					{
						printf("File found in directory %s\n", tl.d[i].name);
						found = 1;
						break;
					}
				}
			}

			if(found == 0)
			{
				printf("File not found\n");
			}
		}

		else if(ch == 5)
		{
			char name[50];
			printf("Enter directory to delete:\n");
			scanf(" %[^\n]", name);
			int found = 0;

			for(int i = 0; i < tl.count; i++)
			{
				if(strcmp(tl.d[i].name, name) == 0)
				{
					for(int j = i; j < tl.count; j++)
					{
						tl.d[j] = tl.d[j+1];
					}

					printf("Directory deleted\n");
					found = 1;
					tl.count--;
				}
			}

			if(found == 0)
			{
				printf("Directory not found\n");
			}
		}

		else if(ch == 6)
		{
			char dname[50], fname[50];
			printf("Enter directory name:\n");
			scanf(" %[^\n]", dname);
			printf("Enter file name:\n");
			scanf(" %[^\n]", fname);
			int found = 0;

			for(int i = 0; i < tl.count; i++)
			{
				if(strcmp(tl.d[i].name, dname) == 0)
				{
					for(int j = 0; j < tl.d[i].count; j++)
					{
						if(strcmp(tl.d[i].f[j].name, fname) == 0)
						{
							for(int k = j; k < tl.d[i].count - 1; k++)
							{
								tl.d[i].f[k] = tl.d[i].f[k+1];
							}

							tl.d[i].count--;
							printf("File deleted\n");
							found = 1;
						}
					}
				}
			}

			if(found == 0)
			{
				printf("File not found\n");
			}
		}
	
		else
		{
			return;
		}
	}
}
