set xlabel 'Tiempo (10^6 pasos)'
set ylabel 'Entropia'
set xtics 100000
set key at 600000, 2.5
set term pdf
set out 'fig2.pdf'
plot '50.txt' w l t 'LC=50' ,'75.txt' w l t 'LC=75','100.txt' w l t 'LC=100','125.txt' w l t 'LC=125','150.txt' w l t 'LC=150'
