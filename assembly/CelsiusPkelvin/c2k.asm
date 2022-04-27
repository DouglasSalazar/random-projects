section .data
  ;*********************************************************************************************
  celsius dw 25, 80, 115, 15  ; VETOR celsius DO TIPO word, SE FOSSE dword SERIA celsius dd 25, 80, 115, 15
  ;*********************************************************************************************
  kelvin dw  0,  0,   0,  0
  aux db 0
  branco db ' '
  ke dw 'Kelvin'
  Ce dw 'Celsius'
  ms dw 'Conversao Celsius para Kelvin'
  eol  db 10 ;nova linha
; kelvin deverá ter 298, 353, 388, 288

;inclusao das macros print e prinf
 %include "macroc2k.inc"

section .text

  global _start

  _start:
;************************************************************************************ 
 ;print da msg e do celsius
 
 _printf ms,29
 _printf eol,1
 _printf eol,1
  mov rax,4      ; faremos 4 repeticoes
  xor rsi,rsi
  _printf Ce,6
  _printf branco,1

  for:
   ;convesao e impressao
   _printNum [celsius+rsi],aux
   ;impressao de um espaço
    _printf branco,1
    add rsi,2
    dec rax         ; decrementa
    cmp rax,0
    jnz for
 

    _printf eol,1

;*********************************************************************************************************
  ;print Kelvin
  
  mov rcx,4      ; faremos 4 repeticoes
  xor rsi,rsi
  _printf ke,6
  _printf branco,1
  forcx:
    lea rbx, [celsius+rsi]

    mov ax, [rbx]         ; nao é possivel fazer mov [kelvin+rsi],[celsius+rsi], precisa-se de um registrador auxiliar
    add ax, 273           ; soma 273
    mov [kelvin+rsi], ax  ; *(kelvin+rsi)=rax  
	
    push rcx       ;guarda valor antigo do contador, que está sendo usado na repetição do label forcx
    ;convesao e impressao
    _printNum rax,aux
    ;impressao de um espaço
    _printf branco,1
    add rsi,2      ; DESLOCAMENTO DE 2 EM 2 BYTES. WORD TEM 2 BYTES. dword tem 4 bytes
    
    pop rcx        ; recupera o número de iterações do label forcx
    dec rcx         ; decrementa
    cmp rcx,0
    jnz forcx
    ;nova linha    
    _printf eol,1
 
     _exit 0
		
