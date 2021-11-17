f(x) = a*x**0.5 + b
fit [0:600000] f(x) 'datos.txt' via a,b
set xlabel 'Tiempo (10^6 pasos)'
set ylabel 'Tamaño de la gota'
set key at 800000,20
set term pdf
set out "fig3.pdf"
plot 'datos.txt' w l lw 2 t 'Tamaño vs. t', f(x) w l lw 2 t 'Ajuste : t^1^/^2'
