// simulate the following file allocation strategies
// linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct block
{
	int alloc;
	struct block* next;
};

struct file
{
	char name[50];
	int noofblocks;
	struct block* allocated;
};

struct block* create(int alloc)
{
	struct block* b = (struct block*)malloc(sizeof(struct block));
	b->alloc = alloc;
	b->next = NULL;
	return b;
}

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
			f[count].allocated = NULL;
			f[count].noofblocks = blocks;

			for(int i = 0; i < blocks; i++)
			{
				int temp;

				do
                		{	
					temp = rand() % (totblocks + 1);
					flag = 0;
					
					for(int j = 0; j < listcount; j++)
					{
						if(usedblocks[j] == temp)
						{
							flag = 1;
							break;
						}
					}
				} while(flag == 1);

				struct block* new = create(temp);
				new->next = f[count].allocated;
				f[count].allocated = new;
				usedblocks[listcount] = temp;
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

	printf("File name\tFile size\tBlocks allocated\n");

	for(int i = 0; i < count; i++)
	{
		printf("%s\t\t%d\t\t", f[i].name, f[i].noofblocks);

		struct block* current = f[i].allocated;
		
		while(current != NULL)
		{
			printf("%d ", current->alloc);
			current = current->next;
		}

		printf("\n");
	}
}

