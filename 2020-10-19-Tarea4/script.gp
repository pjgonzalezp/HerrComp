set log xy
f(x) = A*x**B
A=1.5e-7; B=3;
fit f(x) 'datos.txt' via A, B
plot 'datos.txt' w lp lw 4 t 'datos', f(x) lw 5 t 'fit'			
set xlabel 'N'								
set ylabel 'CPU time (s)'
set term pdf								
set out "fig.pdf"
replot
