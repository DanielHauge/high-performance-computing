set xlabel 'Memory footprint'                              # x-axis label
set ylabel 'Mega flops'                          # y-axis label

# Set outputfile
set terminal png
set output 'plot.png'

# Add legend
set key top left


plot 'gg.dat' with lines


