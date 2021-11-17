set xlabel 'X'
set ylabel 'Y'
set size square
set term pdf
set out "fig3-0.pdf"
plot [-100:100][-100:100] 'datos.txt' u 2:3 pt 7 ps 0.5 t 'Crema en el café t=0'
