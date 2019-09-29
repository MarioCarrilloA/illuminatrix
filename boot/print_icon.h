.altmacro

.macro PRINT_ICON
	//-------------------- PRINT A PIXEL ------------------------
	mov $0x0013, %ax
	int $0x10
	mov $0x0C2E, %ax
	mov $0x01, %bh
	mov $0x0001, %cx
	mov $0x0001, %dx
	int $0x10
	//------------------------------------------------------------
.endm
