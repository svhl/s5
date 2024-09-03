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
	int startblock;
};

void main()
{
	struct block b[50];
	struct file f[50];
	
	int remblocks = 100, nb = 0, nf = 0, n;
	printf("Enter no. of files:\n");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		char n[50];
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
			strcpy(f[i].name, n);
			f[i].startblock = nb;
			nf++;
			
			for(int j = 0; j < s - 1; j++)
			{
				b[nb].nextblock = nb + 1;
				nb++;
			}
			
			b[nb].nextblock = -1;
			nb++;
		}
	}
	
	for(int i = 0; i < nf; i++)
	{
		int count = 0, curblock = f[i].startblock;
		
		while(curblock != -1)
		{
			count++;
			curblock = b[curblock].nextblock;
		}
		
		printf("File:%s\t\tStart block:%d\t\tNo. of blocks:%d\n", f[i].name, f[i].startblock, count);
	}
}
