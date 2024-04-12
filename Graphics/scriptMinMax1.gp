set terminal png
set output "outputMediaDecrescente.png"
set title "MediaDecrescente"
set xlabel "Tamanho dos vetores"
set ylabel "Médias de tempo"
set xrange [0:500000]
set yrange [0:1200]
set grid

set term png size 1350, 950

plot "MediaDecrescente.csv" using 1:2 with lines title 'MinMax1', \
     "MediaDecrescente.csv" using 1:3 with lines title 'MinMax2', \
     "MediaDecrescente.csv" using 1:4 with lines title 'MinMax3'
