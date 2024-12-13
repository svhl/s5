; familiarization of masm

.model small
.data
	a db "hello$"
.code
	mov ax, @data
	mov ds, ax
	mov dx, offset a
	mov ah, 09h
	int 21h
	mov ah, 4ch
	int 21h
end
