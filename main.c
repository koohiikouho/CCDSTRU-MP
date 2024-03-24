#include <stdbool.h>
#include <stdio.h>

struct strLoc
{
	int x,
		y;
	bool exist;
};

void effThreeMaker(struct strLoc eff[6][6], struct strLoc effOne[6][6], struct strLoc effTwo[6][6], struct strLoc effThree[6][6])
{
	int i, j;
	for(i = 0; i < 6; i++)
		for(j = 0 ; j < 6; j++)
			if(eff[i][j].x == effOne[i][j].x && eff[i][j].y == effOne[i][j].y && effOne[i][j].exist == true)
				effThree[i][j].exist = true;

	for( i = 0; i < 6; i++)
		for(j = 0 ; j < 6; j++)
			if(eff[i][j].x == effTwo[i][j].x && eff[i][j].y == effTwo[i][j].y && effTwo[i][j].exist == true)
				effThree[i][j].exist = true;			
}

bool overChecker(struct strLoc effThree[6][6], struct strLoc seeOne[2][2], struct strLoc seeTwo[2][2], struct strLoc pos)
{
	int i, j;
	bool effThreeIsZero = true;
	bool 	exInSeeOne, 
			exInSeeTwo,
			exInPee; //:D
	if(seeOne[ pos.x - 1 ][ pos.y - 1 ].exist == true )
		exInSeeOne = true;
	if(seeTwo[ pos.x - 1 ][ pos.y - 1 ].exist == true )
		exInSeeTwo = true;

	for(i = 0; i < 2; i++)
		for(j = 0; j <2; j++)
			if(seeTwo[ pos.x - 1][ pos.y - 1 ].exist == true)	
				exInPee = true;
				
				
	for(i = 0; i < 6; i++)
		for(j = 0; i < 6; j++ )
			if(effThree[i][j].exist == true)
				effThreeIsZero = false;

	if(effThreeIsZero == true || (exInSeeOne == true && exInPee == true) || (exInSeeTwo == true && exInPee == true))
	return true;
	else
	return false;
}

int powerSeteffExCheckWithS(struct strLoc effOne[6][6])
{
	int i, j,
		nAccumulator1 = 0,
		nAccumulator2 = 0,
		nAccumulator3 = 0,
		nAccumulator4 = 0,
		nCardinality = 0;
	int nSetOne[2][5] = { 	{1, 1, 2, 3, 3},
							{1, 3, 2, 1, 3} 
						};
	int nSetTwo[2][5] = { {4, 4, 5, 6, 6}, {4, 6, 5, 4, 6} };
	int nSetThree[2][5] ={ {1, 2, 2, 2, 3}, {5, 4, 5, 6, 5} };
	int nSetFour[2][6] = { {4, 4, 5, 5, 6, 6}, {1, 3, 1, 3, 1, 3} };
	
	for(i = 0; i < 5; i++)
		if(effOne[ nSetOne[1][i] ][ nSetOne[2][i] ].exist == true)
				nAccumulator1++;
	
	for(i = 0; i < 5; i++)
		if(effOne[ nSetTwo[1][i] ][ nSetTwo[2][i] ].exist == true)	
				nAccumulator2++;

	for(i = 0; i < 5; i++)
		if(effOne[ nSetTwo[1][i] ][ nSetTwo[2][i] ].exist == true)	
				nAccumulator3++;

	for(i = 0; i < 5; i++)
		if(effOne[ nSetTwo[1][i] ][ nSetTwo[2][i] ].exist == true)	
				nAccumulator4++;
	
	if(nAccumulator1 == 5)
		nCardinality++;
	if(nAccumulator2 == 5)
		nCardinality++;
	if(nAccumulator3 == 5)
		nCardinality++;
	if(nAccumulator4 == 6)
		nCardinality++;
		
return nCardinality;
			
}

void readyPlayerMove(struct strLoc pos, bool over, bool next, bool good, struct strLoc effThree[6][6], struct strLoc effOne[6][6], struct strLoc effTwo[6][6],
struct strLoc seeOne[2][2], struct strLoc seeTwo[2][2])
{
	int a, b,
		c, d,
		i, j,
		nPEffOneIntersectS,
		nPEffTwoIntersectS,
		nSeeOneCardinality = 0, 
		nSeeTwoCardinality = 0;
		
	bool xyInEffThree;
	a = pos.x;
	b = pos.y;
	
	if(effThree[pos.x - 1][pos.y - 1].exist == true)
		xyInEffThree = true;
				
	nPEffOneIntersectS = powerSeteffExCheckWithS(effOne);
	nPEffTwoIntersectS = powerSeteffExCheckWithS(effTwo);
	
	for(i = 0; i < 2; i++)
		for(j = 0; j <2; j++)
			if(seeOne[i][j].exist == true)
				nSeeOneCardinality++;
				
	for(i = 0; i < 2; i++)
		for(j = 0; j <2; j++)
			if(seeTwo[i][j].exist == true)
				nSeeTwoCardinality++;
	
	c = (a - 1) / 3 + 1;
	d = (b - 1) / 3 + 1;

	if(over == false && next == true && xyInEffThree == true)
	{
		good = !good;
		effOne[pos.x - 1][pos.y -1].exist = true;
	}
	if(over == false && next == false &&  xyInEffThree == true)
	{
		good = !good;
		effOne[pos.x - 1][pos.y -1].exist = true;
	}
	if(over == false && good == true && next == true && nPEffOneIntersectS > nSeeOneCardinality)
	{
		seeOne[ c - 1 ][ d - 1 ].exist = true;
	}
	if(over == false && good == true && next == true && nPEffTwoIntersectS > nSeeTwoCardinality)
	{
		seeOne[ c - 1 ][ d - 1 ].exist = true;
	}
	
}

void gameOver(bool over, bool next, struct strLoc pos, struct strLoc seeOne[2][2], struct strLoc seeTwo[2][2])
{
	int i, j;
	bool 	exInSeeOne, 
			exInSeeTwo,
			exInPee; //:D
	if(seeOne[ pos.x - 1 ][ pos.y - 1 ].exist == true )
		exInSeeOne = true;
	if(seeTwo[ pos.x - 1 ][ pos.y - 1 ].exist == true )
		exInSeeTwo = true;

	for(i = 0; i < 2; i++)
		for(j = 0; j <2; j++)
			if(seeTwo[ pos.x - 1][ pos.y - 1 ].exist == true)	
				exInPee = true;
				
	if( over == true && next == true && exInSeeOne == true && exInPee == true )
		printf("\nA wins\n");
	if( over == true && next == true && exInSeeTwo == true && exInPee == true )
		printf("\nA wins\n");	
	if(over == false)
		next = !next;
}

void printBoard(struct strLoc eff[6][6])
{
	int i, j;
	for( i = 0; i < 6; i++)
	{
		for(j = 0 ; j < 6; j++)		
			printf(" %d %d [%d]| ", eff[i][j].x, eff[i][j].y, eff[i][j].exist);
	printf("\n");
	}
			
}					
void fill(int first, int last, struct strLoc arr[first][last], bool tOrF)
{
	int i, j;
	for( i = 0; i < first; i++)
		for(j = 0 ; j < last; j++)
		{	arr[i][j].x = i +1;
			arr[i][j].y = j + 1;
			if(tOrF == false)
			arr[i][j].exist = false;
			else 
			arr[i][j].exist = true;
		};	
}

int main()
{
//system initializations
	int i, j, x, y;
	struct strLoc varLoc;
	struct strLoc 	see[2][2],
					seeOne[2][2],
					seeTwo[2][2],
					effOne[6][6],
					effTwo[6][6],
					effThree[6][6],
					eff[6][6],
					pos;
	fill(2, 2, see, true);
	fill(2, 2, seeOne, false);
	fill(2, 2, seeTwo, false);
	fill(6, 6, eff, true);
	fill(6, 6, effOne, false);
	fill(6, 6, effTwo, false);
	fill(6, 6, effThree, false);
	
	bool 	good = false,
			next = false,
			over;
			
//System Facts


	effThreeMaker(eff, effOne, effTwo, effThree);
	printBoard(effThree);
	
	do
	{

	do
	{
	fflush(stdin);
	scanf("%d %d", &pos.x, &pos.y);
	}while(!(pos.x > 0 && pos.x < 7 && pos.x > 0 && pos.x < 7));
	
	over = overChecker(effThree, seeOne, seeTwo, pos);	
	readyPlayerMove(pos, over, next, good, effThree, effOne, effTwo, seeOne, seeTwo);
	gameOver(over, next, pos, seeOne, seeTwo);
	
	}while(over == false)	;
	
	
	
			
}