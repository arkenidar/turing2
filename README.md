# TuringOne / RedTM
TuringOne / RedTM : a reduced design for a modified Turing Machine (minimal, modern, turing completess)

This is Software Code in "C" programming language for a Turing Machine
automaton with non-sequential memory access for RAMs in place 
of magnetic tapes and a single, universal, NOR operation 
(NOR as universal logic gate), a design chosen applying the Ockham Razor 
(law of parsimony). This is a "Turing complete" system, possibly 
one of the set of minimal designs for doing computations
with Turing completeness.
Control flow is graph-based (like in libfirm). but here has been applied a reduction also, without limiting the turing-completeness expressivity.

Historical notes:
The Hutter compression challenge made me think in stimulating ways about programs and posed a challenge which motivated my pursuit for understanding what intelligence, even in machines, is.
During the years many side-tracks were born and the exploration path has proved to me to be noteworthy.
Even if at present time I have not yet formulated an Hutter Challenge solution in terms of the shorter RedTM program code that produces the "goal data" (decompression, fine tuned algorithmically).

Possible future developments:
- code morphing for efficiency and/or security
- data compression (links below)
- VHDL for HW-based RedTM
- software VM for running all kinds of computations (simulation of hardware and software)
- spawing multiple cores is easy as cores are small and cheap!
- optimizations (before-running and during-running) on a uniform computational system

Links:
* http://scottberkun.com/2013/ten-myths-of-innnovation/
* 
* https://en.wikipedia.org/wiki/Theory_of_computation
* https://en.wikipedia.org/wiki/Alan_Turing
* https://en.wikipedia.org/wiki/Turing_machine
* 
* https://en.wikipedia.org/wiki/Minimal_instruction_set_computer
* http://www.instructables.com/id/NOR-as-Universal-Gate/
* https://en.wikipedia.org/wiki/One_instruction_set_computer
* 
* https://pragprog.com/magazines/2012-03/the-nor-machine
* http://pp.ipd.kit.edu/firm/
* https://en.wikipedia.org/wiki/1-bit_architecture
* 
* https://en.wikipedia.org/wiki/Code_morphing
* https://en.wikipedia.org/wiki/Transmeta
* 
* http://prize.hutter1.net/
* https://www.infoq.com/news/2016/09/facebook-zstandard-compression
* 
* https://en.wikipedia.org/wiki/Turing_tarpit
