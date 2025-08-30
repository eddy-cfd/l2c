program tempo_execucao
  implicit none
  integer :: i
  real(8) :: s, t_start, t_end

  s = 0.0d0
  call cpu_time(t_start)

  do i = 1, 100000000
     s = s + 1.0d0 / dble(i)
  end do

  call cpu_time(t_end)

  print *, 'Resultado da soma: ', s
  print *, 'Tempo de execução: ', t_end - t_start, 'segundos'
end program tempo_execucao
