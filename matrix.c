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
#include <float.h>

double random_double();

int main()
{
	double m1[10][20], m2[20][30], m3[10][30], m4[10][20];
	int i, j, k;

	// Dumping randomly generated inputs and generated output in seperate files

	FILE *matrix1 = NULL;
	matrix1 = fopen("matrix1.dat", "wb");

	FILE *matrix2 = NULL;
	matrix2 = fopen("matrix2.dat", "wb");

	FILE *matrix3 = NULL;
	matrix3 = fopen("matrix3.dat", "wb");

	// Generating inputs

	for (i=0; i<10; i++)
	{
		for (j=0; j<20; j++)
		{
			m1[i][j] = random_double();
		}
	}

	fwrite (m1, sizeof(double), 200, matrix1);

	fclose(matrix1);

	for (i=0; i<20; i++)
	{
		for (j=0; j<30; j++)
		{
			m2[i][j] = random_double();
		}
	}

	fwrite (m2, sizeof(double), 600, matrix2);

	fclose(matrix2);

	// Matrix multiplication

	for (i=0; i<10; i++)
	{
		for (j=0; j<30; j++)
		{
			m3[i][j] = 0;

			for (k=0; k<20; k++)
			{
				m3[i][j] += m1[i][k] * m2[k][j];
			}
		
			printf ("%f ", m3[i][j]);
		}

		printf("\n");
	}

	fwrite (m3, sizeof(double), 300, matrix3);

	fclose(matrix3);
	
	return 0;
}

// Generating random doubles between -50000 and +50000
double random_double()
{
	double f = (double)rand() / RAND_MAX;
	double random = -50000 + f * 50000 * 2;
	return random;
}
