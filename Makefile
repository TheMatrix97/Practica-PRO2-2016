OPTIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++0x

program.exe: GestorTextos.o GestorCites.o text.o cita.o program.o
	g++ -o program.exe program.o GestorTextos.o GestorCites.o text.o cita.o

GestorTextos.o: GestorTextos.hh
	g++ -c GestorTextos.cc GestorTextos.hh $(OPTIONS)

GestorCites.o: GestorCites.hh
	g++ -c GestorCites.cc GestorCites.hh $(OPTIONS)
text.o:	text.hh
	g++ -c text.cc text.hh $(OPTIONS)
cita.o: cita.hh
	g++ -c cita.cc cita.hh $(OPTIONS)
program.o:
	g++ -c program.cc $(OPTIONS)


practicaPRO2.tar:
	tar -cvf PracticaPRO2.tar *.hh *.cc *.txt Makefile
clean:
	rm *.o
	rm *.exe


