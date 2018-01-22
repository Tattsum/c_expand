set title "sim.txt"
set xlabel "time (sec.)"
set ylabel "pos.(m), vel.(m/s), acc.(m/s^{2})"
plot "sim.txt" using 1:2 w l title "pos."
replot "sim.txt" using 1:3 w l title "vel."
replot "sim.txt" using 1:4 w l title "acc."
pause -1
