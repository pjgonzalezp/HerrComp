# esto es un comentario

all: fig.pdf

sumas.x: sumas.cpp
	g++ sumas.cpp -o sumas.x

#restas.x: restas.cpp
#	g++ restas.cpp -o restas.x

datos.txt: sumas.x
	./sumas.x > datos.txt


fig.pdf: plot.py datos.txt
	python3 plot.py
