//C++
#include <cstdio>

int fib( const int n )
{
	if ( n <= 1 ) return n;

	return fib( n - 1 ) + fib( n - 2 );
}

int main()
{
	for ( auto i = 0; i < 20; ++i )
		printf( "%d\n", fib( i ) );
}

//C++ e MASM X86 Fibonacci Algorithm
#include <iostream>
char    format[] = "%d\n";
_declspec (naked) int fibonacci(const int n)
{
    __asm
    {
        push ebp
        mov ebp, esp
        sub esp, 4
        push ebx
        push esi
        mov ecx, 30
        mov eax, 0xCCCCCCCC
        cmp DWORD PTR[ebp + 8], 1
        jg loop_1
        mov eax, DWORD PTR [ebp+8]
        jmp loop_2
    loop_1:
        mov eax, DWORD PTR[ebp + 8]
        sub eax, 1
        push eax
        call fibonacci
        add esp, 4
        mov esi, eax
        mov ecx, DWORD PTR[ebp + 8]
        sub ecx, 2
        push ecx
        call fibonacci
        add esp, 4
        add eax, esi
    loop_2:
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret
    }
}

int main()
{
    _asm
    {
            push ebp
            mov ebp, esp
            sub esp, 4
            push ebx
            mov eax, 0xCCCCCCCC
            mov DWORD PTR[ebp+8], 0
        jmp loop_1
        loop_3:
            mov eax, DWORD PTR [ebp + 8]
            add eax, 1
            mov DWORD PTR[ebp+8], eax
        loop_1:
            cmp DWORD PTR[ebp+8], 20
        je loop_2
            mov eax, DWORD PTR [ebp+8]
            push eax
            call fibonacci
            add esp, 4
            push eax
            push offset format
            call dword ptr [printf]
            add esp, 8
        jmp loop_3
        loop_2:
            pop ebx
            mov esp, ebp
            pop ebp
            leave
            ret
    }
}