//crt_fopen_s.c
//Thisprogramopenstwofiles.Ituses
//fclosetoclosethefirstfileand
//_fclosealltocloseallremainingfiles.
#include <stdio.h>
FILE*stream, *stream2;
int main(void)
{
	errno_terr;
	//Openforread(willfailiffile"crt_fopen_s.c"doesnotexist)
	err = fopen_s(&stream, "crt_fopen_s.c", "r");
	if (err == 0)
	{
		printf("Thefile'crt_fopen_s.c'wasopened\n");
	}
	else
	{
		printf("Thefile'crt_fopen_s.c'wasnotopened\n");
	}

	//Openforwrite
	err = fopen_s(&stream2, "data2", "w+");
	if (err == 0)
	{
		printf("Thefile'data2'wasopened\n");
	}
	else
	{
		printf("Thefile'data2'wasnotopened\n");
	}
	//ClosestreamifitisnotNULL
	if (stream)
	{
		err = fclose(stream);
		if (err == 0)
		{
			printf("Thefile'crt_fopen_s.c'wasclosed\n");
		}
		else
		{
			printf("Thefile'crt_fopen_s.c'wasnotclosed\n");
		}
	}
	//Allotherfilesareclosed:
	intnumclosed = _fcloseall();
	printf("Numberoffilesclosedby_fcloseall:%u\n", numclosed);
}