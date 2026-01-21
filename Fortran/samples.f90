program samples
    use bettersyntax
    implicit none
    
    character(len=20) :: user_name

    ! Initialize SyntaX environment
    call clear_s()
    call print_s("SyntaX for Fortran has been initialized!")
    
    ! Input/Output Demonstration
    call input_s("What is your name?", user_name)
    call print_s("Hello " // trim(user_name) // "!")
    
    ! Timing Demonstration
    call print_s("System will sleep for 2 seconds...")
    call sleep_s(2.0)
    
    call print_s("With SyntaX, every language is now easier.")
end program samples
