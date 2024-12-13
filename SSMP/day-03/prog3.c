// implement paging techniques of memory management

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct proc
{
	char name[50];
	int size;
	int frames[50];
};

void main()
{
	int totmem, frsize, totfr, size, ch, flag, count = 0, listcount = 0, totsize = 0, fragment = 0;
	char name[50];
	printf("Enter total memory (in Kb): ");
	scanf("%d", &totmem);
	printf("Enter frame size (in Kb): ");
	scanf("%d", &frsize);
	totfr = (totmem + frsize - 1) / frsize;
	printf("Total no. of frames available: %d\n", totfr);
	int allocated[totfr];
	
	for(int i = 0; i < totfr; i++)
	{
		allocated[i] = -1;
	}
	
	struct proc p[50];
	srand(time(0));
	
	while(1)
	{
		printf("Menu\n");
		printf("1. Insert\t2. Delete\t3. Display PCB\t4. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &ch);
		
		if(ch == 1)
		{
			printf("Enter process ID: ");
			scanf(" %[^\n]", name);
			strcpy(p[count].name, name);
			printf("Enter process size: ");
			scanf("%d", &size);
			
			if(totsize + (((size + frsize - 1) / frsize) * frsize) > totmem)
			{
				printf("Memory full\n");
				continue;
			}
			
			totsize += ((size + frsize - 1) / frsize) * frsize;
			printf("%d\n", totsize);
			p[count].size = size;
			fragment += (((size + frsize - 1) / frsize) * frsize) - size;
			
			for(int i = 0; i < ((size + frsize - 1) / frsize); i++)
			{
				p[count].frames[i] = rand() % (totfr + 1);

				do
				{
					flag = 0;

					for(int j = 0; j < listcount; j++)
					{
						if(allocated[j] == p[count].frames[i])
						{
							p[count].frames[i] = rand() % (totfr + 1);
							flag = 1;
							break;
						}
					}

				} while(flag == 1);
				
				allocated[listcount] = p[count].frames[i];
				listcount++;
			}
			
			count++;
			printf("Process allocated\n");
			printf("Internal fragmentation: %d\n", fragment);
		}
		
		else if(ch == 2)
		{
			printf("Enter process ID: ");
			scanf(" %[^\n]", name);
			int found = 0;
			
			for(int i = 0; i < count; i++)
			{
				if(strcmp(p[i].name, name) == 0)
				{
					found = 1;
					
					for(int j = 0; j < ((size + frsize - 1) / frsize); j++)
					{
						for(int k = 0; k < listcount; k++)
						{
							if(allocated[k] == p[i].frames[j])
							{
								for(int l = k; l < listcount - 1; l++)
								{
									allocated[l] = allocated[l+1];
								}
								
								listcount --;
								break;
							}
						}
					}
					
					for(int j = i; j < count - 1; j++)
					{
						strcpy(p[j].name, p[j+1].name);
						p[j].size = p[j+1].size;
						
						for(int k = 0; k < 50; k++)
						{
							p[j].frames[k] = p[j+1].frames[k];
						}
					}
					
					count--;
					printf("Process deleted\n");
				}
			}
			
			if(found == 0)
			{
				printf("Process not found\n");
			}
		}
		
		else if(ch == 3)
		{
			printf("Process ID\tProcess size\tFrames\n");
			
			for(int i = 0; i < count; i++)
			{
				printf("%s\t\t%d\t\t", p[i].name, p[i].size);
				
				for(int j = 0; j < ((p[i].size + frsize - 1) / frsize); j++)
				{
					printf("%d ", p[i].frames[j]);
				}
				
				printf("\n");
			}
		}
	}
}
