reset
set terminal pdfcairo enhanced color font "Times,14"
set output 'grafico_sedimentacao.pdf'

set title "Sedimentação de partícula em baixo Reynolds"
set xlabel 't (s)'
set ylabel 'v(t) (m/s)'

set grid
set key at graph 0.7, 0.15 center box spacing 1

# Estilos
set style line 1 lt 1 lw 2 lc rgb "black"
set style line 2 pt 7 ps 0.8 lc rgb "black"

# Plot
plot \
  'solucao_analitica.dat' using 2:1 with lines title 'Solução Analítica' ls 1, \
  'solucao_numerica.dat' using 2:1 every 5 with points title 'Solução Numérica' ls 2
