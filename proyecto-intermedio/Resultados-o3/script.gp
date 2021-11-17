set log xy
set xlabel 'Numero de iteraciones'
set ylabel 'CPU time (s)'
set term pdf
set out 'fig-o3.pdf'
plot 'datos.txt' u 1:2 w lp lw 4 t 'Datos con O3', 'datos.txt' u 1:3 w lp lw 4 t 'Datos sin O3'
