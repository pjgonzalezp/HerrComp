f(x) = A*x**2
fit f(x) 'fig2-2.txt' via A
set xlabel 'Lado del contenedor'
set ylabel 'Tiempo en alcanzar el equilibrio'
set term pdf
set out "fig2-2.pdf"
plot 'fig2-2.txt' w lp lw 3 t 't_e_q_. vs. Lc', f(x) lw 3 t 'Ajuste: Lc^2'
