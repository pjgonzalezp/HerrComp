all: datos.txt

CXX=g++
OBJECTS=Coffee-3.o Cof-simul.o
CPPFILES=Coffee-3.cpp Cof-simul.cpp
HEADERS=Molecule.h Cof-simul.h
CXXFLAGS= -O3 
SANITFLAGS= -g -fsanitize=leak -fsanitize=address -fsanitize=undefined
VALGRINDFLAGS= --tool=memcheck
GPRFLAGS=-pg

Coffee-3.x: $(OBJECTS) Molecule.h
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $(OBJECTS) -o $@

datos.txt: Coffee-3.x
	./$< > $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

fig3: datos.txt
	gnuplot $@.gp

memcheck: $(OBJECTS) Molecule.h
	rm -f *.x *.txt
	$(CXX) -O3  $(OBJECTS) -o $@.x
	valgrind $(VALGINDFLAGS) ./$@.x

gprof: $(CPPFILES) Molecule.h
	$(CXX) $(CXXFLAGS) $(GPRFLAGS) $(CPPFILES) -o Coffee-gprof.x
	./Coffee-gprof.x
	$@ ./Coffee-gprof.x > gprof-report.txt

cachegrind: $(CPPFILES) Molecule.h
	$(CXX) $(CXXFLAGS) $(CPPFILES) -o Coffee-cachegrind.x
	valgrind --tool=cachegrind ./Coffee-cachegrind.x
	cg_annotate $$(ls -t cachegrind.out.* | head -n 1) > cachegrind-report.txt

clean:
	rm -f *.o *.x *.txt
