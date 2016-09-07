// turing.c : minimal, modern, turing completess
/* This is Software Code in "C" programming language for a Turing Machine
automaton with non-sequential memory access for RAMs in place 
of magnetic tapes and a single, universal, NOR operation 
(NOR as universal logic gate), a design chosen applying the Ockham Razor 
(law of parsimony). This is a "Turing complete" system, possibly 
one of the set of minimal designs for doing computations
with Turing completeness.

Links:
https://en.wikipedia.org/wiki/Minimal_instruction_set_computer
https://pragprog.com/magazines/2012-03/the-nor-machine
http://pp.ipd.kit.edu/firm/
http://prize.hutter1.net/

*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*
int nor_op(int a, int b) { return a==0&&b==0?1:0; }
int nor_mapping[][3] = {{1,0,0},{1,1,1}};
int paths[][2] = {{1,1},{0,0}};
int memory[]={0,0};
int current_op=0;
#define EXIT -1
#define PATH_CHOOSER 0
#define OUT 1
#define IN 2
//for(int n=0; 1; n++, n%=2)printf("%d", n);//similar program, optimized
*/
int nor_op(int a, int b) { return a==0&&b==0?1:0; }
int nor_mapping[][3] = {{1,2,2},{0,2,2}};
int paths[][2] = {{1,1},{0,-1}};
int memory[]={0,0,0};
int current_op=0;
#define EXIT -1
#define PATH_CHOOSER 0
#define OUT 1
#define IN 2
int getbit(){
	int ch = getche();
	if (ch=='0' || ch=='1') return ch-'0';
	else if (ch=='q') exit(0);
	else return -1;
}
int getinput(int* mapping, int index){
	if(mapping[index]==IN) {
		int out; while( (out=getbit()) == -1 ){ printf("!bit or quit!"); }
		memory[mapping[index]] = out;
	}
	return memory[mapping[index]];
}
int perform_operation(){
	int* mapping=nor_mapping[current_op];
	memory[mapping[0]]=nor_op(getinput(mapping, 1), getinput(mapping, 2));
	if(mapping[0]==OUT) return 1; else return 0;
}
void path_choice(){ current_op=paths[current_op][memory[PATH_CHOOSER]];}
int main(int argc, char **argv) {
	while(1){
		if(perform_operation()==1) printf("%d", memory[OUT]);
		path_choice(); if(current_op==EXIT) break;
	}
}
/* This is part of a series of experiments on minimality 
and optimizations of computational systems.
Furthermore, program code optimization,
perhaps, could be applied to the Hutter Prize, a challenge
where the goal is producing the program that outputs a fixed hard coded
bit sequence, with a computer program that is minimal in size,
i.e. achieving compression of bit sequence by means of 
program computation and then program code reduction in size,
this kind of program code optimization. This allows to produce a
short program that outputs a bit sequence, a file, i.e. achieving
decompression (and compression of course) of files.
This could be understood as producing the best algorithm for
compressing given data, as the choice/production of the best algorithm
for compression depends on data to be compressed.
Although maybe not of a immediate practical use I see this explorations
as interesting for advancing the information's
and computation of information theories. http://prize.hutter1.net/ */
