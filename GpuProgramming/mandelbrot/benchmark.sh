seq 1 40 | xargs -I ½ sh -c 'echo "Threads: ½" && time $(OMP_NUM_THREADS=½ ./mandelbrot)'
