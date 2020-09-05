Integrantes:
-Daniela Quiroga
-Jose Hernandez
-Paula Gonzalez

Tarea 1. Herramientas computacionales

Ejercicio 9 (página 35)

Write a program to print a table of the function f(x)=5-sqrt(25+x*x) for x=0 to
1 with steps of 0.01. Be sure that your program yields full machine precision,
but do not progrma the proble in double precision. Explain the results


En la función original se expresa la ecuación que proponen en el ejercio usando
la función "sqrtf" que permite calcular de una manera más precisa con datos tipo
flotante. En la función modificada se multiplica y divide por el conjugado
buscando disminuir el error de substracción cancelativa. Como se puede observar
al ejercutar el programa los valores obtenidos difieren en algunos decimales,
esta diferencia se hace mayor para valores cercanos a cero y a medida que x se
acerca a 1 la diferencia disminuye porque el valor de la raíz en la función
original se aleja de 5.0 y por tanto se presenta menor error de substracción cancelativa.

