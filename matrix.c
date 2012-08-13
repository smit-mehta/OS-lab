/* OS lab - CS
 * Asssignment 1 - Matrix Multiplication
 * Smit Mehta, CS10B024
 * Abhiram R,  CS10B0
 * Sahitya,    CS10B044
 * Karthik A,  CS10B0
 * Date of Submission : 7/8/12
 */


#include <stdio.h>
#include <stdlib.h>

int main()
{
	long int m1[10][20], m2[20][30];
	long int m3[10][30];
	int i, j, k;
	FILE *file;
	file = fopen("output.txt","w");
	// Initializing two operand matrices with random ints.
	srand(time(0));

	// Generating inputs

	fprintf(file, ";A Matrix Begins here\n");
	for (i=0; i<10; i++)
	{
		for (j=0; j<20; j++)
		{
			m1[i][j] = rand();
			fprintf(file, "dd 0x%.8lx\n",m1[i][j]);
		}
	}


	fprintf(file, ";B Matrix Begins here\n");
	for (i=0; i<20; i++)
	{
		for (j=0; j<30; j++)
		{
			m2[i][j] = rand();
			fprintf(file, "dd 0x%.8lx\n",m2[i][j]);
		}
	}


	fprintf(file, ";C Matrix Begins here\n");
	// Matrix multiplication

	int temp;

	for (i=0; i<10; i++)
	{
		for (j=0; j<30; j++)
		{
			m3[i][j] = 0;

			for (k=0; k<20; k++)
			{
				m3[i][j] += m1[i][k] * m2[k][j];
			}
			temp = m3[i][j]>>32;	
			fprintf (file, "dd 0x%.8x\ndd 0x%.8x\n", temp, (int)m3[i][j]&0xFFFFFFFF);
		}

	}
	fclose(file);
	
	return 0;
}

