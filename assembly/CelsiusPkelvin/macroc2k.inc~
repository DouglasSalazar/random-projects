%macro _printNum 2

    ;salva todos os registradores mais comuns
    push rax
    push rbx
    push rcx       
    push rdx
    
    mov rax,%1
    ;divide por 10
    xor rcx,rcx           ;xor reg,reg zera reg. Melhor que mov reg, 0
    xor rdx,rdx
    xor rbx,rbx
    %%_divide:
       mov rbx,10
       div bl        ;divide o acumulador ax por 10. Nao se permite div 10, div 3, div 20, etc
       add ah,'0'    ;al quociente, ah é o resto, temos que guardar ah. Não importa o que está em al
       push rax      ;deveria empilhar somente ah, mas temos que empilhar todo o rax
       inc rcx       ;conta elementos na pilha 
       and ax,0x00ff ;zera ah: fica somente com al (ax tem 2 bytes e dois nibble de 1 byte). LEMBRAM QUE EU TINHA COLOCADO and ax,0xff00?
                    ;Como só podemos dividir ax por 10 e não somente al, temos que zerar ah, a parte alta.
    
       ;cmp al,0      ;verifica se o quociente foi zero. Se for zero, acabou o processo de divisao. DESNECESSÁRIO NESSE CASO, POIS O zf INFORMA AO jnz
       jnz %%_divide   ;Se o quociente for diferente de zero, salte para o label _divide:
	
      ;imprime elementos da pilha

    %%_imprimeTopo:
              
       pop rax           ;desempilha rax. O que nos interessa é somente o ah, que já está somado com '0'. O que tem em al não interessa.
       push rcx          ;guarda valor antigo do contador de elementos da pilha, que está sendo usado na repetição do label _imprimeTopo   
       mov byte [%2],ah ; pega o resto e guarda na variável aux. No endereço de aux
       mov eax,4         ;escrita
       mov ebx,1         ;fd=1, na tela
       mov ecx,%2       ;&buffer a ser impresso, no caso um caractere só
       mov edx,1         ;tamanho a ser gravado. Se é um caractere só, o tamanho é 1. 
       int 0x80
	
       pop rcx        ;recupera o tamanho da pilha
       dec rcx        ;atualiza o tamanho
       ;cmp rcx,0     ;DESNECESSÁRIO NESSE CASO, POIS O zf INFORMA AO jnz
       jnz %%_imprimeTopo
       
       ;recupera os registradores mais comuns
       pop rdx
       pop rcx
       pop rbx       
       pop rax
%endmacro

%macro _printf 2
   push rax
   push rbx
   push rcx
   push rdx

   mov eax,4      ;escrita
   mov ebx,1      ;fd=1, na tela
   mov ecx,%1 ;&buffer a ser impresso, no caso um caractere só
   mov edx,%2      ;tamanho a ser gravado. Se é um caractere só, o tamanho é 1. 
   int 0x80 
  
   pop rdx
   pop rcx
   pop rbx       
   pop rax 
%endmacro

;%macro %endmacro

%macro _exit 1
  mov rax,1
  mov rbx,%1
  int 0x80
%endmacro

;%macro nomeMacro numArg
;   push rax
;   push rbx
;   push rcx
;   push rdx

     
;   pop rdx
;   pop rcx
;   pop rbx       
;   pop rax 
;%endmacro

