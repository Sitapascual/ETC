        .data	#Zona de datos
        #Variables globales
msg:    .asciiz "El resultado es "      # Cadena para imprimir, le a馻de el \0, con ascii no tiene el fin de cadena
var_a:  .word   17                      # Variable inicializada a 17, de 4 bytes
var_b:  .word   0x17                    # Variable inicializada a 23, definida en hexadecimal
msg1: 	.asciiz	"Introduce un numero"

        .text	#Zona de codigo
# Procedimiento principal
main:   
	#Prologo de la funcion
        addi    $sp, $sp, -4    # Hace espacio en la pila
        sw      $ra, 0($sp)     # Almacena $ra en la pila
        
        #Cuerpo de la funcion
        #lw      $t0, var_a      # Carga var_a en $t0, leer de memoria el contenido de la memoria, hemos leido 17 y lo hemos $t0
        #lw      $t1, var_b      # Carga var_b en $t1, $t1 tiene el valor 0x
        jal	leer_numero
        move	$s0, $v0
        jal	leer_numero
        move	$s1, $v0
        add     $a0, $s0, $s1   # Suma,  resultado en $a0 para print_resultado
        jal     print_resultado # Llama a print_resultado
        li      $v0, 10         # C贸digo de la llamada al sistema "exit" en $v0
        syscall                 # Termina el programa
        
        #Epilogo del programa
        lw      $ra, 0($sp)     # Recupera el valor de $ra de la pila
        addi    $sp, $sp, 4     # Devuelve el espacio de pila usado
        jr      $ra
            
# Procedimiento para imprimir un mensaje con el resultado. Imprime la
# cadena msg seguida del valor que se le pasa como primer argumento (en $a0)
print_resultado:
        move    $t0, $a0        # Guarda en $t0 el valor a imprimir
        la      $a0, msg        # Pone en $a0 la direcci贸n de la cadena
        li      $v0, 4          # C贸digo syscall para imprimir una cadena
        syscall                 # Imprime la cadena
        move    $a0, $t0        # Pone en $a0 el entero a imprimir
        li      $v0, 1          # C贸digo syscall para imprimir un entero
        syscall                 # Imprime el entero
        jr      $ra             # Vuelve al procedimiento invocador
        
#Ejercicio2
#Modificar el programa para al usuario que numeros sumar
leer_numero:
	la	$a0, msg1	#Introducimos en a0 la cadena msg
	li	$v0, 4		
	syscall
	li	$v0, 5
	syscall
	jr $ra			#Fin de la funcion
