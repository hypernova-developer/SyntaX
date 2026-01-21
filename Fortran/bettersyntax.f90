!==============================================================================
! Project: SyntaX
! Library: bettersyntax for Fortran
! Author: hypernova-developer
! License: GPL-3.0
! Version: 1.0.0 (Fortran Edition)
! Description: Simplifying Fortran syntax for the SyntaX family.
!==============================================================================

module bettersyntax
    implicit none
    private
    
    ! Public procedures
    public :: print_s, input_s, sleep_s, clear_s

contains

    ! --- Standard Output ---
    subroutine print_s(message)
        character(len=*), intent(in) :: message
        print *, trim(message)
    end subroutine print_s

    ! --- Standard Input ---
    subroutine input_s(prompt, buffer)
        character(len=*), intent(in) :: prompt
        character(len=*), intent(out) :: buffer
        write(*, '(A)', advance='no') trim(prompt) // " "
        read(*, '(A)') buffer
    end subroutine input_s

    ! --- Sleep Function (Modern F2008+) ---
    subroutine sleep_s(seconds)
        real, intent(in) :: seconds
        integer :: count, count_rate, count_max
        real :: t1, t2
        
        call system_clock(count, count_rate, count_max)
        t1 = real(count) / real(count_rate)
        t2 = t1
        do while (t2 - t1 < seconds)
            call system_clock(count)
            t2 = real(count) / real(count_rate)
        end do
    end subroutine sleep_s

    ! --- Terminal Screen Clearing ---
    subroutine clear_s()
        ! Uses system command to clear terminal
        call execute_command_line('cls')
    end subroutine clear_s

end module bettersyntax
