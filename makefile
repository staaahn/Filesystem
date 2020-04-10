clean:
  rm ./a.out

compile:
  gcc main.c
  
run:
  make clean
  make compile
  ./a.out


