#include<stdio.h>
#include <string.h>

void main ()
{
  int data[10];
  char datastr[4];
  int dataatrec[10], c, c1, c2, c3, i;
  char dataatrecstr[7];

  printf ("Enter 4 bits of original data\n");
  scanf ("%s", datastr);
  if (datastr[0] == '0')
    data[0] = 0;
  else
    data[0] = 1;
  if (datastr[1] == '0')
    data[1] = 0;
  else
    data[1] = 1;
  if (datastr[2] == '0')
    data[2] = 0;
  else
    data[2]=1;
if(datastr[3]=='0')
    data[4]=0;
else
    data[4]=1;


  data[6] = data[0] ^ data[2] ^ data[4];
  data[5] = data[0] ^ data[1] ^ data[4];
  data[3] = data[0] ^ data[1] ^ data[2];



  printf ("\nEnter 7 received data bits\n");
    scanf("%s",dataatrecstr);
    for(int i=0;i<7;i++){
        if(dataatrecstr[i]=='0')
        dataatrec[i]=0;
        else
        dataatrec[i]=1;
    }

  c1 = dataatrec[6] ^ dataatrec[4] ^ dataatrec[2] ^ dataatrec[0];
  c2 = dataatrec[5] ^ dataatrec[4] ^ dataatrec[1] ^ dataatrec[0];
  c3 = dataatrec[3] ^ dataatrec[2] ^ dataatrec[1] ^ dataatrec[0];
  c = c3 * 4 + c2 * 2 + c1;

  if (c == 0 && dataatrec[6] == data[6] && dataatrec[5] == data[5]
      && dataatrec[3] == data[3])
    {
      printf ("\nNo error\n");
    }
  else
    {
      printf ("\nError on position %d", c);

      printf ("\nData has to be sent : ");
      for (i = 0; i < 7; i++)
	printf ("%d", data[i]);

      printf ("\nData received : ");
      for (i = 0; i < 7; i++)
	printf ("%d", dataatrec[i]);

      printf ("\nCorrect message is : ");

      if (dataatrec[7 - c] == 0)
	dataatrec[7 - c] = 1;
      else
	dataatrec[7 - c] = 0;

      for (i = 0; i < 7; i++)
	{
	  printf ("%d", data[i]);
	}
    }
    printf("\n");
}