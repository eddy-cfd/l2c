program zero_maquina
  implicit none
  real(8) :: eps

  eps = 1.0d0
  do while (1.0d0 + eps /= 1.0d0)
     eps = eps / 2.0d0
  end do

  eps = eps * 2.0d0
  print *, "Zero de máquina aproximado: ", eps
end program zero_maquina
