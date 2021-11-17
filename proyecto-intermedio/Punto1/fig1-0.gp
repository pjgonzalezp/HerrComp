set xlabel 'Tiempo (10^6 pasos)'
set ylabel 'Entropia'
set term pdf
set out "fig1-0.pdf"
plot 'datos.txt' w l lw 2 t 'Entropia vs. t'
