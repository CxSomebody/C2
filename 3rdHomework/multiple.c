#include<stdio.h>
#include <stdlib.h>

struct num{
	int num;
	int remain;
}Num[10];

int main()
{
    int *p[5000];
	int *q[5000];
    int N = 0;
    int X[10] = {0};
    int i = 0, j = 0, k = 0, m = 0;
	int numLen = 0, newRem = 0;
	FILE *in, *out;
	in = fopen("multiple.in", "r");
	out = fopen("multiple.out", "w");
	fscanf(in, "%d", &N);
    //scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		p[i] = NULL;
		q[i] = NULL;
	}
    //while(scanf("%d", &i)!=EOF) 
	while (fscanf(in, "%d", &i)!=EOF)
	{
		X[i] = 1;
		if(i == N)
		{
			fprintf(out,"%d", i);
			fclose(in);
			fclose(out);
			return 0;
		}
	}
		
	for(i = 0; i < 10; i++)
	{
		if(X[i] == 1)
		{
			Num[j].num = i;
			Num[j].remain = i;
			j++;

			p[i] = (int*)malloc(sizeof(i)*500);
			*p[i] = i%N;//why p[i] != NULL ?
		}
	}
	numLen = j;
	for(i = 1; i <= 500; i++)//(i+1) means the digits, at most 500
	{
		for(j = 0; j < numLen; j++)
		{
			Num[j].remain = 10 * Num[j].remain%N;
			for(k = 0; k < N; k++)
			{
				newRem = (k + Num[j].remain) % N;
				if(p[k] != NULL)
				{
					if (newRem == 0 && Num[j].num != 0)//find the number
					{
						//printf("%d", Num[j].num);
						fprintf(out, "%d", Num[j].num);
						for (m = i - 1; m >= 0; m--)
						{
							//printf("%d", *(p[k] + m));
							fprintf(out, "%d", *(p[k] + m));
						}
						fclose(in);
						fclose(out);
						return 0;
					}
					if (q[newRem] != NULL)
					{
						continue;
					}
					else{
						q[newRem] = (int*)malloc(sizeof(i)* 500);
					}
					for(m = 0; m < i; m++)
					{
						*(q[newRem] + m) = *(p[k] + m);
					}
					*(q[newRem] + m) = Num[j].num;// m+1 digits
				}
			}
		}
		//swap p,q, set q to NULL
		for(j = 0; j < N; j++)
		{
			free(p[j]);
			p[j] = q[j];
			q[j] = NULL;
		}
	}
	//printf("NO");
	fprintf(out, "0");
	fclose(in);
	fclose(out);
	return 0;
}