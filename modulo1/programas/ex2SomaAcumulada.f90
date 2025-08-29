program soma_acumulada
  implicit none
  integer :: i, n
  real(8) :: soma_prog, soma_regr, exato, erro_prog, erro_regr

  n = 1000000
  soma_prog = 0.0d0
  soma_regr = 0.0d0
  exato = 1.6449340668482264d0

  do i = 1, n
    soma_prog = soma_prog + 1.0d0 / (dble(i)*dble(i))
  end do

  do i = n, 1, -1
    soma_regr = soma_regr + 1.0d0 / (dble(i)*dble(i))
  end do

  erro_prog = abs(soma_prog - exato)
  erro_regr = abs(soma_regr - exato)

  print *, "Soma progressiva: ", soma_prog
  print *, "Soma regressiva: ", soma_regr
  print *, "Erro progressivo: ", erro_prog
  print *, "Erro regressivo: ", erro_regr
end program soma_acumulada
