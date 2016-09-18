#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
	char data:1;
} bit_type;

bit_type memory[] = {{0},{0},{0},{0}};

char nor_op(char a, char b){
	return a==0 && b==0 ? 1:0;
}

typedef struct {
	long mapping[3];
	long paths[2];
} instruction_type;

#define PATH_CHOOSER 0
#define OUT 1
#define IN 2

#define EXIT -1
long current_op = 0;

instruction_type instructions[] =  { 
	{ {OUT, IN, IN}, {1,1} },
	{ {PATH_CHOOSER, IN, IN}, {0,EXIT} }
};

int getbit(){
	char ch = getche();
	if (ch=='0' || ch=='1') return ch-'0';
	else if (ch=='q') exit(0);
	else return -1;
}

int getinput(long* mapping, int index){
	if(mapping[index]==IN) {
		int out; while( (out=getbit()) == -1 ){
			printf(".insert bit or quit.");
		}
		memory[mapping[index]].data = out;
	}
	return memory[mapping[index]].data==0?0:1;
}

void perform_operation(){
	instruction_type instruction = instructions[current_op];
	memory[instruction.mapping[0]].data = nor_op(
		getinput(instruction.mapping, 1),
		getinput(instruction.mapping, 2)
	);
	if(instruction.mapping[0]==OUT)printf("%d",memory[OUT].data==0?0:1);
}

void path_choice(){
	instruction_type instruction = instructions[current_op];
	current_op = instruction.paths[
		memory[PATH_CHOOSER].data==0?0:1
	];
}

int main(int argc, char **argv) {
	
	while(1){
		if(current_op==EXIT) break;
		perform_operation();
		path_choice();
	}
	
	return 0;
}
