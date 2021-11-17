set xlabel 'X'
set ylabel 'Y'
set size square
set term pdf
set out "fig3-4.pdf"
plot [-50:50][-50:50] 'datos.txt' u 2:3 pt 7 ps 0.5 t 'Crema en el café t=10^6'
