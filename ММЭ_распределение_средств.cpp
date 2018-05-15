#include <stdio.h>
#include <conio.h>
main()
{
	int x[6] = {0, 8, 16, 24, 32, 40};
	int g1[6] = {0, 48, 57, 120, 150, 180};
	int g2[6] = {0, 28, 60, 122, 146, 175};
	int g3[6] = {0, 35, 67, 130, 144, 180};
	int g4[6] = {0, 27, 73, 125, 182, 178};

	int f1[6], f2[6], f3[6], f4;
	int i, j, fmax, xmax, ftmp;
	int S = 40;

	// 1-й этап
	for(i = 0; i < 6; i++)
	{
		f1[i] = g1[i];
		printf("\nf1(%d) = %d", x[i], g1[i]);
	}

	// 2-й этап
	for(i = 0; i < 6; i++)
	{
		printf("\nS = %d => f2(%d) = max {", x[i], x[i]);
		for(j = 0, fmax = 0; j <= i; j++)
		{
			ftmp = g2[j] + f1[i - j];
			if(ftmp >= fmax)
			{
				fmax = ftmp;
				xmax = x[j];
			}
			printf(" %d + %d", g2[j], f1[i - j]);
			if(i != j) printf(","); else printf(" ");
		}
		f2[i] = fmax;
		printf("} = %d, x2 = %d", fmax, xmax);
	}

	// 3-й этап
	for(i = 0; i < 6; i++)
	{
		printf("\nS = %d => f3(%d) = max {", x[i], x[i]);
		for(j = 0, fmax = 0; j <= i; j++)
		{
			ftmp = g3[j] + f2[i - j];
			if(ftmp >= fmax)
			{
				fmax = ftmp;
				xmax = x[j];
			}
			printf(" %d + %d", g3[j], f2[i - j]);
			if(i != j) printf(","); else printf(" ");
		}
		f3[i] = fmax;
		printf("} = %d, x3 = %d", fmax, xmax);
	}

	// 4-й этап
	i = 5;
	printf("\nS = %d => f4(%d) = max {", x[i], x[i]);
	for(j = 0, fmax = 0; j <= i; j++)
	{
		ftmp = g4[j] + f3[i - j];
		if(ftmp >= fmax)
		{
			fmax = ftmp;
			xmax = x[j];
		}
		printf(" %d + %d", g4[j], f3[i - j]);
		if(i != j) printf(","); else printf(" ");
	}
	f4 = fmax;
	printf("} = %d, x4 = %d", fmax, xmax);
	
	getch();
	return 0;
}