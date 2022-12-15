
section .text
global roomInfo



roomInfo:
    call getDiscription
    ret



getDiscription:
    cmp QWORD[rsi], 0   ; Checks if we are in First room
    je FirstRoomLogic
    cmp QWORD[rsi], 1
    je SecondRoomLogic  ; Checks if we are in the second room
    ret


FirstRoomLogic:             
    lea rdx, [FirstRoom]
    cmp rdi, 2              
    je FirstRoomMoveWest
    
    mov rax, QWORD[rdx+rdi*8]   
    ret 

    FirstRoomMoveWest:
        add QWORD[rsi], 1
        mov rdi, 0          ;Sets rdi to 0, so weo point to the Discription
        jmp getDiscription

SecondRoomLogic:            ; Logic for the second Room
    lea rdx, [SecondRoom]   ; Loads the array of SecondRoom into rdx
    cmp rdi, 4              ; Checks for moveable direction
    je GoBack               ; If we can move East in this case jump
    
    mov rax, QWORD[rdx+rdi*8]; Move rax to the string pointer
    ret

    GoBack:
        add QWORD[rsi], -1  ; Goes Back to First room
        mov rdi, 0          ; Sets rdi to 0, so we point to the Discription
        jmp getDiscription  ; Gets 

SecondRoom:
    dq Discription1, North0, West1, South0, East1,


    
Discription1: db "Second Room there is no exit from this Room, other than the way you came, and there is nothing of interest",0    
West1: db "There is no passage way to the North",0
East1: db "You can travel through the west passage way"


FirstRoom:
    dq Discription0, North0, West0, South0, East0
    ;  +0           +8     +16   +24        +32

Discription0: db "You are back in the Starting Room",0
North0: db "There is no passage way to the North",0
West0: db "You can travel through the west passage way",0
South0: db "There is no passage way to the South",0
East0: db "There is no passage way to the East",0



