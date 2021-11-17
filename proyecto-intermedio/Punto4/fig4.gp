f(x) = 400*exp(-x/c)
fit f(x) 'datos.txt' via c
set xlabel 'Tiempo (10^6 pasos)'
set ylabel 'Numero de moléculas en el contenedor'
set term pdf
set out "fig4.pdf"
plot 'datos.txt' w l lw 2 t 'Numero de moleculas vs. t', f(x) w l lw 2 t 'Ajuste : exp(-t/{/Symbol t})'
 
