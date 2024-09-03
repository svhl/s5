// simulate the following file allocation strategies
// sequential

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct block
{
	int nextblock;
};

struct file
{
	char name[50];
	int noofblocks;
	int startblock;
};

void main()
{	
	int remblocks, nb = 0, nf = 0;
	printf("Enter total no. of blocks:\n");
	scanf("%d", &remblocks);
	struct block b[remblocks];
	struct file f[remblocks];
	
	while(1)
	{
		char n[50], ch;
		int s;
		printf("Enter name of file:\n");
		scanf(" %[^\n]", n);
		printf("Enter no. of blocks:\n");
		scanf("%d", &s);
		
		if(s > remblocks)
		{
			printf("File can't be allocated\n");
		}
		
		else
		{
			remblocks -= s;
			strcpy(f[nf].name, n);
			f[nf].startblock = nb;
			f[nf].noofblocks = s;
			nf++;
			
			for(int j = 0; j < s - 1; j++)
			{
				b[nb].nextblock = nb + 1;
				nb++;
			}
			
			b[nb].nextblock = -1;
			nb++;
		}
		
		printf("Do you want to enter more files? (y/n):\n");
		scanf(" %c", &ch);
		
		if(ch == 'N' || ch == 'n')
		{
			break;
		}
	}
	
	printf("File name\tFile size\tBlocks allocated\n");
	
	for(int i = 0; i < nf; i++)
	{
		printf("%s\t\t%d\t\t", f[i].name, f[i].noofblocks);
		int curblock = f[i].startblock;
		
		while(curblock != -1)
		{
			printf("%d ", curblock);
			curblock = b[curblock].nextblock;
		}
		
		printf("\n");
	}
}
