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
	int totmem, frsize, totfr, name, size, count = 0, listcount = 0;
	printf("Enter total memory (in Kb):\n");
	scanf("%d", &totmem);
	printf("Enter frame size (in Kb):\n");
	scanf("%d", &frsize);
	totfr = (totmem + frsize - 1) / frsize;
	int allocated[totfr];
	struct proc p[50];
	srand(time(0));
	
	while(1)
	{
		printf("Menu\n");
		printf("1. Insert\t2. Delete\t3. Display PCB\t4. Exit\n");
		printf("Enter choice\n");
		scanf("%d", &ch);
		
		if(ch == 1)
		{
			printf("Enter process ID:\n");
			scanf(" %[^\n]", name);
			strcpy(p[count].name, name);
			printf("Enter process size:\n");
			scanf("%d", &size);
			p[count].size = size;
			
			for(int i = 0; frsize * (i + 1) >= size; i++)
			{
				f[count].frames[i] = rand() % (totblocks + 1);

				do
				{
					flag = 0;

					for(int i = 0; i < listcount; i++)
					{
						if(allocated[i] == f[count].index)
						{
							f[count].frames[i] = rand() % (totblocks + 1);
							flag = 1;
							break;
						}
					}

				} while(flag == 1);
				
				allocated[listcount] = f[count].frames[i];
				listcount++;
			}
			
			count++;
		}
		
		else if(ch == 3)
		{
			printf("Process ID\tProcess size\tFrames\n");
		}
	}
}
