#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char memory[] = {0,0,0,0,0,0,0,0,0,0};

char nor_op(char a, char b){
	return a==0 && b==0 ? 1:0;
}

typedef struct {
	long mapping[3];
	long paths[2];
} instruction_type;

// reserved
#define PATH_CHOOSER 0
#define OUT 1
#define IN 2
#define COPY 3
// first unreserved
#define BASE 4

// reserved
#define EXIT -1
long current_op = 0;

// simple program "demo1"
instruction_type instructions_demo1[] =	{
	{ {OUT, IN, IN}, {1,1} },
	{ {PATH_CHOOSER, IN, IN}, {0, EXIT} }
};

// simple program "pipe"
instruction_type instructions_pipe[] =	{
	{ {OUT, COPY, IN}, {EXIT,EXIT} }
};

// http://www.instructables.com/id/NOR-as-Universal-Gate/

// simple program "not"
instruction_type instructions_not[] =	{
	{ {BASE, COPY, IN}, {1,1} },
	{ {BASE+1, COPY, BASE}, {2,2} },
	{ {OUT, BASE, BASE+1}, {EXIT,EXIT} }
};

// simple program "or"
instruction_type instructions_or[] =	{
	{ {BASE, IN, IN}, {1,1} },
	{ {BASE+1, COPY, BASE}, {2,2} },
	{ {OUT, BASE, BASE+1}, {EXIT,EXIT} }
};

// simple program "and"
#define AND_OUT1 BASE+2
#define BASE2 AND_OUT1+1
#define AND_OUT2 BASE2+2
instruction_type instructions_and[] =	{
	
	// NOT(X)
	{ {BASE, COPY, IN}, {1,1} },
	{ {BASE+1, COPY, BASE}, {2,2} },
	{ {AND_OUT1, BASE, BASE+1}, {3,3} },
	
	// NOT(Y)
	{ {BASE2, COPY, IN}, {4,4} },
	{ {BASE2+1, COPY, BASE2}, {5,5} },
	{ {AND_OUT2, BASE2, BASE2+1}, {6,6} },
	
	// OUT = AND(X,Y) = NOR(NOT(X), NOT(Y))
	{ {OUT, AND_OUT1, AND_OUT2}, {EXIT,EXIT} }
};

// simple program "nand"
#define AND_OUT1 BASE+2
#define BASE2 AND_OUT1+1
#define AND_OUT2 BASE2+2
#define BASE3 AND_OUT2+1
instruction_type instructions_nand[] =	{
	
	// NOT(X)
	{ {BASE, COPY, IN}, {1,1} },
	{ {BASE+1, COPY, BASE}, {2,2} },
	{ {AND_OUT1, BASE, BASE+1}, {3,3} },
	
	// NOT(Y)
	{ {BASE2, COPY, IN}, {4,4} },
	{ {BASE2+1, COPY, BASE2}, {5,5} },
	{ {AND_OUT2, BASE2, BASE2+1}, {6,6} },
	
	// BASE3 = AND(X,Y) = NOR(NOT(X), NOT(Y))
	{ {BASE3, AND_OUT1, AND_OUT2}, {7,7} },
	
	// OUT = NAND(X,Y) = NOT(AND(X,Y)) = NOT(BASE3)
	{ {BASE3+1, COPY, BASE3}, {8,8} },
	{ {OUT, BASE3, BASE3+1}, {EXIT,EXIT} }
};

instruction_type* instructions = instructions_nand;

int getbit(){
	char ch = _getche();
	if (ch=='0' || ch=='1') return ch-'0';
	else if (ch=='q'){
		printf(" } ");
		exit(0);
	}
	else return -1;
}

int getinput(long* mapping, int index){
	if(mapping[index]==IN) {
		int out; while( (out=getbit()) == -1 ){
			printf(" !insert bit or quit! ");
		}
		memory[mapping[index]] = out;
	}
	return memory[mapping[index]];
}

void perform_operation(){
	instruction_type instruction = instructions[current_op];
	if(instruction.mapping[1]==COPY){
		memory[instruction.mapping[0]] = getinput(instruction.mapping, 2);	
	} else {
		memory[instruction.mapping[0]] = nor_op(
			getinput(instruction.mapping, 1),
			getinput(instruction.mapping, 2)
		);
	}
	if(instruction.mapping[0]==OUT)printf("%d",memory[OUT]);
}

void path_choice(){
	instruction_type instruction = instructions[current_op];
	current_op = instruction.paths[
		(int) memory[PATH_CHOOSER]
	];
}

int main(int argc, char **argv) {

	printf(" { ");

	while(1){
		if(current_op==EXIT){
			printf(" } ");
			break;
		}
		perform_operation();
		path_choice();
	}

	return 0;
}
