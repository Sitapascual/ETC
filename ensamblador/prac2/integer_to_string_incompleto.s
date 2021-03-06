        .data
buffer:	.space 256
str000:	.asciiz	"Introduzca un número (n) en base 10: "
str001:	.asciiz	": "
str002:	.asciiz	"n en base "
str003:	.asciiz	"\n"
        
        .text
# mueve la línea siguiente justo antes de la versión que desees probar

integer_to_string_v0:			# ($a0, $a1, $a2) = (n, base, buf)
        move    $t0, $a2		# char *p = buff
	# for (int i = n; i > 0; i = i / base) {
        move	$t1, $a0		# int i = n
B0_3:   blez	$t1, B0_7		# si i <= 0 salta el bucle
	div	$t1, $a1		# i / base
	mflo	$t1			# i = i / base, el contenido de lo a t1
	mfhi	$t2			# d = i % base
	addiu	$t2, $t2, '0'		# d + '0'
	sb	$t2, 0($t0)		# *p = $t2 
	addiu	$t0, $t0, 1		# ++p
	j	B0_3			# sigue el bucle
        # }
B0_7:	sb	$zero, 0($t0)		# *p = '\0'
B0_10:	jr	$ra


integer_to_string_v1:           	# ($a0, $a1, $a2) = (n, base, buf)
	 move    $t0, $a2		# char *p = buff
	# for (int i = n; i > 0; i = i / base) {
        move	$t1, $a0		# int i = n
B1_3:   blez	$t1, B1_7		# si i <= 0 salta el bucle
	div	$t1, $a1		# i / base
	mflo	$t1			# i = i / base, el contenido de lo a t1
	mfhi	$t2			# d = i % base
	addiu	$t2, $t2, '0'		# d + '0'
	sb	$t2, 0($t0)		# *p = $t2 
	addiu	$t0, $t0, 1		# ++p
	j	B1_3			# sigue el bucle
        # }
B1_7:	sb	$zero, 0($t0)		# *p = '\0'
	#A�adido en clase
	addi	$t0, $t0, -1		
for:	bge	$a2, $t0, fin_for
	lb	$t3, 0($a2)	#leer
	lb	$t4, 0($t0)
	sb	$t4, 0($a2)	#escribir
	sb	$t3, 0($t0)
	addi	$a2, $a2, 1
	addi	$t0, $t0, -1
	j	for
fin_for:


B1_10:	jr	$ra


integer_to_string_v2:           	# ($a0, $a1, $a2) = (n, base, buf)
	move    $t0, $a2		# char *p = buff
	# for (int i = n; i > 0; i = i / base) {
	bltz	$a0, convert		#Comprobar que a0 es menor que 0
					#Si es mayor que cero continuamos
	move	$t1, $a0		#Copio el valor de $a0 en $t0
	j	B2_3			#Si es mayor que cero vamos a B2_3
	
convert:abs	$t1, $a0		#Valor absoluto a t1 ya que es menor que 1
B2_3:   blez	$t1, B2_7		# si i <= 0 salta el bucle
	div	$t1, $a1		# i / base
	mflo	$t1			# i = i / base, el contenido de lo a t1
	mfhi	$t2			# d = i % base
	addiu	$t2, $t2, '0'		# d + '0'
	sb	$t2, 0($t0)		# *p = $t2 
	addiu	$t0, $t0, 1		# ++p
	j	B2_3			# sigue el bucle
        # }
B2_7:   bgez	$a0, fin_if		#Si a0 es mayor o igual que cero entonces vamos al fin_if
	li	$t3, '-'		#Si es menor que cero entonces le a�adimos el '-'
	sb	$t3, 0($t0)		#Guardamos el $t3 en la posicion 0($t0)
	addi	$t0, $t0, 1
fin_if:	sb	$zero, 0($t0)		# *p = '\0'
	#A�adido en clase
	addi	$t0, $t0, -1		
for2:	bge	$a2, $t0, fin_for2
	lb	$t3, 0($a2)	#leer
	lb	$t4, 0($t0)
	sb	$t4, 0($a2)	#escribir
	sb	$t3, 0($t0)
	addi	$a2, $a2, 1
	addi	$t0, $t0, -1
	j	for2
fin_for2:


B2_10:	jr	$ra

integer_to_string:
integer_to_string_v3:
	move    $t0, $a2		# char *p = buff
	# for (int i = n; i > 0; i = i / base) {
	beqz	$a0, cero		#Comprobar que a0 es igual a 0
	bltz	$a0, convert3		#Comprobar que a0 es menor que 0
					#Si es mayor que cero continuamos
	move	$t1, $a0		#Copio el valor de $a0 en $t0
	j	B3_3			#Si es mayor que cero vamos a B2_3
	
convert3:abs	$t1, $a0		#Valor absoluto a t1 ya que es menor que 1
B3_3:   blez	$t1, B3_7		# si i <= 0 salta el bucle
	div	$t1, $a1		# i / base
	mflo	$t1			# i = i / base, el contenido de lo a t1
	mfhi	$t2			# d = i % base
	addiu	$t2, $t2, '0'		# d + '0'
	sb	$t2, 0($t0)		# *p = $t2 
	addiu	$t0, $t0, 1		# ++p
	j	B3_3			# sigue el bucle
        # }

B3_7:   bgez	$a0, fin_if3		#Si a0 es mayor o igual que cero entonces vamos al fin_if
	li	$t3, '-'		#Si es menor que cero entonces le a�adimos el '-'
	sb	$t3, 0($t0)		#Guardamos el $t3 en la posicion 0($t0)
	addi	$t0, $t0, 1
fin_if3:sb	$zero, 0($t0)		# *p = '\0'

	#A�adido en clase
	addi	$t0, $t0, -1		
for3:	bge	$a2, $t0, fin_for3
	lb	$t3, 0($a2)	#leer
	lb	$t4, 0($t0)
	sb	$t4, 0($a2)	#escribir
	sb	$t3, 0($t0)
	addi	$a2, $a2, 1
	addi	$t0, $t0, -1
	j	for3
cero:	
li	$t3, '0'
sb	$t3, 0($t0)
addi	$t0, $t0, 1
sb	$zero, 0($t0)	
fin_for3:


B3_10:	jr	$ra

integer_to_string_v4:			# ($a0, $a1, $a2) = (n, base, buf)
	# TODO
        break
        jr	$ra

# Imprime el número recibido en base 10 seguido de un salto de linea
test1:					# $a0 = n
	addiu	$sp, $sp, -4
	sw	$ra, 0($sp)
	li	$a1, 10
	la	$a2, buffer
	jal	integer_to_string	# integer_to_string(n, 10, buffer); 
	la	$a0, buffer
	jal	print_string		# print_string(buffer); 
	la	$a0, str003
	jal	print_string		# print_string("\n"); 
	lw	$ra, 0($sp)
	addiu	$sp, $sp, 4
	jr	$ra

# Imprime el número recibido en todas las bases entre 2 y 36
test2:					# $a0 = n
	addiu	$sp, $sp, -12
	sw	$ra, 8($sp)
	sw	$s1, 4($sp)
	sw	$s0, 0($sp)
	move	$s0, $a0		# n
        # for (int b = 2; b <= 36; ++b) { 
	li	$s1, 2			# b = 2
B6_1:	la	$a0, str002
	jal	print_string		# print_string("n en base ")
	move	$a0, $s1
	li	$a1, 10
	la	$a2, buffer
	jal	integer_to_string	# integer_to_string(b, 10, buffer)
	la	$a0, buffer
	jal	print_string		# print_string(buffer)
	la	$a0, str001
	jal	print_string		# print_string(": "); 
	move	$a0, $s0
	move	$a1, $s1
	la	$a2, buffer
	jal	integer_to_string	# integer_to_string(n, b, buffer); 
	la	$a0, buffer
	jal	print_string		# print_string(buffer)
	la	$a0, str003
	jal	print_string		# print_string("\n")
	addiu	$s1, $s1, 1		# ++b
        li	$t0, 36
	ble	$s1, $t0, B6_1		# sigue el bucle si b <= 36
	# } 
	lw	$s0, 0($sp)
	lw	$s1, 4($sp)
	lw	$ra, 8($sp)
	addiu	$sp, $sp, 12
	jr	$ra

	.globl	main
main:
	#Prologo (Pila)
	addiu	$sp, $sp, -8
	sw	$ra, 4($sp)
	sw	$s0, 0($sp)
	
	#Cuerpo
	la	$a0, str000
	jal	print_string		# print_string("Introduzca un número (n) en base 10: ")
	jal	read_integer
	move	$s0, $v0		# int n = read_integer(), guardamos lo leido e s0
	move	$a0, $s0		#Guardamos lo leido en a0
	jal	test1			# test1(n)
	move	$a0, $s0
	jal	test2			# test2(n), llamamos a test2 con el valor que hemos leido
	li	$a0, 0
	jal	mips_exit		# mips_exit(0)
	li	$v0, 0
	
	#Desapilar
	lw	$s0, 0($sp)
	lw	$ra, 4($sp)
	addiu	$sp, $sp, 8
	jr	$ra

read_integer:
	li	$v0, 5
	syscall	
	jr	$ra

print_string:
	li	$v0, 4
	syscall	
	jr	$ra

mips_exit:
	li	$v0, 17
	syscall	
	jr	$ra
