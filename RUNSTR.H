
enum {
	SYML = 4,
	SYMH = 6,
	MAXLENSTR = 25,
	MONH = 25,
	MONL = 79,
/*
black square - 178
white square - 176
heart - 3
*/
	FILL = '²',
	FILLC = '°'
};
struct sizeString {
//	char symb;
	int len;
	int hig;
	int vol;
	char **arr;
};

static struct sizeString runStr;

char sMinus[][SYML] = {
FILLC,  FILLC,  FILLC,  FILLC,
FILLC,  FILLC,  FILLC,  FILLC,
FILLC,  FILL, FILL, FILLC,
FILLC,  FILLC,  FILLC,  FILLC,
FILLC,  FILLC,  FILLC,  FILLC,
FILLC,  FILLC,  FILLC,  FILLC
};
char s0[][SYML] = {
FILLC,  FILL, FILL, FILLC,
FILL, FILLC,  FILLC,  FILL,
FILL, FILLC,  FILLC,  FILL,
FILL, FILLC,  FILLC,  FILL,
FILL, FILLC,  FILLC,  FILL,
FILLC,  FILL, FILL, FILLC
};
char s1[][SYML] = {

FILLC,  FILLC,  FILL, FILLC,
FILLC,  FILL, FILL, FILLC,
FILLC,  FILLC,  FILL, FILLC,
FILLC,  FILLC,  FILL, FILLC,
FILLC,  FILLC,  FILL, FILLC,
FILLC,  FILL, FILL, FILL
};
char s2[][SYML] = {
FILLC,  FILL, FILL, FILLC,
FILL, FILLC,  FILLC,  FILL,
FILLC,  FILLC,  FILL, FILLC,
FILLC,  FILL, FILLC,  FILLC,
FILL, FILLC,  FILLC,  FILLC,
FILL, FILL, FILL, FILL
};
char s3[][SYML] = {
FILLC,  FILL, FILL, FILLC,
FILL, FILLC,  FILLC,  FILL,
FILLC,  FILLC,  FILL, FILLC,
FILLC,  FILLC,  FILLC,  FILL,
FILL, FILLC,  FILLC,  FILL,
FILLC,  FILL, FILL, FILLC
};
char s4[][SYML] = {
FILL, FILLC,  FILLC,  FILL,
FILL, FILLC,  FILLC,  FILL,
FILL, FILLC,  FILLC,  FILL,
FILLC,  FILL, FILL, FILL,
FILLC,  FILLC,  FILLC,  FILL,
FILLC,  FILLC,  FILLC,  FILL
};
char s5[][SYML] = {
FILL, FILL, FILL, FILL,
FILL, FILLC,  FILLC,  FILLC,
FILL, FILL, FILL, FILLC,
FILLC,  FILLC,  FILLC,  FILL,
FILL, FILLC,  FILLC,  FILL,
FILLC,  FILL, FILL, FILLC
};
char s6[][SYML] = {
FILLC,  FILL, FILL, FILL,
FILL, FILLC,  FILLC,  FILLC,
FILL, FILL, FILL, FILLC,
FILL, FILLC,  FILLC,  FILL,
FILL, FILLC,  FILLC,  FILL,
FILLC,  FILL, FILL, FILLC
};
char s7[][SYML] = {
FILL, FILL, FILL, FILL,
FILLC,  FILLC,  FILLC,  FILL,
FILLC,  FILLC,  FILLC,  FILL,
FILLC,  FILLC,  FILL, FILLC,
FILLC,  FILL, FILLC,  FILLC,
FILL, FILLC,  FILLC,  FILLC
};
char s8[][SYML] = {
FILLC,  FILL, FILL, FILLC,
FILL, FILLC,  FILLC,  FILL,
FILLC,  FILL, FILL, FILLC,
FILL, FILLC,  FILLC,  FILL,
FILL, FILLC,  FILLC,  FILL,
FILLC,  FILL, FILL, FILLC
};
char s9[][SYML] = {
FILLC,  FILL, FILL, FILLC,
FILL, FILLC,  FILLC,  FILL,
FILL, FILLC,  FILLC,  FILL,
FILLC,  FILL, FILL, FILL,
FILLC,  FILLC,  FILLC,  FILL,
FILLC,  FILL, FILL, FILLC
};
char sProm[][1] = {
FILLC,
FILLC,
FILLC,
FILLC,
FILLC,
FILLC
};


/*++-------------------------------------------------------------*/
char *enterNumsStr() {
int i;
static char txt[MAXLENSTR];

	i = 0;
	while (((txt[i]=getchar()) != '\n') && ( i < MAXLENSTR))
		if ( (txt[i] == '-') || (txt[i] >= '0') && (txt[i] <='9') )
			i++;
	txt[i]='\0';
//	printf ("%s\n", txt);

	return txt;
}

/*++-------------------------------------------------------------*/
struct sizeString countNecMem (char *str) {
	int i;
	struct sizeString tmp;

	for (i = 0; str[i] != '\0'; i++ )
		;

	tmp.len = i*SYML+i-1;
	tmp.hig = SYMH;
	tmp.vol = (tmp.len*tmp.hig*sizeof(char)); ///struct sizeString));//char));

	return tmp;
}

/*-------------------------------------------------------------*/
int addNum (char symb[][SYML], struct sizeString runS, int pos) {
int i, j;

	for ( i = 0; i < SYMH; i++)
		for ( j = 0; j < SYML; j++) {
			runS.arr[i][j+pos] = symb[i][j];
//			printf ("%c!", symb[i][j]);
		}
	return (j + pos);
}

/*-------------------------------------------------------------*/
struct sizeString makeStr (char *ch) {
int i, j, stPos;


	runStr = countNecMem(ch);

	printf ("%d %d %d\n", runStr.len, runStr.hig, runStr.vol);

	runStr.arr = (char **) malloc ( runStr.hig * sizeof(char));

	for ( i = 0; i < runStr.hig; i++)
		runStr.arr[i] = (char *) malloc ( runStr.len * sizeof(char));

//	stPos = 0;
	for ( i = stPos = 0; ch[i] != '\0'; i++) {
		switch (ch[i]) {
			case '-': stPos = addNum (sMinus, runStr,\
						 stPos);
				break;
			case '0': stPos = addNum (s0, runStr,\
						 stPos);
				break;
			case '1': stPos = addNum (s1, runStr,\
						 stPos);
				break;
			case '2': stPos = addNum (s2, runStr,\
						 stPos);
				break;
			case '3': stPos = addNum (s3, runStr,\
						 stPos);
				break;
			case '4': stPos = addNum (s4, runStr,\
						 stPos);
				break;
			case '5': stPos = addNum (s5, runStr,\
						 stPos);
				break;
			case '6': stPos = addNum (s6, runStr,\
						 stPos);
				break;
			case '7': stPos = addNum (s7, runStr,\
						 stPos);
				break;
			case '8': stPos = addNum (s8, runStr,\
						 stPos);
				break;
			case '9': stPos = addNum (s9, runStr,\
						 stPos);
				break;

			default : break;
/*			case '-': addNumX (, char chArr[][], stPos);
				break;
*/
		}
		for ( j = 0; j < SYMH; j++)
			runStr.arr[j][stPos] = FILLC;
		stPos++;

//		printf ("%c!\n", ch[i]);
	}

	return runStr;
}
/*++-------------------------------------------------------------*/
void writeStr (struct sizeString runs) {
int i, j;

	for ( i = 0; i < runs.hig; i++) {
		for (j = 0; j < runs.len; j++)
			printf ("%c", runs.arr[i][j]);
		printf ("!\n");
	}
	printf ("Press any key for continue...\n");
	getch();
}
/*-------------------------------------------------------------*/
void writeRunStr (struct sizeString runs) {
int i, j, jdif, jm;

	while (1) {
		jm = 0;

		for (jdif = abs(runs.len - MONL); jdif > 0 ; jdif--) {

			clrscr();

			for ( i = 0; i < runs.hig; i++) {

				for (j = jm; j < runs.len; j++)
					printf ("%c", runs.arr[i][j]);

				for (j = 0; j < jdif; j++)
					printf ("%c", FILLC);

				for (j = 0; j < jm; j++)
					printf ("%c", runs.arr[i][j]);

				for (j = 0; j < (MONL-runs.len-jdif) ; j++)
					printf ("%c", FILLC);

				printf ("\n");
			}

			if (jm < runs.len ) {
				jm++;
				jdif++;
			}

			printf ("\n\nPress any key for stop runnig string.\n");
			if (kbhit())
				return 0;
			delay (100);
	      }
	}
}

/*=============================================================*/
/*++-------------------------------------------------------------*/
void askForPrint () {

char ch;

	printf ("Continue? [y,n]: ");

	while (1) {
		ch = getch();
		if ( (ch == 'n') || ( ch  == 'N')) {
			printf ("%c", ch);
			exit(); //return 0;
		} else if ( (ch == 'y') || ( ch  == 'Y')) {
			printf ("%c", ch);
			printf ("\n");
			break;
		}
	}
}

/*-------------------------------------------------------------*/
int main () {

char *strP;

//	clrscr();

	/* enter the string */
	printf ("The program takes numbers and makes running string with it.\n");
	printf ("Enter the text (only numbers and symbol minus):\n");

	//strP = enterNumsStr();

	strP = "491-63-26";

	printf ("We have got the next string:\n");
	printf ("%s\n\n", strP);

	/* count neccesary memory */
	printf ("Output of running string takes !--%d--! bytes of memory.\n",\
		 countNecMem(strP).vol);

	/* asking about continuie */
	//askForPrint();

	/* make an array */
	//makeStr(strP);

	/* show array */
	writeStr(makeStr(strP));

	writeRunStr(makeStr(strP));

	//getchar();

	return 0;

}

/*
-,
0, 0, 0, 0,
0, 0, 0, 0,
0, 1, 1, 0,
0, 0, 0, 0,
0, 0, 0, 0,
0, 0, 0, 0,

0,
0, 1, 1, 0,
1, 0, 0, 1,
1, 0, 0, 1,
1, 0, 0, 1,
1, 0, 0, 1,
0, 1, 1, 0,
,
1,
0, 0, 1, 0,
0, 1, 1, 0,
0, 0, 1, 0,
0, 0, 1, 0,
0, 0, 1, 0,
0, 1, 1, 1,
,
2,
0, 1, 1, 0,
1, 0, 0, 1,
0, 0, 1, 0,
0, 1, 0, 0,
1, 0, 0, 0,
1, 1, 1, 1,
,
3,
0, 1, 1, 0,
1, 0, 0, 1,
0, 0, 1, 0,
0, 0, 0, 1,
1, 0, 0, 1,
0, 1, 1, 0,
,
4,
1, 0, 0, 1,
1, 0, 0, 1,
1, 0, 0, 1,
0, 1, 1, 1,
0, 0, 0, 1,
0, 0, 0, 1,
,
5,
1, 1, 1, 1,
1, 0, 0, 0,
1, 1, 1, 0,
0, 0, 0, 1,
1, 0, 0, 1,
0, 1, 1, 0,
,
6,
0, 1, 1, 1,
1, 0, 0, 0,
1, 1, 1, 0,
1, 0, 0, 1,
1, 0, 0, 1,
0, 1, 1, 0,
,
7,
1, 1, 1, 1,
0, 0, 0, 1,
0, 0, 0, 1,
0, 0, 1, 0,
0, 1, 0, 0,
1, 0, 0, 0,
,
8,
0, 1, 1, 0,
1, 0, 0, 1,
0, 1, 1, 0,
1, 0, 0, 1,
1, 0, 0, 1,
0, 1, 1, 0,
,
9,
0, 1, 1, 0,
1, 0, 0, 1,
1, 0, 0, 1,
0, 1, 1, 1,
0, 0, 0, 1,
0, 1, 1, 0,
*/
