// simulate the following file allocation strategies
// indexed

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct file
{
	char name[50];
	int noofblocks;
	int index;
	int allocated[50];
};

void main()
{	
	int remblocks, totblocks, count = 0;
	printf("Enter total no. of blocks:\n");
	scanf("%d", &remblocks);
	totblocks = remblocks;
	int usedblocks[remblocks], listcount = 0, flag = 1;
	struct file f[50];
	srand(time(0));
	
	while(1)
	{
		char name[50], ch;
		int blocks;
		printf("Enter name of file:\n");
		scanf(" %[^\n]", name);
		printf("Enter no. of blocks:\n");
		scanf("%d", &blocks);
		
		if(blocks > remblocks)
		{
			printf("File can't be allocated\n");
		}
		
		else
		{
			remblocks -= blocks;
			strcpy(f[count].name, name);
			f[count].index = rand() % (totblocks + 1);

			do
			{
				flag = 0;

				for(int i = 0; i < listcount; i++)
				{
					if(usedblocks[i] == f[count].index)
					{
						f[count].index = rand() % (totblocks + 1);
						flag = 1;
						break;
					}
				}

			} while(flag == 1);

			usedblocks[listcount] = f[count].index;
			listcount++;		
			f[count].noofblocks = blocks;

			for(int i = 0; i < blocks; i++)
			{
				f[count].allocated[i] = rand() % (totblocks + 1);

				do
				{
					flag = 0;

					for(int j = 0; j < listcount; j++)
					{
						if(usedblocks[j] == f[count].allocated[i])
						{
							f[count].allocated[i] = rand() % (totblocks + 1);
							flag = 1;
							break;
						}
					}
				} while(flag == 1);

				usedblocks[listcount] = f[count].allocated[i];
				listcount++;
			}

			count++;
		}
		
		printf("Do you want to enter more files? (y/n):\n");
		scanf(" %c", &ch);
		
		if(ch == 'N' || ch == 'n')
		{
			break;
		}
	}
	
	printf("Index\tFile name\tFile size\tBlocks allocated\n");
	
	for(int i = 0; i < count; i++)
	{
		printf("%d\t%s\t\t%d\t\t", f[i].index, f[i].name, f[i].noofblocks);
	
		for(int j = 0; j < f[i].noofblocks; j++)
		{
			printf("%d ", f[i].allocated[j]);
		}
		
		printf("\n");
	}
}
