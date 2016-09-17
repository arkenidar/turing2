#include <stdio.h>
#include <stdlib.h>

typedef char bit_type;

typedef struct {
	bit_type data:1;
} bit_data;

typedef struct {
	unsigned long mapping[3];
	unsigned long paths[2];
} instruction_type;

bit_type nor_op(bit_type a, bit_type b) { return a==0&&b==0?1:0; }
bit_data memory[] = {{0},{0},{0}};

instruction_type instructions[] =  { 
	{ {1,0,0}, {1,1} },
	{ {1,1,1}, {0,0} }
};

unsigned long current_op = 0UL;

#define PATH_CHOOSER 0UL
#define OUT 1UL
#define EXIT 2UL

void perform_operation(){
	instruction_type instruction = instructions[current_op];
	memory[instruction.mapping[0]].data = nor_op(
		memory[instruction.mapping[1]].data,
		memory[instruction.mapping[2]].data
	);
	if(instruction.mapping[0]==OUT)printf("%d",memory[OUT].data==0?0:1);
}

void path_choice(){
	instruction_type instruction = instructions[current_op];
	current_op = instruction.paths[
		memory[PATH_CHOOSER].data
	];
}

int main(int argc, char **argv) {
	
	while(1){
		perform_operation();
		path_choice();
		if(current_op==EXIT) break;
	}
}
