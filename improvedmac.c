
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 256

static int stack[STACK_SIZE];

typedef enum
{
    HLT,
    PSH,
    POP,
    ADD,
    MUL,
    DIV,
    SUB,
    SLT,
    MOV,
    SET,
    LOG,
    IF,
    IFN,
    GLD,
    GPT,
    NOP
} Instructions;

typedef enum
{
    A,
    B,
    C,
    D,
    E,
    F,
    I,
    J,
    EX,
    EXA,
    IP,
    SP,
    REGISTER_SIZE
} Registers;

static int registers[REGISTER_SIZE];

int *instructions;

int instruction_count = 0;

int instruction_space = 4;

static bool running = true;

bool is_jmp = false;

#define SP (registers[SP])
#define IP (registers[IP])

#define FETCH (instructions[IP])

void print_stack()
{
    for (int i = 0; i < SP; i++)
    {
        printf("0x%04d", stack[i]);
        if ((i + 1) % 4 == 0)
        {
            printf("\n");
        }
    }
}
