// simulate the following file allocation strategies
// sequential

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file
{
	char name[50];
	int noofblocks;
	int startblock;
	int allocated[50];
};

void main()
{	
	int remblocks, count = 0, start = 0;
	printf("Enter total no. of blocks:\n");
	scanf("%d", &remblocks);
	struct file f[50];
	
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
			f[count].startblock = start;
			f[count].noofblocks = blocks;

			for(int i = 0; i < blocks; i++)
			{
				f[count].allocated[i] = start;
				start++;
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
	
	printf("File name\tFile size\tBlocks allocated\n");
	
	for(int i = 0; i < count; i++)
	{
		printf("%s\t\t%d\t\t", f[i].name, f[i].noofblocks);
		
		for(int j = 0; j < f[i].noofblocks; j++)
		{
			printf("%d ", f[i].allocated[j]);
		}
		
		printf("\n");
	}
}
